NAME = pipex

SRCS = main.c error.c pip_check.c pip_utils.c get_next_line.c pip_process.c pip_write_result.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re rm -f
