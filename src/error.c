#include "../so_long.h"

void showerror(t_long *so_long, char *message)
{
    ft_putendl_fd(message, STDERR_FILENO);
    //free t_long struct
    exit(1);
}