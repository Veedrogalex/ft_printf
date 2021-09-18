NAME = libftprintf.a

SRCDIR = ./src/

LIBFTDIR = ./libft/

SRC =	$(SRCDIR)ft_printf_conclusion.c\
		$(SRCDIR)ft_printf_conclusion_hex.c\
		$(SRCDIR)ft_printf_parse_for_num.c\
		$(SRCDIR)ft_printf_parse.c\
		$(SRCDIR)ft_printf_utils_for_hex.c\
		$(SRCDIR)ft_printf_utils.c\
		$(SRCDIR)ft_printf.c\
		

SRC_L =	ft_bzero.c   \
		ft_memccpy.c \
		ft_memchr.c  \
		ft_memcmp.c  \
		ft_memcpy.c  \
		ft_memmove.c \
		ft_strchr.c  \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c    \
		ft_calloc.c  \
		ft_strdup.c  \
		ft_substr.c  \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c   \
		ft_itoa.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c


FILES = $(addprefix $(LIBFTDIR), $(SRC_L)) ${SRC}

OBJ = $(FILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLD = ./includes/

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) $(addprefix -I, $(INCLD)) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean  all