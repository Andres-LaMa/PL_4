#include "Gmain.h"
#include "strings.h"

#define RESET "\033[0m"  /* White */
#define RED "\033[31m"   /* Red */
#define GREEN "\x1B[32m" /* Green*/

int program() ///   198.168.1.1:/test+mysrv.com:/Windows/+500.222.1.1:/test+my.cm:/m/n/k.txt
{
    char delim, *string = input(&delim);
    char** pred_process = check(string, delim);
    pred_process = process(pred_process);
    output(pred_process);
    return 0;
}

char* input(char* delim)
{
    printf("path: ");
    size_t n = 0;
    char* string = NULL;
    n = getline(&string, &n, stdin);

    printf("delim: ");
    scanf("%c", delim);

    return string;
}

char** check(char* s_n, char sim)
{
    char** result = malloc(sizeof(char*) * 1);
    char** ips = malloc(sizeof(char*) * 1);
    char** paths = malloc(sizeof(char*) * 1);
    int score_ip = 0;
    int score_path = 0;
    char* s_c = s_n;
    int i = 0;
    while (i < 4)
    {
        s_c = s_n;
        s_n = stok(s_c, sim);
        if (my_isdigit(s_c[0]) <= 9 && my_isdigit(s_c[0]) >= 0)
            if (check_ip_test(s_c) != 0)
                ;
            else
            {
                ips = realloc(ips, sizeof(char*) * (score_ip + 1));
                ips[score_ip] = malloc(slen(s_c) + 1);
                my_strcat(ips[score_ip], s_c, slen(ips[score_ip]));
                my_strcat(ips[score_ip], "+", slen(ips[score_ip]));
                score_ip++;
            }
        else if (my_isalpha(s_c[i]) == 0 || s_c[i] == '/')
        {
            if (check_dom(s_c, '.') != 0)
                ;
            else
            {
                paths = realloc(paths, sizeof(char*) * (score_path + 1));
                paths[score_path] = malloc(slen(s_c) + 1);
                my_strcat(paths[score_path], s_c, slen(paths[score_path]));
                score_path++;
            }
        }
        i++;
    }
    int k = 1;
    for (int i = 0; i < score_ip; i++)
    {
        for (int j = 0; j < score_path; j++)
        {
            result = realloc(result, sizeof(char*) * k);
            result[k - 1]
                    = malloc(sizeof(char) * (slen(ips[i]) + slen(paths[j])));
            my_strcat(result[k - 1], ips[i], slen(result[k - 1]));
            my_strcat(result[k - 1], paths[j], slen(result[k - 1]));
            k++;
        }
    }

    for (int i = 0; ips[i] != NULL; i++)
        free(ips[i]);
    free(ips);
    for (int i = 0; paths[i] != NULL; i++)
        free(paths[i]);
    free(paths);

    return result;
}

char** process(char** s)
{
    char** result = malloc(sizeof(char*) * 1);
    int i = 0;
    for (; s[i] != NULL; i++)
    {
        result = realloc(result, sizeof(char*) * (i + 1));
        result[i] = malloc(slen("\\\\") + slen(s[i]) + 1);
        my_strcat(result[i], "\\\\", 0);
        my_strcat(result[i], s[i], slen(result[i]));
        my_replace(result[i], '/', '\\');
    }
    if (i == 0)
        result = NULL;

    return result;
}

void output(char** s)
{
    if (s == NULL)
        printf(RED "new paths: no paths\n" RESET);
    else
        for (int i = 0; s[i] != NULL; i++)
            printf(GREEN "new paths: %s\n" RESET, s[i]);
}
