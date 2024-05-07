# Library Name
NAME = cub3d
NAME_BONUS = cub3d_bonus

# Dependencies
LIBFT = libft
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
MLX42 = MLX42/build/libmlx42.a
GIT_MLX = https://github.com/codam-coding-college/MLX42.git

# Compiler and Linker Config
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3 -g #-fsanitize=address
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)
LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit $(MLX42) -lglfw -L $(shell brew --prefix glfw)/lib

# Sources directories
INCDIR = inc
SRCDIR = src
SRCDIRB = src_bonus
SRC = error.c extract_info.c extract_info2.c extract_info3.c free.c free_2.c init.c main.c parsing.c utils.c \
       utils2.c verify_data.c map_parsing.c map_parsing_2.c open_window.c hook.c draw_img.c background.c \
       camera.c dda.c dda_2.c texture.c texture_2.c movement.c movement_2.c clean.c
SRCB = background_bonus.c \
	camera_bonus.c \
	clean_bonus.c \
	dda_2_bonus.c \
	dda_bonus.c \
	draw_img_bonus.c \
	error_bonus.c \
	extract_info2_bonus.c \
	extract_info3_bonus.c \
	extract_info_bonus.c \
	free_2_bonus.c \
	free_bonus.c \
	hook_bonus.c \
	init_bonus.c \
	main_bonus.c \
	map_parsing_2_bonus.c \
	map_parsing_bonus.c \
	movement_2_bonus.c \
	movement_bonus.c \
	open_window_bonus.c \
	parsing_bonus.c \
	texture_2_bonus.c \
	texture_bonus.c \
	utils2_bonus.c \
	utils_bonus_bonus.c \
	verify_data_bonus.c

VPATH = ${SRCDIR} ${SRCDIRB}

# Object directories
OBJDIR = obj
OBJDIRB = obj_bonus
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
OBJSB = $(SRCB:%.c=$(OBJDIRB)/%.o)

# Default target
all: install $(NAME)

# Linking
$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -L$(LIBFTDIR) -lft -o $@

# Bonus target
$(NAME_BONUS): $(LIBFT) $(MLX42) $(OBJSB)
	$(CC) $(OBJSB) $(LDFLAGS) -L$(LIBFTDIR) -lft -o $@

# Library dependency
$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX42):
		brew update --quiet
		if brew list cmake &> /dev/null; then \
		echo "Process 1 : cmake"; \
	else \
		brew install cmake &> /dev/null; \
	fi 
		if brew list glfw &> /dev/null; then \
		echo "Process 2 : brew"; \
	else \
		brew install glfw &> /dev/null; \
	fi
		git clone $(GIT_MLX) &> /dev/null
		cd MLX42/ && cmake -B build &> /dev/null
		cd MLX42/ && cmake --build build -j4 &> /dev/null


# Compilation pattern rule
$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(FLAGS) -I$(INCDIR) -I$(LIBFTDIR)/inc -Imlx42 -c $< -o $@

# Object directory creation
$(OBJDIR):
	$(MK) $(OBJDIR)

# Compilation pattern rule
$(OBJDIRB)/%.o : %.c | $(OBJDIRB)
	$(CC) $(FLAGS) -I$(INCDIR) -I$(LIBFTDIR)/inc -Imlx42 -c $< -o $@

# Object directory creation
$(OBJDIRB):
	$(MK) $(OBJDIRB)

# Cleaning up
clean:
	$(RM) $(OBJDIR) $(OBJDIRB)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

re: fclean all

bonus: $(NAME_BONUS)

leaks:
	leaks --atExit -- ./$(NAME) map2.cub

valgrind:
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) map2.cub

.PHONY: clean fclean re bonus all install leaks valgrind