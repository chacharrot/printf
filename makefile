NAME=libftprintf.a

SRCS = do_format.c do_print.c do_x.c format_check.c ft_digitnumber.c\
		ft_itoa.c ft_printf_util.c ft_printf.c ft_putstr.c ft_putwidth.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ft_printf.h

all : $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all