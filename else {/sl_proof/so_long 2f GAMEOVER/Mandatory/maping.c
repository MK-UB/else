/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:05:16 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/20 12:20:40 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(char **str)
{
	int i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

int	ft_still(char x, t_list *content)
{
	int i;
	int r;
    int c;
    c = 0;
    r = 0;
	i = 0;
    while(content->map[r])
    {
        while(content->map[r][c])
        {
            if(content->map[r][c] == x)
            {
				i++;
            }
            c++;
        }
        c=0;
        r++;
	}
	return(i);
}
	
void setup_imgs(t_list *content)
{
	int y;
    int width;
	int height;

	if(!content->bob_down || !content->bob_up || !content->bobleft 
		|| !content->bobright || !content->home || !content->jellyfish 
			|| !content->safe || !content->wall || !content->water)
				ft_error("missing xpm");
	width = ft_strlen(content->map[0]) * 64;
	height = map_height(content->map) * 64;
    content->win_ptr = mlx_new_window(content->mlx_ptr, width, height, "so_long");
    content->wall = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/wall.xpm", &y, &y);
    content->water = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/water.xpm", &y, &y);
    content->bobright = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/bobright.xpm", &y, &y);
    content->bobleft = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/bobleft.xpm", &y, &y);
    content->bob_up = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/bob_up.xpm", &y, &y);
    content->bob_down = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/bob_down.xpm", &y, &y);
	content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/jellyfish.xpm", &y, &y);
    content->home = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/home.xpm", &y, &y);
	content->safe = mlx_xpm_file_to_image(content->mlx_ptr, "./textures/safe.xpm", &y, &y);
}

void	maper(t_list *content , int m, int k)
{
	if(content->map[k][m] == 'C')
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->jellyfish, m * 64, k * 64);			
	if(content->map[k][m] == 'P')
	{
		if (content->pos == 1)
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobright, m * 64, k * 64);
		if (content->pos == -1)
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobleft, m * 64, k * 64);
		if (content -> pos == 2)
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bob_up, m * 64, k * 64);
		if (content -> pos == -2)
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bob_down, m * 64, k * 64);		
	}
	if(content->map[k][m] == 'E')
    {
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->home, m * 64, k * 64);
		if(ft_still('C', content) == 0)
		{
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->water, m * 64, k * 64);
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->safe, m * 64, k * 64);
		}
	}
}

void    make_map(t_list *content)
{
	int m;
	int k; 

	k = 0;
 	while(content->map[k])
	{
		m = 0;
		while (content->map[k][m])
		{
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->water, m * 64, k * 64);
			if(content->map[k][m] == '1')
				mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->wall, m * 64, k * 64);
			maper(content, m, k);
			m++;
        }
        k++;
	}
}