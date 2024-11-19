SRCS = ft_printf.c ft_putnbr.c ft_putstr.c\
	ft_putchar.c ft_putptr_p.c ft_putunsigned.c\
	ft_putnbr_base_x.c ft_putnbr_base_x_up.c

	
	
	

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o:%.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}



clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : clean 