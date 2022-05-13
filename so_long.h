
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
int g_fd;


typedef struct	s_data {
	void	   *img;
	char	   *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_long
{
   char **map;
   int x;
   int y;
   int px;
   int py;
	void	*wall_img;
	void	*door_img;
	void	*coins_img;
	void	*player_img;
   void  *empty;
   void  *enemy;
   void   *mlx_ptr;
   void   *win_ptr;
   void   *image;
}               t_long;



void     showerror(t_long *so_long, char *message);
int     read_check(char *filename, t_long *so_long);
void     print_map(char **map);
int      full_wall(char *line);
int      check_line(char *line);
int     count_lines(char *filename);
int      is_valid(char c);
int      convert_color(int color, int endian);
int      deal_key(int key, void *arg);
void    get_image(t_long *so_long);
void    check_image(char **map, t_long *so_long);
void    pos_player(t_long *so_long, char **map);
void    my_mlx(t_long *so_long);
#endif