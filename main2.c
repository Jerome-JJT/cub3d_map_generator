#include <cub3d.h>

int	ft_gen_count(t_vars *vars)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 0;
	while (i < GEN_HEIGHT)
	{
		j = 0;
		while (j < GEN_WIDTH)
		{
			if (vars->map.raw[i][j] == '0')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

void	ft_gen_expend(t_vars *vars, int x, int y, int dir)
{
	if (x <= 0 || x >= GEN_WIDTH - 2 || y <= 0 || y >= GEN_HEIGHT - 1
		|| vars->map.raw[y][x] != '1')
		return ;
	if (ft_gen_count(vars) > (GEN_WIDTH * GEN_HEIGHT) * GEN_TRESH * 3
		&& rand() % 3 == 0)
		return ;
	vars->map.raw[y][x] = '0';
	if (rand() % 100 < GEN_CONTINUE && dir == 1)
		ft_gen_expend(vars, x, y - 1, 1);
	if (rand() % 100 < GEN_CONTINUE && dir == 2)
		ft_gen_expend(vars, x - 1, y, 2);
	if (rand() % 100 < GEN_CONTINUE && dir == 3)
		ft_gen_expend(vars, x + 1, y, 3);
	if (rand() % 100 < GEN_CONTINUE && dir == 4)
		ft_gen_expend(vars, x, y + 1, 4);
	if (rand() % 100 < GEN_PROPAG)
		ft_gen_expend(vars, x, y - 1, 1);
	if (rand() % 100 < GEN_PROPAG)
		ft_gen_expend(vars, x - 1, y, 2);
	if (rand() % 100 < GEN_PROPAG)
		ft_gen_expend(vars, x + 1, y, 3);
	if (rand() % 100 < GEN_PROPAG)
		ft_gen_expend(vars, x, y + 1, 4);
}

int	ft_gen_check2(t_vars *vars)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = GEN_WIDTH * GEN_BORDERS;
	j = GEN_HEIGHT * GEN_BORDERS;
	while (i < GEN_WIDTH * (1 - GEN_BORDERS))
	{
		if (vars->map.raw[j][i] == '0' && nb <= 0)
			nb++;
		i++;
	}
	i = GEN_WIDTH * GEN_BORDERS;
	j = GEN_HEIGHT * (1 - GEN_BORDERS);
	while (i < GEN_WIDTH * (1 - GEN_BORDERS))
	{
		if (vars->map.raw[j][i] == '0' && nb <= 1)
			nb++;
		i++;
	}
	return (nb);
}

int	ft_gen_check(t_vars *vars)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = GEN_HEIGHT * GEN_BORDERS;
	j = GEN_WIDTH * GEN_BORDERS;
	while (i < GEN_HEIGHT * (1 - GEN_BORDERS))
	{
		if (vars->map.raw[i][j] == '0' && nb <= 0)
			nb++;
		i++;
	}
	i = GEN_HEIGHT * GEN_BORDERS;
	j = GEN_WIDTH * (1 - GEN_BORDERS);
	while (i < GEN_HEIGHT * (1 - GEN_BORDERS))
	{
		if (vars->map.raw[i][j] == '0' && nb <= 1)
			nb++;
		i++;
	}
	return (nb + ft_gen_check2(vars) >= 3);
}
