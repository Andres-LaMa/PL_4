#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH 260

unsigned long int slen(char* string)
{
    if (string == NULL)
        return 0;

    unsigned long int count = 0;
    while (string[count] != '\n' && string[count] != '\0')
    {
        count++;
    }
    return count;
}

short my_isalpha(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return 0;
    return -1;
}

short scmp(char* str_1, char* str_2)
{
    short i = 0;
    while ((str_1[i] != '\n' && str_1[i] != '\0')
           || (str_2[i] != '\n' && str_2[i] != '\0')) // copy - cop
    {
        if (str_1[i] != str_2[i])
            return -1;
        i++;
    }
    return 0;
}

void scpy(char* str_1, char* copy)
{
    if (str_1 == NULL || copy == NULL)
        return;
    short len = slen(copy);

    for (short i = 0; i <= len; i++)
        copy[i] = str_1[i];
    copy[len] = '\0';
}

char* stok(char* string, char simbol)
{
    if (string == NULL)
        return NULL;

    unsigned position = 0;
    while (position < slen(string))
    {
        if (string[position] == simbol)
        {
            string[position] = '\0';
            return &string[position + 1];
        }
        position++;
    }
    return &string[position];
}

int my_isdigit(char simbol)
{
    int int_sim = (int)simbol - 48;
    if (int_sim >= 0 && int_sim <= 9)
        return int_sim;
    else
        return -1;
}

int my_atoi(char* string)
{
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (my_isdigit(string[i]) != -1)
            result = result * 10 + my_isdigit(string[i]);
        else
            return result;
    }
    return result;
}

int sspn(char* str1, char* str2)
{
    if (str1 == NULL || str2 == NULL)
        return -1;
    int size1 = slen(str1), size2 = slen(str2);
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (str1[i] == str2[j])
                return i;
        }
    }
    return size1;
}

int check_LEN(char* str, int* num)
{
    int i = 0;
    if (str == NULL)
        return -4;
    while (str[i] != '\0')
    {
        if (i == MAX_PATH)
            return -1;
        if (str[i] == ':' || str[i + 1] != '/')
            return -2;
        if (sspn(str, str) == -1)
            return -3;

        *num = ++i;
    }
    return 0;
}

int not_win_simbols(char* s)
{
    unsigned i = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i])
    {
        if (s[i] == '/' || !my_isalpha(s[i]))
            return -1;
        i++;
    }
    return 0;
}

int not_lin_simbols(char* s)
{
    unsigned i = 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        if (s[i] == '"' || s[i] == '\'' || s[i] == '\\')
            return -1;
        i++;
    }
    return 0;
}

int domen(char* s)
{
    if ((scmp(s, "com\0") == 0 || scmp(s, "ru\0") == 0
         || scmp(s, "org\0") == 0))
        return 0;
    else
        return -1;
}

void swap_str(char* str_1, char* str_2)
{
    char* temp = str_1;
    str_1 = str_2;
    str_2 = temp;
}

void my_strcat(char* result, char* add, int position)
{
    int i = 0;
    while (add[i] != '\n' && add[i] != '\0')
    {
        result[position + i] = add[i];
        i++;
    }
    result[position + i] = '\0';
}

void my_replace(char* s, char r_sim, char p_sim)
{
    int i = 0;
    while (s[i] != '\n' && s[i] != '\0')
    {
        if (s[i] == r_sim)
            s[i] = p_sim;
        i++;
    }
}
