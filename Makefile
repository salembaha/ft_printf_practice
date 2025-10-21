NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
SRC_DIR		= src

SRCS = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_print_c.c \
		$(SRC_DIR)/ft_print_s.c \
		$(SRC_DIR)/ft_print_d.c \
		$(SRC_DIR)/ft_print_u.c \
		$(SRC_DIR)/ft_print_x.c \
		$(SRC_DIR)/ft_print_p.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

.PHONY: all clean fclean re
