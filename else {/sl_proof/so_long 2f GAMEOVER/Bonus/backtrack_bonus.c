/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:14:59 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/19 21:15:57 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	find_player(t_list *content, int *xp, int *yp)
{
	int y;
	int x;

	y = 0;
	while(content->map[y])
	{
		x = 0;
		while(content->map[y][x])
		{
			if (content->map[y][x] == 'P')
			{
				*xp = x;
				*yp = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void    make_matrice(t_list *content)
{
	int y;
	int x;
	int size;

	y = 0;
	while (content->map[y])
	{
		x = 0;
		while (content->map[y][x])
			x++;
		y++;
	}
	size = x;
	content->matrice = (char **)malloc(sizeof(char *) * y + 1);
	content->matrice[y] = NULL;
	while(--y >= 0)
	{
		x = -1;
		content->matrice[y] = (char *)malloc(size + 1);
		while (++x < size)
			content->matrice[y][x] = '1';
		content->matrice[y][x] = '\0';
	}
}

void	ft_flood_fill(t_list *content, int xp, int yp)
{
    content->matrice[yp][xp] = '0';
	// printf("(%d,%d) = %c\n",xp,yp,content->matrice[yp][xp]);
    if (content->matrice[yp][xp + 1] == '1' && content->map[yp][xp + 1]  != '1' && content->map[yp][xp + 1]  != 'E')
       ft_flood_fill(content, xp + 1, yp);
    if (content->matrice[yp][xp - 1] == '1' && content->map[yp][xp - 1]  != '1' && content->map[yp][xp - 1]  != 'E')
         ft_flood_fill(content, xp - 1, yp);
    if (content->matrice[yp + 1][xp] == '1' && content->map[yp + 1][xp]  != '1' && content->map[yp + 1][xp]  != 'E')
         ft_flood_fill(content, xp , yp +1);
    if (content->matrice[yp - 1][xp] == '1' && content->map[yp - 1][xp]  != '1' && content->map[yp - 1][xp]  != 'E')
         ft_flood_fill(content,xp, yp - 1);
	// printf("mat:%hhd\n", content->matrice[yp][xp]);
}

int	find_and_act(t_list *content)
{
	int y = 0;
	while(content->map[y])
	{
		int x = 0;
		while(content->map[y][x])
		{
			if ((content->map[y][x] == 'C' || content->map[y][x] == 'N') && content->matrice[y][x] == '1')
       			return (0);
			if (content->map[y][x] == 'E' && (content->matrice[y][x + 1] == '1' 
											&& content->matrice[y][x - 1] == '1' 
												&& content->matrice[y + 1][x] == '1' 
													&& content->matrice[y - 1][x] == '1'))
															return(0);
			x++;
		}
		y++;
	}
	return (1);
}