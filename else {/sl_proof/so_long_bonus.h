/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:29 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/22 12:57:11 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
# include <unistd.h>

typedef struct s_list
{
	int		h;
	int		v;
	int		x;
	int		y;
	int		i;
	int		j;
	void	*plancton;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*water;
	void	*bobright;
	void	*bobleft;
	void	*bob_down;
	void	*bob_up;
	void	*jellyfish;
	void	*home;
	void	*safe;
	int		column;
	int		row;
	int		c;
	int		pos;
	char	**map;
	char	*path;
	int		steps;
	char	**matrice;
}				t_list;

void	ft_check_extension(t_list *content);
void	ft_parssing(t_list *content);
void	ft_close(char **str);
void	unisized_map(char **str);
void	rectangular_map(char **str);
void	check_vertical(char **str);
void	check_horizental(char **str);
void	check_components(char**str);
void	foreign_material(char **str);
void	remove_newline(t_list *content, char *av);
void	swap(char *a, char *b, t_list *content);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
int		found_newline(char *stash);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*get_linee(char *src);
char	*ft_substr(char *s, unsigned int start, size_t	len);
char	*update_it(char *s);
int		ft_close_win(t_list *content);
void	ft_error(char *str);
int		key_move(int key, t_list *content);
void	swap(char *a, char *b, t_list *content);
void	make_map(t_list *content);
void	player_pos(t_list *content);
int		ft_still(char x, t_list *content);
void	find_player(t_list *content, int *xp, int *yp);
void	make_matrice(t_list *content);
void	ft_flood_fill(t_list *content, int xp, int yp);
int		find_and_act(t_list *content);
int		map_height(char **str);
void	setup_imgs(t_list *content);
int		render_next_frame(t_list *content);
void	enemy_move(t_list *content);
char	*ft_itoa(int n);
void	mini_main(t_list *content);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif