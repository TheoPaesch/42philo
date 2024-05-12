NAME=philo

CC=cc
CFLAGS = -Wall -Wextra -Werror


CFILES = error.c \
		 init_philos.c \
		 main.c \
		 parsing.c \
		 routine.c \
		 time.c \
		 utils.c

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f philo

re: fclean all