#include "Gmain.h"
#include "strings.h"

#define RESET "\033[0m"  /* White */
#define RED "\033[31m"   /* Red */
#define GREEN "\x1B[32m" /* Green*/

int program() ///   23.18.1.1:/test+mysrv.com:/Windows/+192.222.1.1:/test+my.tr:/m/n/k.txt
{
    char delim, *string = input(&delim);
    char* pred_process = check(string, delim);
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

char* check(char* s_n, char sim)
{
    char* result = malloc(sizeof(char) * 1);

    char* s_c;
    int i = 0;
    int check = 0;
    while (i < 4)// (kol-vo '+') + 1 
    {
        s_c = s_n;
        s_n = stok(s_c, sim);
        
        if (my_isdigit(s_c[0]) <= 9 && my_isdigit(s_c[0]) >= 0)
            if (check_ip_test(s_c) != 0)
                ;
            else
            {
                if (check!=0)
                    my_strcat(result, "+", slen(result));
                result = realloc(result, sizeof(char) * (slen(s_c) + slen(result) + 1));
                my_strcat(result, "\\\\", slen(result));
                my_strcat(result, s_c, slen(result));
                check++;
            }
        else if (my_isalpha(s_c[i]) == 0 || s_c[i] == '/')
        {
            if (check_dom(s_c, '.') != 0)
                ;
            else
            {
                if (check!=0)
                    my_strcat(result, "+", slen(result));
                result = realloc(result, sizeof(char) * (slen(s_c) + slen(result) + 1));
                my_strcat(result, "\\\\", slen(result));
                my_strcat(result, s_c, slen(result));
                check++;
            }
        }
        i++;
    }
    if (check == 0)
        result = NULL;
    return result;
}

char* process(char* s)
{
    if (s == NULL)
        return NULL;
    my_replace(s, '/', '\\');
    return s;
}

void output(char* s)
{
    if (s == NULL)
        printf(RED "new paths: no paths\n" RESET);
    else
        printf(GREEN "new paths: %s\n" RESET, s);
}
