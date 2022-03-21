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

//Total max size of map
# define GEN_WIDTH 80
# define GEN_HEIGHT 60

//Percentage of change to expend in a direction /100
# define GEN_PROPAG 25

//Percentage of chance to continue to expend in a direction after going in this direction /100
# define GEN_CONTINUE 70

//Minimum fraction of map cases who need to be filled for a map to be correct /1
# define GEN_TRESH 0.08

//Obligate the generation to cross at least 3/4 borders who are x percent inside the map /1
# define GEN_BORDERS 0.2

//GEN_BORDERS example
//11111111
//1------1
//1|1111|1
//1|1111|1
//1|1111|1
//00000000
//1|1101|1
//1---0--1
//11110111

//-----------------
//math.c

char	ft_get_case(t_vars *vars, int x, int y);

//-----------------
//tabs.c

void	ft_free_2d(char **tab);

#endif //CUB3D_H
