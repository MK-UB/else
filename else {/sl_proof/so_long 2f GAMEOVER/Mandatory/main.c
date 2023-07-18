/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:45:30 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/19 17:06:25 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_parssing(t_list *content)
{
	check_horizental(content->map);
	check_vertical(content->map);
    unisized_map(content->map);
    check_components(content->map);
    foreign_material(content->map);
    rectangular_map(content->map);
}

int main(int ac, char **av)
{
    int xp;
    int yp;
    t_list content;
    
    if (ac != 2)
        ft_error("too few arguments!");
    content.path = av[1];
    ft_check_extension(&content);
    content.mlx_ptr = mlx_init();
       // struct_init(&content);
    content.pos = 1;
    remove_newline(&content, av[1]);
    setup_imgs(&content);
    make_map(&content);
    ft_parssing(&content);
    make_matrice(&content);
    find_player(&content, &xp, &yp);
    // printf("%d_%d\n", xp, yp);
    // printf("%s\n",content.matrice[0]);
    ft_flood_fill(&content, xp, yp);
    if (find_and_act(&content))
        write(1, "\33[94mValid map!!!\33[00m\n", 17);
    else
        return(write(1, "\33[31mNon Valid map!\33[00m\n", 20), 0);
    content.steps = 0;
     mlx_hook(content.win_ptr, 2, 0, key_move, &content);
     mlx_hook(content.win_ptr, 17, 0, ft_close_win, &content);
     mlx_loop(content.mlx_ptr);
}