NAME = binary

SRC =	./srcs/binary_crypto.c \
	./srcs/binary_read_chaine.c \
	./srcs/binary_reader.c \
	./srcs/binary_spe.c \
	./srcs/binary_utils.c \
	./srcs/binary_write_chaine.c \
	./srcs/binary_writer.c \
	./srcs/binary.c \
	./main.c \

OBJ = $(SRC:.c=.o)

DEPS = $(OBJ:.o=.d)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o:  %.c 
	${CC} ${CFLAGS} -MMD -c $< -o $@

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