NAME	= libft.a

SRCS =	ft_strlen.c		ft_atoi.c		\
		ft_bzero.c		ft_isalnum.c	\
		ft_isalpha.c	ft_isascii.c	\
		ft_isdigit.c	ft_isprint.c	\
		ft_memcpy.c		ft_memccpy.c	\
		ft_memset.c		ft_strcat.c		\
		ft_strchr.c		ft_strcmp.c		\
		ft_strcpy.c		ft_strdup.c		\
		ft_strncat.c	ft_strnstr.c	\
		ft_strstr.c		ft_strncmp.c	\
		ft_strncpy.c	ft_strrchr.c	\
		ft_tolower.c	ft_toupper.c	\
		ft_memchr.c		ft_memmove.c	\
		ft_memcmp.c		ft_strlcat.c	\
		ft_memalloc.c	ft_memdel.c		\
		ft_strnew.c		ft_strdel.c		\
		ft_strclr.c		ft_striter.c	\
		ft_striteri.c	ft_strmap.c		\
		ft_strmapi.c	ft_strequ.c		\
		ft_strnequ.c	ft_strsub.c		\
		ft_strjoin.c	ft_strtrim.c	\
		ft_putchar.c	ft_putstr.c		\
		ft_putnbr.c		ft_putchar_fd.c	\
		ft_putstr_fd.c	ft_putendl_fd.c	\
		ft_putnbr_fd.c	ft_strsplit.c	\
		ft_itoa.c		ft_intlen.c		\
		ft_lstnew.c		ft_lstdelone.c	\
		ft_lstdel.c		ft_lstadd.c		\
		ft_lstmap.c		ft_lstiter.c	\
		ft_lstat.c		ft_lstsize.c	\
		ft_putendl.c 	ft_error.c		\
		get_next_line.c ft_fnutils.c	\
		ft_countwords.c ft_splitdel.c	\
		ft_log.c		ft_putfloat.c	\
		ft_printspace.c

OBJ_DIR = ./.objs
SRC_DIR = ./srcs
INC_DIR = ./includes
OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
CFLAGS	:= -Wall -Wextra -Werror -I$(INC_DIR)

p_libft =  \033[1m[\033[1m\033[33m LIBFT \033[0m\033[1m]\033[0m  

all: mk $(NAME)

$(NAME):  $(OBJS)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@printf "$(p_libft)\033[1m library successfully created.\033[0m\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/libft.h $(INC_DIR)/get_next_line.h 
		@gcc $(CFLAGS) -o $@ -c $<

mk: 
	@mkdir -p .objs
clean:
		@rm -f ./objs/$(OBJS)
		@printf "$(p_libft) objects cleared.\n"

fclean : clean
		@rm -f $(NAME)
		@printf "$(p_libft) binary deleted.\n"

re:		fclean all