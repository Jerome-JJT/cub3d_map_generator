#include <cub3d.h>

void	ft_time(void)
{
	size_t			millis;
	struct timeval	time;

	gettimeofday(&time, NULL);
	millis = time.tv_sec * 10000000 + time.tv_usec;
	printf("t %zu\n", millis);
	printf("tu %zu %d\n", time.tv_sec, time.tv_usec);
}

long	map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

int	ft_color(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	int	res;

	res = a;
	res = (res << 8) + r;
	res = (res << 8) + g;
	res = (res << 8) + b;
	return (res);
}

char	ft_get_case(t_vars *vars, int x, int y)
{
	if (y < 0)
		return ('\e');
	if (vars->map.raw[y] == NULL)
		return ('\e');
	if (x < 0)
		return ('\e');
	if (x > (int)ft_strlen(vars->map.raw[y]))
		return ('\e');
	return (vars->map.raw[y][x]);
}
