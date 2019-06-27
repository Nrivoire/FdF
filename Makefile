# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/14 18:19:22 by nrivoire     #+#   ##    ##    #+#        #
#    Updated: 2019/06/25 18:20:42 by nrivoire    ###    #+. /#+    ###.fr      #
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
SRC_SUP = cplx_segment
SRC_PATH = src
SRC_NAME = main.c\
		   list.c get_next_line.c fdf_parsing.c create_tab.c\
		   cplx_segment/ft_absolu.c\
		   cplx_segment/ft_error.c\
		   cplx_segment/ft_make_cplx.c\
		   cplx_segment/put_segment.c\
		   cplx_segment/strai_horizontal.c\
		   cplx_segment/strai_vertical.c\
		   cplx_segment/swap_cplx.c\
		   cplx_segment/vertical_kind.c\
		   cplx_segment/horizontal_kind.c\
		   cplx_segment/ft_create_img.c\
		   cplx_segment/ft_pixel_put.c\
		   cplx_segment/make_rgb.c\
		   cplx_segment/hex_rgb.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

#	Objects
OBJ_PATH = .objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#	Includes
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -L libft
LDLIBS = -lft
MINILIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

#	Compiler
CC = gcc
CFLAGS = -Wall  -Wextra -I.

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

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
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
