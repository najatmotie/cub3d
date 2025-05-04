#include "../cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	r;

	sign = 1;
	i = 0;
	r = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * sign);
}
