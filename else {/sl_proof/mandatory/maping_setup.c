/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:30:37 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 14:15:57 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	setup_xpm(t_list *content)
{
	int	y;

	content->wall
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/wall.xpm", &y, &y);
	content->water
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/water.xpm", &y, &y);
	content->bobright
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/bobright.xpm", &y, &y);
	content->bobleft
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/bobleft.xpm", &y, &y);
	content->bob_up
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/bob_up.xpm", &y, &y);
	content->bob_down
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/bob_down.xpm", &y, &y);
	content->jellyfish
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/jellyfish.xpm", &y, &y);
	content->home
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/home.xpm", &y, &y);
	content->safe
		= mlx_xpm_file_to_image(content->mlx_ptr, "./xp/safe.xpm", &y, &y);
}

void	setup_imgs(t_list *content)
{
	int	width;
	int	height;

	width = ft_strlen(content->map[0]) * 64;
	height = map_height(content->map) * 64;
	content->win_ptr
		= mlx_new_window(content->mlx_ptr, width, height, "so_long");
	if (!content->win_ptr)
		ft_error("mlx window failed");
	setup_xpm(content);
	if (!content->bob_down || !content->bob_up || !content->bobleft
		|| !content->bobright || !content->home || !content->jellyfish
		|| !content->safe || !content->wall || !content->water)
		ft_error("missing xpm");
}
