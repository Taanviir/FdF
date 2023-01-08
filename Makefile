# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanas <tanas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 22:21:39 by tanas             #+#    #+#              #
#    Updated: 2023/01/07 22:22:10 by tanas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
C_FLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $^

%.o : %.c
	@cc $(C_FLAGS) -c $< -o $@
	@echo "Compiling $< now"

clean :
	@rm -rf *.o
	@echo "Cleaning object files"

fclean : clean
	@rm -f $(NAME)
	@echo "Cleaning $(NAME)"

re : fclean all

.PHONY = all clean fclean re