SRC_PATH = src/
SRC = ft_calloc.c ft_checkarg.c ft_mid_val.c ft_split.c ft_strncmp.c push_main.c push_swap.c \
		utils_compare.c utils_high.c utils_lowest.c utils_push.c utils_rev_rotate.c \
		utils_rotate.c utils_swap.c utils_tri_sort.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME = libpushswap.a
AR = ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/ -I printf/includes/

OPTIONS = -L printf -lftprintf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		@cd ./printf && $(MAKE) && cp libftprintf.a ../$(NAME)
		@$(AR) $@ $(OBJS)

%.o:$(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		@$(RM) $(OBJS)
		@cd ./printf && $(MAKE) clean

fclean:	clean
		@$(RM) $(NAME)
		@cd ./printf && $(MAKE) fclean

re:		fclean all

.PHONY: all clean fclean re 