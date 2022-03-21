#include <cub3d.h>

int	ft_concat_tab(char ***ptr, char *new)
{
	char	**newptr;
	int		count;
	int		i;

	count = 0;
	while ((*ptr) != NULL && (*ptr)[count] != NULL)
		count++;
	newptr = ft_calloc(count + 2, sizeof(char *));
	newptr[count + 1] = NULL;
	newptr[count] = new;
	i = 0;
	while (i < count)
	{
		newptr[i] = (*ptr)[i];
		i++;
	}
	if (*ptr != NULL)
		free(*ptr);
	*ptr = newptr;
	return (count + 1);
}

size_t	ft_tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab != NULL && tab[i] != NULL)
		i++;
	return (i);
}

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
