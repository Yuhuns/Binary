NAME = binary

SRC =	./srcs/binary_crypto.c \
	./srcs/binary_read_chaine.c \
	./srcs/binary_reader.c \
	./srcs/binary_spe.c \
	./srcs/binary_utils.c \
	./srcs/binary_write_chaine.c \
	./srcs/binary_writer.c \
	./srcs/binary.c \
	./srcs/garbage_memory.c \
	./main_write.c \

OBJ = $(SRC:.c=.o)

DEPS = $(OBJ:.o=.d)

CC = clang

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o:  %.c 
	${CC} ${CFLAGS} -g3 -Wuninitialized -Winit-self -MMD -Iincludes -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) -C libft 
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(DEPS)
	$(MAKE) -C libft clean

norm:
	norminette ./srcs/ ./includes ./libft

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean norm fclean re

-include $(DEPS)