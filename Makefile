NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFT_DIR	= libft

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	ar rcs #(NAME) $(OBJS) $(LIBFT_DIR)/*.o

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re