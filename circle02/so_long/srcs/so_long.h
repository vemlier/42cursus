/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:13:13 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 16:50:33 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "get_next_line.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53

typedef struct s_img {
	void	*chara;
	void	*chest;
	void	*land;
	void	*door;
	void	*door2;
	void	*wall;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	*str_line;
	int		width;
	int		height;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
	int		direction;
}	t_game;

char	*ft_strdup_new(char *s);
int		ft_strlcpy_new(char *dst, char *src, int len);
char	*ft_strjoin_new(char *s1, char *s2);

t_img	img_init(void *mlx);
void	put_img(t_game *g, int w, int h);
void	put_image_chara(t_game *g, int w, int h);
void	setting_img(t_game *game);

void	map_read(char *filename, t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
void	map_check(t_game *game);

int		clear_game(t_game *game);
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

void	print_error(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
int		main(int ac, char *av[]);

#endif