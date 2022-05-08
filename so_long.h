
#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

#include "libft/libft.h"
#define POS 0
#define COLL 1
#define EXT 2

int g_x;
int g_y;
int g_symbol[3];

typedef struct s_long
{
   char **map;
   int x;
   int y;
   int px;
   int py;
}               t_long;

void     showerror(t_long *so_long, char *message);
int     read_check(char *filename, t_long *so_long);
void     print_map(char **map);
int      full_wall(char *line);
int      check_line(char *line);
int     count_lines(char *filename);
int      is_valid(char c);

#endif