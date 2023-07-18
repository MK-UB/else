/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:46 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/18 17:09:29 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_error(char *str)
{
    write (2, "ERROR:", 6);
    write (2, "\n", 1);
    write (2, str, ft_strlen(str));
    exit (1);
}

void ft_check_extension(t_list *content)
{
	int i;
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
	int j;
	int i;
	j = 0;
	while (str[j])
	{
		i = 0;
		while(str[j][i])
		{
			if(str[j][i] != '1' && str[j][i] != '0'
				&& str[j][i] != 'P' && str[j][i] != 'C'
					&& str[j][i] != 'E')
						ft_error("foreing material");
			i++;
		}
		j++;
	}
}

static int there_is(char **str, char x)
{
	int y = 0;
	int i = 0;
	int j = 0;
	while(str[j])
	{
		while(str[j][i])
		{
			if (str[j][i] == x)
				y++;
			i++;
		}
		i = 0;
		j++;
	}
	return (y);
}


void	check_components(char **str)
{

		if(there_is(str, 'P') != 1 
			|| there_is(str, 'C') < 1 
				|| there_is(str, 'E') != 1)
					ft_error("MISSING / EXTRA COMPONENTS");
}