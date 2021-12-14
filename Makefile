NAME = push_swap

INPUT = \
	main.c \
	sort.c \
	utils.c \
	stack.c \
	swap.c \
	push.c \
	rotate.c \
	rrotate.c \
	smart.c \
	minmax.c \
	isort.c \
	indexer.c \

OUTPUT = ${INPUT:.c=.o}

all:	${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME): ${OUTPUT}
	gcc -Wall -Wextra -Werror ${OUTPUT} -o ${NAME}

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re:		fclean all