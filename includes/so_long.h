/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:54:31 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/17 18:05:16 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define WIN_WIDTH 40 * 64 
#define WIN_HEIGHT 60 * 64
#define ITERATIONS 100
#define SAMPLE_RATE 345678
#define AMPLITUDE 99999
# include "../mlx/mlx.h"
# include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_textures
{
	void	*floor;
	void	*balls;
	void	*balls_2;
	
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*winf;
	char		**grid;
	char		**grid_bis;
	int			height;
	int			length;
	int			player_x;
	int			player_y;
	int			pos_ex;
	int			pos_ey;
	int			coin;
	int			move;
	int			grid_c;
	int			grid_e;
	int			grid_l;
	char		*file;
	t_textures	*textures;
}	t_game;

char	*get_next_line(int fd);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *str, int c);
char	*ft_free(char *buffer, char *buf);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);

int		ft_printf(const char *str, ...);
ssize_t	ft_putc(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putptr(void *ptr);
ssize_t	ft_putun(unsigned int n);
ssize_t	ft_puthex(unsigned int n, int index);
ssize_t	convert(const char *str, va_list *args);

int		begin_render(t_game *game, char **grid);
int		check_call(int fd, int n_line, t_game *game, char *file);
int		read_map(char *file, t_game *game);
int		check_map(t_game *game);
int		check_wall(t_game *game);
int		check_coin(t_game *game);
int		size_map(t_game *game);
int		check_double(t_game *game);
int		count_line(int fd);
int		size_map(t_game *game);
int		get_line_length(char *line);
int		pos_player(t_game *game);
int		pos_exit(t_game *game);
int		fill_grid_bis(int fd, int lines, t_game *game);
int		fill_grid(int fd, int lines, t_game *game);
int		check_flood(int fd, int n_lines, t_game *game, char *file);
void	flood_fill(t_game *game, int x, int y);

void	move_player(t_game *game, int dx, int dy);
void	move_player_two(t_game *game, int dx, int dy);
void	put_enemy(t_game *game);
void	render_map(t_game *game, char **grid);
void	get_images(t_game *game);
int		handle_key(int keycode, t_game *game);
int		valid_move(t_game *game, int dx, int dy);

void	free_resources(t_game *game);
void	free_grid(char **grid);
void	put_null(t_game *game);
void	free_ressources_grid(t_game *game);

#endif