CC = cc
FLAGS = -Wall -Wextra -Werror 
AR  = ar rcs

Source_Code = ft_printf.c  ft_hexConvert.c  ft_putnbr.c

Object_Files = $(Source_Code:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(Object_Files)
	$(AR) $(NAME) $(Object_Files)


%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(Object_Files)

fclean : clean
	rm -f $(NAME)

re: fclean all