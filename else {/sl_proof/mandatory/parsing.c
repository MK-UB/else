/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:28:12 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/22 12:51:11 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	unisized_map(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (ft_strlen(str[j]) != ft_strlen(str[0]))
			ft_error("not unisized");
		j++;
	}
}

void	rectangular_map(char **str)
{
	int	i;
	int	j;

	i = ft_strlen(*str);
	j = 0;
	while (str[j])
		j++;
	if (j == i)
		ft_error("technically not a rectangle");
}

void	check_horizental(char **str)
{
	int	j;
	int	i;

	j = map_height(str) - 1;
	i = 0;
	while (str[j][i])
	{
		if (str[0][i] != '1' || str[j][i] != '1')
			ft_error("missing perimeter walls");
		i++;
	}
}

void	check_vertical(char **str)
{
	int	j;
	int	i;

	j = 0;
	i = ft_strlen(str[j]) - 1;
	while (str[j])
	{
		if (str[j][0] != '1' || str[j][i] != '1')
			ft_error("missing perimeter walls");
		j++;
	}
}
