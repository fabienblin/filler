# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/05/15 14:08:18 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/05/23 17:23:27 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

NAME	=	filler

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/

INC_DIR	=	./inc/

CFILES	=	main.c			ft_constructors.c	ft_destructors.c

OFILES	=	$(CFILES:.c=.o)

SOURCES	=	$(addprefix $(SRC_DIR), $(CFILES))

OBJECTS	=	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS	=	-Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:

clean	:

fclean	:

re		:

libft	:
			make -C ./libft/

test	:	libft
			gcc ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler && cat testinput | ../players/filler_test.filler

debug	:	libft
			gcc -ggdb ./src/*.c ./libft/libft.a -I ./libft/inc -I ./inc -o ../players/filler_test.filler && lldb ../players/filler_test.filler

.PHONY	:	all clean fclean re libft