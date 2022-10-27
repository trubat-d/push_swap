# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 02:15:22 by trubat-d          #+#    #+#              #
#    Updated: 2022/10/27 18:06:29 by trubat-d         ###   ########.fr        #
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

NAME = push_swap

all: $(NAME)

$(NAME):
		@cd ./push_swap_project && $(MAKE) && cp push_swap ../push_swap

bonus:
		@cd ./checker_project && $(MAKE) && cp checker ../checker
clean:
		$(ECHO) "$(RED)Suppression des push_swap...$(RESETTXT)"
		@rm -f push_swap
		@cd ./push_swap_project && $(MAKE) fclean && cd ..
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de checker...$(RESETTXT)"
		@rm -f checker
		@cd ./checker_project && $(MAKE) fclean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
		
re:		fclean all

.PHONY: all clean fclean re 