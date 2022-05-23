# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 01:03:59 by zcherrad          #+#    #+#              #
#    Updated: 2022/05/21 01:04:07 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT= ./libft/
LIBFT_A= ./libft/libft.a
NAME=so_long
SRC=src/main.c\
	src/error.c\
	src/read_check.c\
	src/tools.c\
	src/mlx_m.c\
	src/mlx_image.c\
	src/movements.c\
	src/utils.c\

HEADER=so_long.h

INCLUDE= -I . -I $(LIBFT)

OBJS=$(SRC:.c=.o)
CFLAGS= -g -Wall -Wextra -Werror
cc=gcc
INC= -Lmlx -lmlx -framework OpenGL -framework AppKit #-L./mlx -I/usr/local/include/  -Lmlx -lmlx -framework OpenGL -framework AppKit
RM= rm -f

	
all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT)
	$(cc) $(CFLAGS) $^ $(LIBFT_A) $(INC) -o $(NAME)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C  $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all