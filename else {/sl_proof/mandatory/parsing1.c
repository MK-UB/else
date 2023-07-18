/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:46 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 14:34:13 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_extension(t_list *content)
{
	int	i;

	if (content->path)
	{
		i = 0;
		while (content->path[i])
		{
			if (content->path[i] == '.'
				&& content->path[i + 1] == 'b'
				&& content->path[i + 2] == 'e'
				&& content->path[i + 3] == 'r'
				&& content->path[i + 4] == '\0')
				return ;
			i++;
		}
		ft_error("non '.ber' extenssion");
	}
}

void	foreign_material(char **str)
{
	int	j;
	int	i;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != '1' && str[j][i] != '0'
				&& str[j][i] != 'P' && str[j][i] != 'C'
				&& str[j][i] != 'E')
				ft_error("foreing material");
			i++;
		}
		j++;
	}
}

static int	there_is(char **str, char x)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j][i])
		{
			if (str[j][i] == x)
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

void	check_components(char **str)
{
	if (there_is(str, 'P') != 1
		|| there_is(str, 'C') < 1
		|| there_is(str, 'E') != 1)
		ft_error("MISSING / EXTRA COMPONENTS");
}
