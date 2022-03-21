#include <cub3d.h>

int		ft_gen_count(t_vars *vars);
void	ft_gen_expend(t_vars *vars, int x, int y, int dir);
int		ft_gen_check2(t_vars *vars);
int		ft_gen_check(t_vars *vars);

void	ft_gen_add_spaces(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < GEN_HEIGHT)
	{
		j = 0;
		while (j < GEN_WIDTH)
		{
			if (ft_strchr("\e 1", ft_get_case(vars, j - 1, i)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j, i - 1)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j + 1, i)) != NULL
				&& ft_strchr("\e 1", ft_get_case(vars, j, i + 1)) != NULL)
				vars->map.raw[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	print_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < GEN_HEIGHT)
	{
		printf("%s\n", vars->map.raw[i]);
		i++;
	}
}

void	ft_gen_start(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	vars->map.raw = malloc((GEN_HEIGHT + 1) * sizeof(char *));
	vars->map.raw[GEN_HEIGHT] = NULL;
	i = 0;
	while (i < GEN_HEIGHT)
	{
		vars->map.raw[i] = malloc((GEN_WIDTH + 1) * sizeof(char));
		ft_memset(vars->map.raw[i], '1', GEN_WIDTH * sizeof(char));
		vars->map.raw[i][GEN_WIDTH] = '\0';
		i++;
	}
	x = (rand() % (GEN_WIDTH - 2)) + 1;
	y = (rand() % (GEN_HEIGHT - 2)) + 1;
	ft_gen_expend(vars, x, y, 0);
	vars->map.raw[y][x] = 'N';
}

int	main(void)
{
	t_vars	vars;
	int		inf;

	ft_bzero(&vars, sizeof(t_vars));
	srand(time(NULL));
	inf = 0;
	while (inf < 100)
	{
		ft_gen_start(&vars);
		if (ft_gen_count(&vars) > (GEN_HEIGHT * GEN_WIDTH) * GEN_TRESH)
		{
			if (ft_gen_check(&vars))
				break ;
		}
		ft_free_2d(vars.map.raw);
		inf++;
	}
	if (inf == 100)
		exit(printf("Really bad luck\n"));
	ft_gen_add_spaces(&vars);
	print_map(&vars);
	exit(0);
}
