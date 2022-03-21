#include <cub3d.h>

int	count_map(t_vars *vars);
void	genmap(t_vars *vars, int x, int y, int dir);
int	check_map2(t_vars *vars);
int	check_map(t_vars *vars);

void	void_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
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
	while (i < HEIGHT)
	{
		printf("%s\n", vars->map.raw[i]);
		i++;
	}
}

void	create_map(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	vars->map.raw = malloc((HEIGHT + 1) * sizeof(char *));
	vars->map.raw[HEIGHT] = NULL;
	i = 0;
	while (i < HEIGHT)
	{
		vars->map.raw[i] = malloc((WIDTH + 1) * sizeof(char));
		ft_memset(vars->map.raw[i], '1', WIDTH * sizeof(char));
		vars->map.raw[i][WIDTH] = '\0';
		i++;
	}
	x = (rand() % (WIDTH - 2)) + 1;
	y = (rand() % (HEIGHT - 2)) + 1;
	genmap(vars, x, y, 0);
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
		create_map(&vars);
		if (count_map(&vars) > (HEIGHT * WIDTH) * TRESH)
		{
			if (check_map(&vars))
				break ;
		}
		ft_free_2d(vars.map.raw);
		inf++;
	}
	if (inf == 100)
		exit(printf("Really bad luck\n"));
	void_map(&vars);
	print_map(&vars);
	exit(0);
}
