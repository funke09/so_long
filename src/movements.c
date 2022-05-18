#include "../so_long.h"

int	move_left(t_long *var)
{
	var->map[var->py][var->px] = '0';
	var->px -= 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	// var->img.spt_path = "./img/sprite2.xpm";
	return (0);
}

int	move_right(t_long *var)
{
	var->map[var->py][var->px] = '0';
	var->px += 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	// var->img.spt_path = "./img/sprite1.xpm";
	return (0);
}

int	move_down(t_long *var)
{
	var->map[var->py][var->px] = '0';
	var->py += 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	return (0);
}

int	move_up(t_long *var)
{
	var->map[var->py][var->px] = '0';
	var->py -= 1;
	var->map[var->py][var->px] = 'P';
	var->move++;
	return (0);
}

int	movements(int key, t_long *var)
{
	dprintf(STDERR_FILENO, "px=%d, py=%d\n", var->px, var->py);
	if ((key == A_KEY) // for exit
		&& (var->map[var->py][var->px - 1] == 'E'))
		check_collect(var);
	else if ((key == A_KEY)
		&& (var->map[var->py][var->px - 1] != '1'))
		move_left(var);
	if ((key == D_KEY)
		&& (var->map[var->py][var->px + 1] == 'E'))
		check_collect(var);
	else if ((key == D_KEY)
		&& (var->map[var->py][var->px + 1] != '1'))
		move_right(var);
	if ((key == S_KEY)
		&& (var->map[var->py + 1][var->px] == 'E'))
		check_collect(var);
	else if ((key == S_KEY)
		&& (var->map[var->py + 1][var->px] != '1'))
		move_down(var);
	if ((key == W_KEY)
		&& (var->map[var->py - 1][var->px] == 'E'))
		check_collect(var);
	else if ((key == W_KEY)
		&& (var->map[var->py - 1][var->px] != '1'))
		move_up(var);
	return (0);
}
