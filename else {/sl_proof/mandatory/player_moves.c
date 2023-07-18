/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:39:50 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 14:09:02 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	swap(char *a, char *b, t_list *content)
{
	char	c;

	if (*b == 'C')
		*b = '0';
	if (*b == 'E' && ft_still('C', content) == 0)
	{
		*a = '0';
		write(1, "\33[42mYOU WIN!\33[00m\n", 20);
		exit(0);
	}
	else if (*b == 'E' && ft_still('C', content) > 0)
	{
		return ;
	}
	c = *a;
	*a = *b;
	*b = c;
}

int	what_if_e(int key, t_list *content)
{
	if (key == 2 && (content->map[content->row][content->column + 1] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 0 && (content->map[content->row][content->column - 1] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 13 && (content->map[content->row - 1][content->column] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	if (key == 1 && (content->map[content->row + 1][content->column] == 'E'
		&& ft_still('C', content) != 0))
		return (0);
	return (1);
}

int	move_left_or_right(int key, t_list *content)
{	
	if (!what_if_e(key, content))
		return (0);
	if (key == 2 && content->map[content->row][content->column + 1] != '1')
	{
		content->pos = 1;
		swap(&content->map[content->row][content->column],
			&content->map[content->row][content->column + 1], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bobright, 64, 64);
		content->steps++;
		ft_putnbr(content->steps);
		ft_putchar('\n');
	}
	if (key == 0 && content->map[content->row][content->column - 1] != '1')
	{
		content->pos = -1;
		swap(&content->map[content->row][content->column],
			&content->map[content->row][content->column - 1], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bobleft, 64, 64);
		content->steps++;
		ft_putnbr(content->steps);
		ft_putchar('\n');
	}
	return (0);
}

int	move_up_or_down(int key, t_list *content)
{
	if (!what_if_e(key, content))
		return (0);
	if (key == 13 && content->map[content->row - 1][content->column] != '1')
	{
		content->pos = 2;
		swap(&content->map[content->row][content->column],
			&content->map[content->row - 1][content->column], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bob_up, 64, 64);
		content->steps++;
		ft_putnbr(content->steps);
		ft_putchar('\n');
	}
	if (key == 1 && content->map[content->row + 1][content->column] != '1')
	{
		content->pos = -2;
		swap(&content->map[content->row][content->column],
			&content->map[content->row + 1][content->column], content);
		mlx_put_image_to_window(content->mlx_ptr, content->win_ptr,
			content->bob_down, 64, 64);
		content->steps++;
		ft_putnbr(content->steps);
		ft_putchar('\n');
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
