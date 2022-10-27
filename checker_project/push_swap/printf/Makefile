SRC_PATH = src/
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c \
		ft_atoi.c ft_strchr.c ft_strlen.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_itoa.c ft_isdigit.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME = libftprintf.a
AR = ar rcs
CC		= gcc
RM		= rm -f

OPTIONS = -I includes/
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJS)

%.o:$(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(OPTIONS) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)
re:		fclean all

.PHONY: all clean fclean re 