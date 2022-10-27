# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 02:15:22 by trubat-d          #+#    #+#              #
#    Updated: 2022/10/27 18:07:05 by trubat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = ft_calloc.c ft_checkarg.c ft_mid_val.c ft_split.c ft_strncmp.c push_main.c push_swap.c \
		utils_compare.c utils_high.c utils_lowest.c utils_push.c utils_rev_rotate.c \
		utils_rotate.c utils_swap.c utils_tri_sort.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME = push_swap
AR = ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/ -I printf/includes/

OPTIONS = -L printf -lftprintf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de push_swap...$(RESETTXT)"
		@ cd printf && $(MAKE)
		@ gcc $(CFLAGS) $(INCLUDES) $(OPTIONS) $(OBJS) -o $@ 
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJS)
		@cd printf && $(MAKE) clean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de push_swap et libftprintf.a...$(RESETTXT)"
		@$(RM) $(NAME)
		@cd printf && $(MAKE) fclean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
		
re:		fclean all

.PHONY: all clean fclean re 