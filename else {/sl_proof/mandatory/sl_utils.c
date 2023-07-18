/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:26:16 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 15:38:26 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	write (2, "\33[31mERROR\n", 12);
	write (2, str, ft_strlen(str));
	write (2, "\33[00m", 6);
	exit (1);
}

int	ft_close_win(t_list *content)
{
	int	i;

	i = 0;
	while (content->map[i])
	{
		free(content->map[i++]);
	}
	free(content->map);
	exit (1);
	return (0);
}

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
