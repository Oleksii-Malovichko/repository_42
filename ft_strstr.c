#include <stdio.h>

char    *ft_strstr(char *str, char *to_find)
{
    int index_str;
    int index_find;

    index_find = 0;
    index_str = 0;
    if (*to_find == '\0')
        return (str);
    while (str[index_str] != '\0')
    {
        while (to_find[index_find] != '\0' && str[index_str + index_find] != '\0' &&
               to_find[index_find] == str[index_str + index_find])
        {
            index_find++;
        }
        if (to_find[index_find] == '\0')
        {
            return (str+index_str);
        }
        index_str++;
    }
    return (NULL);
}

int main(void)
{
    char str[] = "Hello, world"; 
    char to_find[] = "world";

    char *result = ft_strstr(str, to_find);
    if(result != NULL)
    {
        printf("Найдено совпадение!\n");
    }
    else
    {
        printf("Совпадение не найдено\n");
    }
}