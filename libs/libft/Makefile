NAME =	libft.a

HEADER = libft.h

LIST =	./ft_tolower.c		./ft_toupper.c		./ft_isprint.c\
		./ft_isascii.c		./ft_isalnum.c		./ft_isdigit.c\
		./ft_isalpha.c		./ft_strncmp.c		./ft_strnstr.c\
		./ft_strrchr.c		./ft_strchr.c		./ft_strlen.c\
		./ft_strlcpy.c		./ft_strlcat.c		./ft_memset.c\
		./ft_atoi.c			./ft_bzero.c		./ft_memcpy.c\
		./ft_memccpy.c		./ft_memmove.c		./ft_memchr.c\
		./ft_memcpy.c		./ft_memcmp.c		./ft_calloc.c	\
		./ft_strdup.c		./ft_putnbr_fd.c	./ft_putendl_fd.c\
		./ft_putstr_fd.c	./ft_putchar_fd.c	./ft_substr.c\
		./ft_strjoin.c		./ft_itoa.c			./ft_strmapi.c\
		./ft_strtrim.c		./ft_split.c\

LIST_B =	./ft_lstnew.c		./ft_lstadd_front.c		./ft_lstsize.c\
			./ft_lstlast.c		./ft_lstadd_back.c		./ft_lstdelone.c\
			./ft_lstclear.c		./ft_lstiter.c			./ft_lstmap.c\

OBJ = $(patsubst %.c, %.o, $(LIST))
OBJ_B = $(patsubst %.c, %.o, $(LIST_B))

FLAGS = -Wall -Wextra -Werror

all :		$(NAME)

$(NAME) :	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ -I

bonus :
	make OBJ="$(OBJ_B)" all
	
clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all

.PHONY : all clean fclean re bonus

	
