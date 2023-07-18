/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:14:31 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 15:33:23 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_pos(t_list *content)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (content->map[r])
	{
		while (content->map[r][c])
		{
			if (content->map[r][c] == 'P')
			{
				content->row = r;
				content->column = c;
				return ;
			}
			c++;
		}
		c = 0;
		r++;
	}
}

void	swap(char *a, char *b, t_list *content)
{
	char	c;

	if (*b == 'C')
		*b = '0';
	if (*b == 'N')
	{
		*a = '0';
		write (1, "\33[41mGAME OVER!\33[00m\n", 22);
		exit(0);
	}
	if (*b == 'E' && ft_still('C', content) == 0)
	{
		*a = '0';
		write (1, "\33[42mYOU WIN!\33[00m\n", 20);
		exit (0);
	}
	else if (*b == 'E' && ft_still('C', content) > 0)
	{
		return ;
	}
	c = *a;
	*a = *b;
	*b = c;
}

int	move_left_or_right(int key, t_list *content)
{
	if (key == 2 && (content->map[content->row][content->column + 1] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 0 && (content->map[content->row][content->column - 1] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 2 && content->map[content->row][content->column + 1] != '1')
	{
		content->pos = 1;
		swap(&content->map[content->row][content->column],
			&content->map[content->row][content->column +1], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bobright, 64, 64);
			content->steps++;
	}
	if (key == 0 && content->map[content->row][content->column - 1] != '1')
	{
		content->pos = -1;
		swap(&content->map[content->row][content->column],
			&content->map[content->row][content->column - 1], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bobleft, 64, 64);
			content->steps++;
	}
	return (0);
}

int	move_up_or_down(int key, t_list *content)
{
	if (key == 13 && (content->map[content->row - 1][content->column] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 1 && (content->map[content->row + 1][content->column] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 13 && content->map[content->row - 1][content->column] != '1')
	{
		content->pos = 2;
		swap(&content->map[content->row][content->column],
			&content->map[content->row - 1][content->column], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bob_up, 64, 64);
			content->steps++;
	}
	if (key == 1 && content->map[content->row + 1][content->column] != '1')
	{
		content->pos = -2;
		swap(&content->map[content->row][content->column],
			&content->map[content->row + 1][content->column], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bob_down, 64, 64);
			content->steps++;
	}
	return (0);
}

int	key_move(int key, t_list *content)
{
	if (key == 53)
		ft_close_win(content);
	player_pos(content);
	move_left_or_right(key, content);
	move_up_or_down(key, content);
	make_map(content);
	return (0);
}
