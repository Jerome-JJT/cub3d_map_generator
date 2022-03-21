#include <cub3d.h>

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
