CC = cc
NAME = miniRT
LIBFT = libft
LIBFT_LIB = libft.a
MINILIBX = minilibx
LDFLAGS = -L$(LIBFT) -lft -L$(MINILIBX) -lmlx -L/usr/lib/X11 -lX11 -lXext -L/usr/lib -lGL -lm
INCLUDE = -I.

MANDATORY_DIR = mandatory
BONUS_DIR = bonus

SRC_FILES = main.c \
	check.c color.c engine.c engine_helper_func.c engine_helper_init.c \
	free_helper.c image.c intersects_helper.c \
	material.c material_utils.c \
	sphere.c vector.c vector_stack.c vector_utils.c vector_more.c \
	cylinder.c cylinder_utils.c vector_utils_s.c camera.c texture.c texture_utils.c\
	cone.c cone_utils.c mlx.c\
	ft_atod/ft_atod.c \
	ft_exit/ft_exit.c \
	ft_init/ft_init_cone.c ft_init/ft_init_cylinder.c ft_init/ft_init_object.c ft_init/ft_init_plane.c ft_init/ft_init_sphere.c ft_init/ft_init_struct.c ft_init/ft_init_utils.c ft_init/ft_init.c ft_init/init_main.c \
	test/print_camera.c test/print_light.c test/print_obj.c test/print_scene.c test/print_vector.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

SRC = $(addprefix $(MANDATORY_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(addsuffix _bonus.c, $(basename $(SRC_FILES))))

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

ifdef FLAG_BONUS
	TARGET = bonus/$(NAME)
	OBJECTS = $(OBJS_BONUS)
else
	TARGET = mandatory/$(NAME)
	OBJECTS = $(OBJS)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(MAKE) -C $(LIBFT)/
	$(MAKE) -C $(MINILIBX)/
	$(CC) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MINILIBX) clean

fclean: clean
	rm -rf $(MANDATORY_DIR)/$(NAME) $(BONUS_DIR)/$(NAME) $(LIBFT)/$(LIBFT_LIB)
	$(MAKE) -C $(LIBFT) fclean

re:
	make fclean
	make all

bonus:
	$(MAKE) FLAG_BONUS=1 all

.PHONY: all bonus clean fclean re
