# include "mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_cub
{
    void *mlx;
    void *win;
} t_cub;

size_t	ft_strlen(const char *s);