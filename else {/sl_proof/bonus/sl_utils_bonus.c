/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:27:56 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 15:34:44 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
