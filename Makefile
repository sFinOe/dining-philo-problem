NAME = philo

NAME2 = philo_bonus

RED=\033[0;31m

YELLOW=\033[1;33m

GREEN=\033[0;32m

GREY=\x1b[30m

RED=\x1b[31m

GREEN=\x1b[32m

YELLOW=\x1b[33m

BLUE=\x1b[34m

PURPLE=\x1b[35m

CYAN=\x1b[36m

WHITE=\x1b[37m

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_philo = philo.c

SRC_philo_bonus = ./bonus/philo_bonus.c

ALL_OF_SRC = args.c\
			error.c\
			init.c\
			lib_utils.c\
			threading.c\
			time.c\

ALL_OF_B_SRC = ./bonus/args.c\
			./bonus/dead.c\
			./bonus/error.c\
			./bonus/init.c\
			./bonus/lib_utils.c\
			./bonus/routine.c\
			./bonus/time.c\
			./bonus/print.c\

OBJ_philo = ${SRC_philo:.c=.o}

OBJ_philo_bonus = ${SRC_philo_bonus:.c=.o}

OBJ_SRC = ${ALL_OF_SRC:.c=.o}

OBJ_SRC_B = ${ALL_OF_B_SRC:.c=.o}

all: $(NAME)
		@printf "${GREY}\e[1mTo compile ./philo [Num of philos] [Time to die] [Time to eat] [Time to sleep]\e\n"
		@printf "${RED}\e[1mFor Better use keep num of philos low!!\e\n"

bonus: $(NAME) $(NAME2)
		@printf "${GREY}\e[1mTo compile ./philo_bonus [Num of philos] [Time to die] [Time to eat] [Time to sleep]\e\n"
		@printf "${RED}\e[1mSeriously NOW Better keep num of philos low!!!\e\n"

%.o: %.c philo.h ./bonus/philo_bonus.h
						@-${CC} -c ${CFLAGS} -o $@ $<
						@printf "${BLUE}\e[1mMaking files please wait....\e\n"

$(NAME) : $(OBJ_philo) $(OBJ_SRC)
			@-$(CC) $(CFLAGS) $(OBJ_philo) $(OBJ_SRC) -o $(NAME)
			@printf "${GREEN}\e[1mSuccess making Philos ....\e\n"

$(NAME2) : $(OBJ_philo_bonus) $(OBJ_SRC_B)
			@-$(CC) $(CFLAGS) $(OBJ_philo_bonus) $(OBJ_SRC_B) -o $(NAME2)
			@printf "${GREEN}\e[1mSuccess making Philos for bonus ....\e\n"

.PHONY: all bonus clean fclean re

clean:
		@rm -f $(OBJ_philo) $(OBJ_SRC) $(OBJ_philo_bonus) $(OBJ_SRC_B)
		@printf "${YELLOW}\e[1m.o files have been removed (•̀ᴗ•́ )و\e\n"

fclean: clean
		@rm -f $(NAME) $(NAME2)
		@printf "${YELLOW}\e[1mPlus the compiling files \( ﾟヮﾟ)/\e\n"

re: fclean all