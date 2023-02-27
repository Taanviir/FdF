# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanas <tanas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 22:21:39 by tanas             #+#    #+#              #
#    Updated: 2023/02/27 19:05:06 by tanas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fdf

ifeq ($(shell uname -s), Darwin)
	MLX_DIR 	= mlx-mac/
	MINILIBX	= libmlx.a
	LIBRARY_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(shell uname -s), Linux)
	MLX_DIR 	= mlx-linux/
	MINILIBX	= libmlx_Linux.a
	LIBRARY_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
endif

C_FLAGS 		= -Wall -Wextra -Werror -O3 -g -fsanitize=address
INCLUDES 		= -Iincludes/ -Ilibft/includes -Imlx-macos/

SRCS_DIR 		= sources/
SRCS_LIST 		= main.c \
					key_hooks.c \
					line.c \
					image.c \
					map.c \
					draw.c \
					error.c \
					colours.c \
					projection.c \
					menu.c
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR 		= objects/
OBJS_LIST 		= $(SRCS_LIST:.c=.o)
OBJS 			= $(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADERS 		= includes/fdf.h \
					includes/keycodes.h \

LIBFT 			= libft/libft.a

# colours
GREEN 			= "\033[1;32m"
RED 			= "\033[1;3;31m"
BLUE 			= "\033[3;34m"
YELLOW 			= "\033[0;33m"
COLOUR_RESET 	= "\033[0m"

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
	@cc $(C_FLAGS) $(LIBRARY_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	@cc $(C_FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BLUE)"Compiling $<."$(COLOUR_RESET)

$(LIBFT) :
	@echo $(YELLOW)"Creating $(LIBFT)"$(COLOUR_RESET)
	@make -sC libft
	@echo $(GREEN)"\nLibft is ready. ✅\n"$(COLOUR_RESET)

$(MINILIBX) :
	@echo $(YELLOW)"Creating $(MINILIBX)"$(COLOUR_RESET)

	@make -sC $(MLX_DIR)
	@echo $(GREEN)"MLX Library is ready. ✅\n"$(COLOUR_RESET)

clean :
	@make clean -sC libft
	@make clean -sC $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"\nRemoving object directory and files"$(COLOUR_RESET)

fclean : clean
	@rm -f $(NAME)
	@make fclean -sC libft
	@echo $(RED)"Removing $(NAME), libft.a and libmlx.a\n"$(COLOUR_RESET)

re : fclean all

.PHONY = all clean fclean re
