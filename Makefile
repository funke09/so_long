

LIBFT= ./libft/
LIBFT_A= ./libft/libft.a
NAME=so_long
SRC=src/main.c\
	src/error.c\
	src/read_check.c\
	src/tools.c\

INCLUDE= -I . -I $(LIBFT)

OBJS=$(SRC:.c=.o)
CFLAGS= -Wall -Wextra -Werror
cc=gcc
INC= -lmlx -framework OpenGL -framework AppKit
RM= rm -f

	
all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT)
	$(cc) $(CFLAGS) $^ $(LIBFT_A) $(INC) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C  $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all