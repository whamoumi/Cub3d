/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:25:14 by whamoumi          #+#    #+#             */
/*   Updated: 2022/01/04 12:39:56 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 1
# define PI 3.14

typedef struct s_parsing{
	int				fd;
	int				fd1;
	int				fd2;
	int				check;	
	char			*line;
	unsigned int	counter;
	unsigned int	premiere_passe;
	unsigned int	taille_tab;
	unsigned int	taille_ligne;
	unsigned int	taille;
	char			**map;
	unsigned int	no;
	unsigned int	so;
	unsigned int	we;
	unsigned int	ea;
	unsigned int	f;
	unsigned int	c;
	char			*south_texture;
	char			*north_texture;
	char			*east_texture;
	char			*west_texture;
	unsigned int	red_ceil;
	unsigned int	green_ceil;
	unsigned int	blue_ceil;
	unsigned int	red_floor;
	unsigned int	green_floor;
	unsigned int	blue_floor;
	unsigned int	longeur_tab;
	unsigned int	taille_map;
}				t_parsing;

typedef struct s_fenetre
{
	void			*id;
	void			*win;
	void			*img;
	void			*tex;
	void			*tex2;
	void			*tex3;
	void			*tex4;
	void			*tex_sprite;
	int				height_xpm;
	int				width_xpm;
	int				height2_xpm;
	int				width2_xpm;
	int				height3_xpm;
	int				width3_xpm;
	int				height4_xpm;
	int				width4_xpm;
	char			*tmp;
	char			*tmp_xpm;
	char			*tmp2_xpm;
	char			*tmp3_xpm;
	char			*tmp4_xpm;
	char			*tmp_sprite;
	int				bpp;
	int				size;
	int				bpp_xpm;
	int				size_xpm;
	int				endian_xpm;
	int				endian;
	int				bpp2_xpm;
	int				bpp3_xpm;
	int				bpp4_xpm;
	int				size2_xpm;
	int				size3_xpm;
	int				size4_xpm;
	int				endian2_xpm;
	int				endian3_xpm;
	int				endian4_xpm;
	int				endian_sprite;
	int				size_sprite;
	int				height_sprite;
	int				width_sprite;
	int				bpp_sprite;
	double			angle_sprite;
	double			dist_sprite;
	unsigned int	px;
	unsigned int	py;
	double			pa;
	double			pdx;
	double			pdy;
	double			disth;
	double			distv;
	double			disthh;
	double			distvv;
	double			disthhh;
	double			distvvv;
	double			disthhhh;
	double			distvvvv;
	int				xi;
	int				yi;
	int				x;
	int				y;
	int				inters;
	int				tmp_x;
	int				tmp_y;
	int				modeg;
	int				modeesc;
	int				modeb;
	int				moded;
	int				modeh;
	int				modefg;
	int				modefd;
	int				largeur;
	int				longeur;
	double			fov_angle;
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	char			**map;
	int				r_c;
	int				g_c;
	int				b_c;
	int				r_f;
	int				g_f;
	int				b_f;
	int				ligne;
	int				col;
	int				jj;
	int				ii;
	int				i;
	double			projection;
	unsigned int	playercount;

}			t_fenetre;

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				is_newline(char *str, char c);
char			*creat_line(char *str, char *buffer);
int				get_rest(char **line, char *str);
int				get_next_line(int fd, char **line);
int				count_word(const char *str, char c);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				ft_strcmp(char *s1, char *s2);
int				check_path_north(char *str, t_parsing *data);
int				check_path_ceil(char *str, t_parsing *data);
int				check_path_floor(char *str, t_parsing *data);
int				size_of_tab(char **str);
int				check_element(char *str);
int				check_map(char **map);
int				check_number_of_element(t_parsing *data, char *str);
void			initialisation_variables(t_parsing *data);
int				premier_parsing(char **argv, t_parsing *data);
int				deuxieme_parsing(t_parsing *data, char **argv);
void			initialisation_of_variables(t_fenetre *d, t_parsing *data);
void			give_position_of_player(t_fenetre *d);
int				troisieme_parsing(t_parsing *data, char **argv);
int				cub_file_check(char *str);
void			my_mlx_pixel_put(t_fenetre *d, int x, int y, int color);
double			check_angle(double angle);
unsigned int	give_color_texture_down_left(t_fenetre *d,
					int x, int y, double angle);
unsigned int	give_color_texture_down_right(t_fenetre *d,
					int x, int y, double angle);
unsigned int	give_color_texture_up_left(t_fenetre *d,
					int x, int y, double angle);
void			give_line_coordd(t_fenetre *d, double angle);
void			give_vert_coord(t_fenetre *d, double angle);
void			give_line_coord(t_fenetre *d, double angle);
unsigned int	give_color_texture(t_fenetre *d,
					int x, int y, double angle);
unsigned int	give_color_texture_up_right(t_fenetre *d,
					int x, int y, double angle);
void			mouvement_up(t_fenetre *d);
void			mouvement_down(t_fenetre *d);
void			mouvement_left(t_fenetre *d);
void			mouvement_right(t_fenetre *d);
void			rotation_left(t_fenetre *d);
void			rotation_right(t_fenetre *d);
int				kill_the_windows(t_fenetre *d);
int				key_press(int keycode, t_fenetre *s);
int				key_release(int keycode, t_fenetre *s);
int				all_mouvement(t_fenetre *d);
double			distance_line_intersection(t_fenetre *s, double angle);
double			distance_down_right(t_fenetre *s, double angle);
double			distance_down_left(t_fenetre *s, double angle);
double			distance_up_left(t_fenetre *s, double angle);
double			distance_up_right(t_fenetre *s, double angle);
double			distance_line_intersectionn(t_fenetre *s, double angle);
double			distance_vertical_intersection(t_fenetre *s, double angle);
double			distance_vertical_intersectionn(t_fenetre *s, double angle);
double			distance_vertical_intersectionnn(t_fenetre *s, double angle);
double			ray_draw(t_fenetre *s, double angle);
int				create_rgb(int r, int g, int b);
void			drawing_wall_right_fov(t_fenetre *s,
					int x, int y, double wall_height);
void			drawing_ceil_right_fov(t_fenetre *s, int x, int y);
void			drawing_floor_right_fov(t_fenetre *s, int x, int y);
void			draw_right_fov(t_fenetre *s);
void			draw_left_fov(t_fenetre *s);
void			drawing_wall_left_fov(t_fenetre *s,
					int x, int y, double wall_height);
void			drawing_floor_left_fov(t_fenetre *s, int x, int y);
void			drawing_ceil_left_fov(t_fenetre *s, int x, int y);
void			give_vert_coordddd(t_fenetre *d, double angle);
void			give_line_coordddd(t_fenetre *d, double angle);
void			give_vert_coorddd(t_fenetre *d, double angle);
void			give_line_coorddd(t_fenetre *d, double angle);
void			give_vert_coordd(t_fenetre *d, double angle);
char			*free_str(char *str);
int				check_path(char *str, t_parsing *data);
int				check_zero(char **map, int i, int j);
void			initialisation_of_variabless(t_fenetre *d, t_parsing *data);
int				free_tab(char *s1, char *s2, char **s3);
void			parsing_utils2(t_parsing *data, char **second_tab);
int				free_ta(char *s1, char *s2, char *s3, char **s4);
void			parsing_utils(t_parsing *data, char **second_tab);
void			give_len_of_line(t_parsing *data);
int				troisieme_parsingg(t_parsing *data, int i, int y);
int				is_all_num(char **sec_tab);
int				is_num(char *str);

#endif