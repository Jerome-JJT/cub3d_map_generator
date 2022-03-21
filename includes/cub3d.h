#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/time.h>

# include <mylibft.h>

# include <structs.h>

# define GEN_WIDTH 80
# define GEN_HEIGHT 60

# define GEN_PROPAG 25
# define GEN_CONTINUE 70
# define GEN_TRESH 0.08
# define GEN_BORDERS 0.2

//-----------------
//math.c

char	ft_get_case(t_vars *vars, int x, int y);

//-----------------
//tabs.c

void	ft_free_2d(char **tab);

#endif //CUB3D_H
