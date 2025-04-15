CC = cc 
CFLAGS = -Wall -Wextra -Werror
SERC =  pasing.c gnl.c so_long.c flood_fill.c parsing_utils.c \
		parsing_utils_two.c helps_fun.c clear_file.c moves.c\
		display.c
NAME = so_long
MLX = -Lmlx -lmlx -lX11 -lXext
OBJ = $(SERC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) 

re: fclean all
