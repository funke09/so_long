#include "../so_long.h"

void showerror(t_long *so_long, char *message)
{
    (void)so_long;
    ft_putendl_fd(message, STDERR_FILENO);
    //free(so_long);
    exit(1);
}