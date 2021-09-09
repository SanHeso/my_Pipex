NAME = pipex

HEADER = includes/pipex.h

SRCS = pipex.c utils.c utils_2.c ft_split.c find_path.c

BNS_SRCS = bonus_find_path.c bonus_pipex.c bonus_utils.c bonus_utils_2.c ft_split.c

SRCS_DIR = $(addprefix src/, $(SRCS))

BNS_SRCS_DIR = $(addprefix src_bonus/, $(BNS_SRCS))

BNS_OBJS = $(patsubst src_bonus/%.c, obj/%.o, $(BNS_SRCS_DIR))

OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS_DIR))

OUT_DIR = obj

GREEN = "\033[0;32m"
CYAN = "\033[0;36m"
RED = "\033[0;31m"
MAGENTA = "\033[0;35m"
EOC = "\033[0m"

CC = @gcc

CFLAGS = -Wall -Wextra -Werror -O2

all:		$(OUT_DIR) $(NAME)

obj/%.o:	src/%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
				$(CC) $(OBJS) -o $(NAME)
				@echo $(MAGENTA) "$(NAME) is created!" $(EOC)

obj/%.o:	src_bonus/%.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus:		fclean $(OUT_DIR) $(BNS_OBJS) $(HEADER)
				$(CC) $(BNS_OBJS) -o $(NAME)
				@echo $(MAGENTA) "Bonus is added!" $(EOC)

$(OUT_DIR):
				@mkdir -p $@
				@echo $(CYAN) "$@ direction created!" $(EOC)

clean:
				@rm -rf $(OUT_DIR)
				@echo $(GREEN) "clean comleted!" $(EOC)

fclean:		clean
				@rm -f $(NAME)
				@echo $(GREEN) "fclean comleted!" $(EOC)

re:			fclean all

.PHONY:		all clean fclean re