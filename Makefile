NAME					= pipex

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
INCS					= -I include

SRC						= pipex.c utils.c 
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) a.out.dSYM


re : fclean all

test :
	make -C $(LIBFT_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

leak :
	make -C $(LIBFT_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus