NAME = ft_ls
SRC = srcs/main.c srcs/list.c srcs/padding.c srcs/print.c \
	srcs/function.c srcs/sort_list.c srcs/print_option.c\
	srcs/function_cut_add.c srcs/manage_size.c\
	srcs/ls.c srcs/create_list.c srcs/check.c
FLAGS = -I Includes -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	make -C libft/

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) libft/libft.a -o $@

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
