#include <stdio.h>
#include <stdlib.h>

#include "strings.h"

int check_ip(char* s)
{
    int i = 0;
    short score_field_ip = 0;
    while (s[i] != ':')
    {
        if (my_isdigit(s[i]) >= 0)
        {
            if (score_field_ip > 4)
                return -1;
            int k;
            if ((k = my_atoi(s + i)) <= 255 && k >= 0)
            {
                score_field_ip++;
                while (my_isdigit(s[i]) >= 0)
                    i++;
            } else
                return -2;
        } else if (s[i] == '.')
            i++;
        else
            return -3;
    }
    if (score_field_ip < 4)
        return -5;

    return i;
}

int check_win_path(char* s)
{
    int i = 0;
    if (my_isalpha(s[i]) == 0 || s[i] == '/')
    {
        i++;
        if (my_isalpha(s[i]) == 0 || s[i] == ':')
            i++;
    }

    while (s[i] != '\0')
    {
        if (s[i] == '/' || my_isalpha(s[i]) == 0 || my_isdigit(s[i]) >= 0
            || s[i] == ':')
            i++;
        else
            return -1;
    }
    return 0;
}

char* for_copy_str(int len)
{
    char* temp = malloc(sizeof(char) * (len + 1));
    if (temp == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        temp[i] = ' ';
    temp[len] = '\0';
    return temp;
}

int check_dom(char* s, char simbol) // mysrv.com:/Windows/
{
    int i = 0, sa = 0, check_dot = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i] != ':')
    {
        if (s[i] == simbol)
        {
            sa = i;
            check_dot++;
        }
        if (check_dot > 4)
            return -3;
        i++;
    }
    int len;

    if ((len = i - sa) > 4)
        return -2;

    char* suff = for_copy_str(len - 1);
    scpy(s + i - len + 1, suff);
    if (domen(suff) != 0)
        return -1;

    check_win_path(s + i);
    return 0;
}

int check_ip_test(char* s) // 192.168.1.1:/test
{
    unsigned i = 0;
    int k;

    if ((k = check_ip(s + i)) < 0)
        return -1;
    i += k;
    if ((k = check_win_path(s + i)) != 0)
        return -2;
    i++;
    if (not_lin_simbols(s) < 0)
        return -4;
    if (i > 260)
        return -3;
    return 0;
}