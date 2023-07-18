/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_making.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:05:16 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/20 20:40:20 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_still(char x, t_list *content)
{
	int	i;
	int	r;
	int	c;

	c = 0;
	r = 0;
	i = 0;
	while (content->map[r])
	{
		while (content->map[r][c])
		{
			if (content->map[r][c] == x)
				i++;
			c++;
		}
		c = 0;
		r++;
	}
	return (i);
}

void	maper_one(t_list *content, int m, int k)
{
	if (content->map[k][m] == '1')
		mlx_put_image_to_window(content->mlx_ptr,
			content->win_ptr, content->wall, m * 64, k * 64);
	if (content->map[k][m] == 'C')
		mlx_put_image_to_window(content->mlx_ptr,
			content->win_ptr, content->jellyfish, m * 64, k * 64);
	if (content->map[k][m] == 'E')
	{
		mlx_put_image_to_window(content->mlx_ptr,
			content->win_ptr, content->home, m * 64, k * 64);
		if (ft_still('C', content) == 0)
		{
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->water, m * 64, k * 64);
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->safe, m * 64, k * 64);
		}
	}
}

void	maper_two(t_list *content, int m, int k)
{
	if (content->map[k][m] == 'P')
	{
		if (content->pos == 1)
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->bobright, m * 64, k * 64);
		if (content->pos == -1)
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->bobleft, m * 64, k * 64);
		if (content -> pos == 2)
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->bob_up, m * 64, k * 64);
		if (content -> pos == -2)
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->bob_down, m * 64, k * 64);
	}
}

void	make_map(t_list *content)
{
	int		m;
	int		k;

	k = 0;
	mlx_clear_window(content->mlx_ptr, content->win_ptr);
	while (content->map[k])
	{
		m = 0;
		while (content->map[k][m])
		{
			mlx_put_image_to_window(content->mlx_ptr,
				content->win_ptr, content->water, m * 64, k * 64);
			maper_one(content, m, k);
			maper_two(content, m, k);
			m++;
		}
		k++;
	}
}
