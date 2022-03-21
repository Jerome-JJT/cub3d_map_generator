#include <cub3d.h>

int	count_map(t_vars *vars)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (vars->map.raw[i][j] == '0')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

void	genmap(t_vars *vars, int x, int y, int dir)
{
	if (x <= 0 || x >= WIDTH - 2 || y <= 0 || y >= HEIGHT - 1
		|| vars->map.raw[y][x] != '1')
		return ;
	if (count_map(vars) > (WIDTH * HEIGHT) * TRESH * 3 && rand() % 3 == 0)
		return ;
	vars->map.raw[y][x] = '0';
	if (rand() % 100 < CONTI && dir == 1)
		genmap(vars, x, y - 1, 1);
	if (rand() % 100 < CONTI && dir == 2)
		genmap(vars, x - 1, y, 2);
	if (rand() % 100 < CONTI && dir == 3)
		genmap(vars, x + 1, y, 3);
	if (rand() % 100 < CONTI && dir == 4)
		genmap(vars, x, y + 1, 4);
	if (rand() % 100 < PROPAG)
		genmap(vars, x, y - 1, 1);
	if (rand() % 100 < PROPAG)
		genmap(vars, x - 1, y, 2);
	if (rand() % 100 < PROPAG)
		genmap(vars, x + 1, y, 3);
	if (rand() % 100 < PROPAG)
		genmap(vars, x, y + 1, 4);
}

int	check_map2(t_vars *vars)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = WIDTH * VERIF;
	j = HEIGHT * VERIF;
	while (i < WIDTH * (1 - VERIF))
	{
		if (vars->map.raw[j][i] == '0' && nb <= 0)
			nb++;
		i++;
	}
	i = WIDTH * VERIF;
	j = HEIGHT * (1 - VERIF);
	while (i < WIDTH * (1 - VERIF))
	{
		if (vars->map.raw[j][i] == '0' && nb <= 1)
			nb++;
		i++;
	}
	return (nb);
}

int	check_map(t_vars *vars)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = HEIGHT * VERIF;
	j = WIDTH * VERIF;
	while (i < HEIGHT * (1 - VERIF))
	{
		if (vars->map.raw[i][j] == '0' && nb <= 0)
			nb++;
		i++;
	}
	i = HEIGHT * VERIF;
	j = WIDTH * (1 - VERIF);
	while (i < HEIGHT * (1 - VERIF))
	{
		if (vars->map.raw[i][j] == '0' && nb <= 1)
			nb++;
		i++;
	}
	return (nb + check_map2(vars) >= 3);
}
