# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/05/15 14:08:18 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/06/23 18:28:07 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

NAME	=	fablin.filler

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/

INC_DIR	=	./inc/

CFILES	=	main.c			ft_constructors.c	ft_destructors.c	\
			ft_bresenham.c	ft_init.c			ft_input.c			\
			ft_misc.c		ft_play.c			ft_strats.c			\
			ft_strats_ext.c

OFILES	=	$(CFILES:.c=.o)

SOURCES	=	$(addprefix $(SRC_DIR), $(CFILES))

OBJECTS	=	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS	=	-Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:	$(OBJECTS)
			@make libft
			gcc $(FLAGS) $(OBJECTS) -L ./libft/ -lft -o $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@make obj
					gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./libft/inc/

clean	:	obj
			@make clean -C ./libft/
			@rm -rf $(OBJ_DIR)

fclean	:	obj
			@make fclean -C ./libft/
			@rm -f $(NAME)
			@rm -rf $(OBJ_DIR)

re		:	fclean all

obj	:
			@mkdir -p $(OBJ_DIR)

libft	:
			@make -C ./libft/

test	:	libft
			gcc ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler

debug	:	libft
			gcc -ggdb ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler && lldb ../players/filler_test.filler

.PHONY	:	all clean fclean re libft obj
