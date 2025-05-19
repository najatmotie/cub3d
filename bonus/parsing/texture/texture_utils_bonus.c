#include "../../cub3d_bonus.h"

char *remove_newline(char *path)
{
    int i = 0;
    char *str;

    str = malloc(ft_strlen(path));
    while(path[i] != '\n')
    {
        str[i] = path[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
