/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:45:30 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 15:36:41 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mini_main(t_list *content)
{
	setup_imgs(content);
	make_map(content);
	make_matrice(content);
}

int	main(int ac, char **av)
{
	int		xp;
	int		yp;
	t_list	content;

	if (ac != 2)
		ft_error("too few arguments!");
	content.path = av[1];
	ft_check_extension(&content);
	remove_newline(&content, av[1]);
	content.mlx_ptr = mlx_init();
	if (!content.mlx_ptr)
		ft_error("mlx failed to init");
	content.pos = 1;
	mini_main(&content);
	find_player(&content, &xp, &yp);
	ft_flood_fill(&content, xp, yp);
	if (!find_and_act(&content))
		return (write(2, "\33[31mERROR\nNon Valid map!\33[00m\n", 26), 0);
	mlx_hook(content.win_ptr, 2, 0, key_move, &content);
	mlx_hook(content.win_ptr, 17, 0, ft_close_win, &content);
	mlx_loop(content.mlx_ptr);
}
