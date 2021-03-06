# Project file
NAME = ft_ls

# Project builds and dirs
SRCDIR = ./src/
#SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCNAMES =	aff.c argument.c ft_optionl.c ls.c main.c make_ls.c \
		padd.c sort.c sort_time.c pad.c
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./inc/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft

# Optimization and Compiler flags and commands
CC = gcc
OPFLAGS = -O3 -funroll-loops
CFLAGS = -Wall -Werror -Wextra -g3

# Debugging flags
DEBUG = -g3

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT)

# Libft rule
$(LIBFT):
	@make -C $(LIBDIR)

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
