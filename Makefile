NAME = ft_ls

INC = -I./libft/

SRC = 	argument.c\
		main.c\
		make_ls.c\
		aff.c\
		sort.c\
		ft_optionl.c\
		sort_time.c\
		ls.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CFLAGS = $(INC)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		gcc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)

$(LIBFT):
		make -C libft/

clean:
		rm -rf $(OBJ)
		make -C libft/ clean

fclean: clean
		make -C ./libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: make clean fclean re all
