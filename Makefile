# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/17 13:47:42 by gulandre     #+#   ##    ##    #+#        #
#    Updated: 2019/12/19 11:27:25 by gulandre    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

HEADER			=		includes/cub.h			\

OBJS_DIR		=		./srcs/obj/*

SRC_PATH		=		srcs

SRCS_FILE		=		libft/ft_strlen.c 			\
						libft/ft_strdup.c 			\
						libft/ft_isalpha.c 			\
						libft/ft_putstr_fd.c 		\
						libft/ft_putchar_fd.c 		\
						libft/ft_putendl_fd.c 		\
						gnl/get_next_line.c 		\
						gnl/get_next_line_utils.c	\
						error_memory.c 				\
						load_map.c 					\
						parsing_info.c 				\
						main.c						\

SRCS			=		$(addprefix $(SRC_PATH)/,$(SRCS_FILE))

OBJS			= 		${SRCS:.c=.o}

NAME			=		cub3D

RM				=		rm -f

FLAGS			=		-g3 -Wall -Wextra -Werror

CC				=		gcc

MLX				=		./opengl/libmlx.a -framework OpenGL -framework AppKit

all				:		$(NAME)

bonus			:		all

%.o				:		%.c
						@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $(notdir $<)
						@$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME)			:		${OBJS}
						@echo "\n\033[0;32m[compiling ok] \033[0m"
						@$(CC) $(FLAGS) $(MLX) -o ${NAME} ${OBJS}
						@echo "\n\033[1;31m Export:\033[0m" $(notdir $(OBJS)) "to :\033[0;32msrcs/obj\033[0m"		

clean			:		
						@echo "\n\033[0;34m[clean " $(notdir $(OBJS))"]"
						@$(RM) $(OBJS_DIR)

fclean			:		clean
						@echo "\033[0;34m[clean " $(NAME)"] \n"
						@$(RM) $(NAME)

re				:      	fclean all

.PHONY			:		clean fclean re