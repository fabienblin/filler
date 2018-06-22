# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/05/15 14:08:18 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/06/22 20:39:27 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

NAME	=	filler

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

$(NAME)	:	libft
			gcc $(FLAGS) $(SOURCES) ./libft/libft.a -I ./libft/inc -I ./inc -o fablin.filler

clean	:	make clean -C ./libft/

fclean	:	make fclean -C ./libft/

re		:	make re -C ./libft/

libft	:
			make -C ./libft/

test	:	libft
			gcc ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler

debug	:	libft
			gcc -ggdb ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler && lldb ../players/filler_test.filler

.PHONY	:	all clean fclean re libft