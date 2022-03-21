#include <cub3d.h>

void	ft_free_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab != NULL && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
