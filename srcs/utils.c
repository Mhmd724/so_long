
#include "../inc/so_long.h"

int ft_new_strchr(char *str, char *cmp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (cmp[j] == '\0' && str[i] == '\0')
        return (1);
    while (str[i])
    {
        while (cmp[j] == str[i + j] && cmp[j] && str[i + j])
            j++;
        if (str[i + j] == '\0' && cmp[j] == '\0')
            return (1);
        else
            j = 0;
        i++;
    }
    return (0);
}

void *ft_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (NULL);
}

int ft_error_int(char *str)
{
    write(2, str, ft_strlen(str));
    return (0);
}