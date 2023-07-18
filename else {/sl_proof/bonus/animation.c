/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:28:28 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 15:30:50 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	jelly_one(t_list *content, int i)
{
	if (i == 0)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly0.xpm", &content->h, &content->v);
	if (i == 5)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly1.xpm", &content->h, &content->v);
	if (i == 10)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly2.xpm", &content->h, &content->v);
	if (i == 15)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly3.xpm", &content->h, &content->v);
	if (!content->jellyfish)
		ft_error("missing xpm (annimation)");
}

void	jelly_two(t_list *content, int i)
{
	if (i == 20)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly4.xpm", &content->h, &content->v);
	if (i == 25)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly5.xpm", &content->h, &content->v);
	if (i == 30)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly6.xpm", &content->h, &content->v);
	if (i == 35)
		content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr,
				"./xp/jelly7.xpm", &content->h, &content->v);
	if (!content->jellyfish)
		ft_error("missing xpm (annimation)");
}

static void	the_move(t_list *content)
{
	if (content->map[content->i + content->x][content->j + content->y] == 'P')
	{
		write (1, "\33[41mGAME OVER!\33[00m\n", 22);
		exit(0);
	}
	if (content->map[content->i + content->x][content->j + content->y] == '0')
	{
		content->map[content->i][content->j] = '0';
		content->i = content->i + content->x;
		content->j = content->j + content->y;
		content->map[content->i][content->j] = 'N';
		make_map(content);
	}
}

void	enemy_move(t_list *content)
{
	int	res;

	content->x = 0;
	content->y = 0;
	content->i = 0;
	while (content->map[content->i])
	{
		content->j = 0;
		while (content->map[content->i][content->j])
		{
			if (content->map[content->i][content->j] == 'N')
			{
				content->x = rand() % 3 - 1;
				content->y = rand() % 3 - 1;
				res = rand() % 2;
				if (res)
					content->x = 0;
				else
					content->y = 0;
				the_move(content);
			}
			content->j++;
		}
		content->i++;
	}
}

int	render_next_frame(t_list *content)
{
	static int	i = 0;
	static int	j = 0;

	if (i == 40)
		i = 0;
	jelly_one(content, i);
	jelly_two(content, i);
	j++;
	i++;
	if (j == 15)
	{
		enemy_move(content);
		j = 0;
	}
	make_map(content);
	return (0);
}
