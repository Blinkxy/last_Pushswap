
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_A = libft/libft.a
CC = cc
SRC = push_rules.c push_rules_bis.c ft_create_node.c  \
ft_list_size.c push_swap.c push_swap_utils.c linked_lists_utils.c \
errors_handling.c low_arg_handle.c low_arg_bis.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 	

$(NAME): $(OBJ)
	@make -C Libft
	@$(CC) $(OBJ) $(LIBFT_A) -o $(NAME)
	@@$(RM) 
	@echo ---program linked---

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:	
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME) libft/*.o $(LIBFT_A)
	@echo ---program cleared---
	@echo ---objects cleared---

re: fclean all

.PHONY: all clean fclean re
