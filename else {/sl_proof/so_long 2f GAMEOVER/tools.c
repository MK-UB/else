/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:24:08 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/13 18:30:05 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void    ft_error(char *str)
// {
//     write (2, "ERROR:", 6);
//     write (2, "\n", 1);
//     write (2, str, ft_strlen(str));
//     exit (1);

// }

void	ft_close(char **str)
{
	free(str);
	printf("map error");
	exit(1);
}
