
NAME	= doom
SRCS 	= main.c mlx_tools.c hooks.c utility.c mouse.c mesh.c opp.c matrix.c

OBJ_DIR = ./.objs
SRC_DIR = ./srcs
INC_DIR = ./includes
INC_HDR = -I./mlx -I./libft -I./
INC_LIB = -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit 
INC_H	= includes/doom.h includes/structs.h includes/defines.h libft/libft.a

CFLAGS	:= -Wall -Wextra -g -ggdb3 -O3 -I$(INC_DIR)
OBJS	:= $(patsubst %.c,$(OBJ_DIR)/%.o,  $(SRCS))

all: CREATE_OBJDIR FT_MAKELIB $(NAME)

$(NAME): $(OBJS) $(FT_MAKELIB)
		@make -C mlx/
		@gcc ${CFLAGS} ${INC_LIB} $^ -o ${NAME}

CREATE_OBJDIR:
		@mkdir -p $(OBJ_DIR)

FT_MAKELIB:
		@make -C libft/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_H)
		gcc $(CFLAGS) -o $@ -c $<

clean:
		@rm -f $(OBJS)
		@cd libft/ && make clean
		@cd mlx/ && make clean

fclean : clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@cd libft/ && make fclean

re:		fclean all
