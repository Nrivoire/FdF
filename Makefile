# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/14 18:19:22 by nrivoire     #+#   ##    ##    #+#        #
#    Updated: 2019/08/21 13:35:52 by nrivoire    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Output
NAME = fdf

#	Sources
# SRC_SUP = {dossiers dans src qui seront separe par une virgule}
SRC_PATH = src
SRC_NAME = main.c\
		   get_next_line.c fdf_parsing.c check_map.c\
		   event.c key_press.c make_rgb.c button.c\
		   create_map.c conic.c\
		   display_map.c\
		   ft_absolu.c\
		   ft_create_img.c\
		   ft_error.c\
		   ft_pixel_put.c\
		   hex_rgb.c\
		   put_segment.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

#	Objects
OBJ_PATH = .objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#	Includes
INC_PATH = includes
INC_NAME = fdf.h keys.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -L libft #-g3 -fsanitize=address
LDLIBS = -lft
MINILIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

#	Compiler
CC = clang
CFLAGS = -Wall -Werror -Wextra -I. #-g3 -fsanitize=address

################
##   COLORS   ##
################

GREY=$ \x1b[30m
RED=$ \x1b[31m
GREEN=$ \x1b[32m
YELLOW=$ \x1b[33m
BLUE=$ \x1b[34m
PINK=$ \x1b[35m
CYAN=$ \x1b[36m
WHITE=$ \x1b[37m

# This is a minimal set of ANSI/VT100 color codes
END=$ \x1b[0m
BOLD=$ \x1b[1m
UNDER=$ \x1b[4m
SUR=$ \x1b[7m

#################
##  TARGETS    ##
#################

# $@ -> nom de la règle
# $^ -> représente tout ce qui est apres le :
# $< -> nom de la dependance

# empêche le Makefile de confondre un fichier et une règle en cas de même nom
.PHONY: all clean fclean re

all: libft.a $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) $(MINILIBX) $(LDLIBS) $^ -o $@
	@printf "\n$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

libft.a:
	@make -C ./libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<
	@printf "\r$(YELLOW)$(BOLD)[COMPILE] $(END) $(<:.c=)..."

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

norme:
	norminette $(SRC) $(INC_PATH)
