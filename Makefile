# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 01:03:59 by zcherrad          #+#    #+#              #
#    Updated: 2022/05/30 08:31:06 by zcherrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT= ./libft/
LIBFT_A= ./libft/libft.a
NAME=so_long
B_NAME=so_long_bonus
SRC=src/main.c\
	src/error.c\
	src/read_check.c\
	src/tools.c\
	src/mlx_m.c\
	src/mlx_image.c\
	src/movements.c\
	src/utils.c\

B_SRC=bonus/src/main_bonus.c\
	bonus/src/error_bonus.c\
	bonus/src/read_check_bonus.c\
	bonus/src/tools_bonus.c\
	bonus/src/mlx_m_bonus.c\
	bonus/src/mlx_image_bonus.c\
	bonus/src/enemy_bonus.c\
	bonus/src/enemy_move_bonus.c\
	bonus/src/movements_bonus.c\
	bonus/src/utils_bonus.c\

HEADER=so_long.h

INCLUDE= -I . -I $(LIBFT)

OBJS=$(SRC:.c=.o)
B_OBJS=$(B_SRC:.c=.o)
CFLAGS= -g -Wall -Wextra -Werror
cc=gcc
INC= -Lmlx -lmlx -framework OpenGL -framework AppKit #-L./mlx -I/usr/local/include/  -Lmlx -lmlx -framework OpenGL -framework AppKit
RM= rm -f

	
all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT)
	$(cc) $(CFLAGS) $^ $(LIBFT_A) $(INC) -o $(NAME)

%.o: %.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C  $(LIBFT)
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	$(RM) $(NAME) $(B_NAME)

re: fclean all

bonus: $(B_NAME)

$(B_NAME):$(B_OBJS)
	@make -C $(LIBFT)
	$(cc) $(CFLAGS) $^ $(LIBFT_A) $(INC) -o $(B_NAME)
%.o: %.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@