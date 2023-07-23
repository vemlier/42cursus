CC=cc
#CFLAGS=-Wall -Wextra -Werror -g
NAME=miniRT
SRC_MAN=mandatory/main.c \
	mandatory/check.c mandatory/color.c mandatory/engine.c mandatory/engine_helper_func.c mandatory/engine_helper_init.c \
	mandatory/free_helper.c mandatory/image.c mandatory/intersects_helper.c \
	mandatory/material.c mandatory/material_utils.c \
	mandatory/sphere.c mandatory/vector.c mandatory/vector_stack.c mandatory/vector_utils.c mandatory/vector_more.c \
	mandatory/cylinder.c mandatory/cylinder_utils.c mandatory/vector_utils_s.c mandatory/camera.c mandatory/texture.c mandatory/texture_utils.c\
	mandatory/cone.c mandatory/cone_utils.c mandatory/mlx.c\
	mandatory/ft_atod/ft_atod.c \
	mandatory/ft_exit/ft_exit.c \
	mandatory/ft_init/ft_init_cone.c mandatory/ft_init/ft_init_cylinder.c mandatory/ft_init/ft_init_object.c mandatory/ft_init/ft_init_plane.c mandatory/ft_init/ft_init_sphere.c mandatory/ft_init/ft_init_struct.c mandatory/ft_init/ft_init_utils.c mandatory/ft_init/ft_init.c mandatory/ft_init/init_main.c \
	mandatory/test/print_camera.c mandatory/test/print_light.c mandatory/test/print_obj.c mandatory/test/print_scene.c mandatory/test/print_vector.c \
	mandatory/gnl/get_next_line.c mandatory/gnl/get_next_line_utils.c
	
SRC_BONUS=bonus/main_bonus.c \
	bonus/check_bonus.c bonus/color_bonus.c bonus/engine_bonus.c bonus/engine_helper_func_bonus.c bonus/engine_helper_init_bonus.c \
	bonus/free_helper_bonus.c bonus/image_bonus.c bonus/intersects_helper_bonus.c \
	bonus/material_bonus.c bonus/material_utils_bonus.c \
	bonus/sphere_bonus.c bonus/vector_bonus.c bonus/vector_stack_bonus.c bonus/vector_utils_bonus.c bonus/vector_more_bonus.c \
	bonus/cylinder_bonus.c bonus/cylinder_utils_bonus.c bonus/vector_utils_s_bonus.c bonus/camera_bonus.c bonus/texture_bonus.c bonus/texture_utils_bonus.c\
	bonus/cone_bonus.c bonus/cone_utils_bonus.c bonus/mlx_bonus.c\
	bonus/ft_atod/ft_atod.c \
	bonus/ft_exit/ft_exit.c \
	bonus/ft_init/ft_init_cone.c bonus/ft_init/ft_init_cylinder.c bonus/ft_init/ft_init_object.c bonus/ft_init/ft_init_plane.c bonus/ft_init/ft_init_sphere.c bonus/ft_init/ft_init_struct.c bonus/ft_init/ft_init_utils.c bonus/ft_init/ft_init.c bonus/ft_init/init_main.c \
	bonus/test/print_camera.c bonus/test/print_light.c bonus/test/print_obj.c bonus/test/print_scene.c bonus/test/print_vector.c \
	bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c

TEST=test/t_fork_print.c \
	 test/t_info_print.c \
	 test/t_philo_print.c 
MAN_OBJS = $(SRC_MAN:.c=.o)
BONUS_OBJS = $(SRC_BONUS:.c=.o)
LIBFT	= libft
LIBFT_LIB	= libft.a

ifdef FLAG_BONUS
	OBJS = $(SRC_BONUS:.c=.o)
	NAME = bonus/miniRT
else
	OBJS = $(SRC_MAN:.c=.o)
	NAME = mandatory/miniRT
endif

all: $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	$(CC) $(OBJS) -Llibft -lft -Lmlx -lmlx -Iml -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(MAN_OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./bonus/miniRT
	rm -rf $(LIBFT_LIB)
	make -C libft fclean

re:
	make fclean
	make all

bonus:
	make FLAG_BONUS=1 all

.PHONY:all bonus clean fclean re