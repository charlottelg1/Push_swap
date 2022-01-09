NAME = push_swap

SRCS = main.c \
	  init.c \
	  sort.c \
	  sort_a.c \
	  sort_b.c \
	  find.c \
	  need.c \
	  algo.c \
	  algo_a.c \
	  algo_b.c \
	  ope_a.c \
	  ope_b.c \
	  ope_double.c \
	  utils.c \
	  free.c \
	  sort_top_b.c \
	  sort_top_a.c \
	  short_a.c \
	  short_b.c \
	  call_a.c \
	  call_b.c \
	  short_part_median_a.c \

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${SRCS} -o push_swap

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re

