SRCS	= ft_printf.c

CC		= cc
CFLAGS	= -Wall -Wextra
LIB		= libftprintf.a
LIBFT	= libft/libft.a
LDFLAGS = -L./libft
LDLIBS	= -lft

OBJS = $(SRCS:%.c=%.o)
NAME = libftprintf.a

$(NAME):
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -c $(SRCS) -I./
	ar -rcs $(LIB) $(OBJS) 

all: $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re