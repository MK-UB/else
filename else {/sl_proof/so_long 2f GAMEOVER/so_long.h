#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>

typedef struct	s_list
{
	int		x;
	int 	y;
	int		i;
	int		j;
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
    char    **matrice;

}				t_list;

void	ft_check_extension(t_list *content);
void	ft_close(char **str);
void	unisized_map(char **str);
void	rectangular_map(char **map);
void	check_vertical(char **str);
void	check_horizental(char **str);
void	check_components(char**str);
void	foreign_material(char **str);
void	remove_newline(t_list *content,char *av);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
int		found_newline(char *stash);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*get_linee(char *src);
char	*ft_substr(char *s, unsigned int start, size_t	len);
char	*update_it(char *s);
int		ft_run_and_alloc(char *str);
int		ft_close_win(t_list *content);
void	check_horizental(char **str);
void	check_vertical(char **str);
void	ft_parssing(t_list *content);
void	ft_error(char *str);
int		key_move(int key, t_list *content);
void	swap(char *a, char *b, t_list  *content);
void	make_map(t_list *content);
void	player_pos(t_list *content);
int		ft_still(char x, t_list *content);
void 	setup_imgs(t_list *content);
void    swap(char *a, char *b, t_list  *content);
void	ft_putnbr(int nb);
void    ft_putchar(char c);
void    make_matrice(t_list *content);
void	ft_flood_fill(t_list *content, int xp, int yp);
int     find_and_act(t_list *content);
void	find_player(t_list *content, int *xp, int *yp);
int     map_height(char **str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif
