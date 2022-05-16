
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
#define ENM 3
#define LEFT_KEY  123
#define RIGHT_KEY 124
#define UP_KEY 126
#define DOWN_KEY  125
#define A_KEY  0
#define S_KEY  1
#define D_KEY  2
#define W_KEY  13
#define ESC 53
# define X_EVENT_KEY_PRESS        2
# define X_EVENT_KEY_EXIT        17 // ESC / exit

 
int g_x;
int g_y;
int g_symbol[4];
int g_fd;


typedef struct	s_data {
	void	   *img;
	char	   *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_long
{
   t_vars mlx_ptr;
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
   void  *image;
   int   move;
}               t_long;



void     showerror(t_long *so_long, char *message);
int     read_check(char *filename, t_long *so_long);
void     print_map(char **map);
int      full_wall(char *line);
int      check_line(char *line);
int     count_lines(char *filename);
int      is_valid(char c);
int      convert_color(int color, int endian);
int 	deal_key(int key, t_long *so_long);
void    get_image(t_long *so_long);
void    check_image(char **map, t_long *so_long);
void    pos_player(t_long *so_long, char **map);
void    my_mlx(t_long *so_long);
int	ft_exit(t_long *so_long);
#endif