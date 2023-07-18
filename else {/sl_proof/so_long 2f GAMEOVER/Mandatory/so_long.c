/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:47:05 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/19 12:46:56 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_newline(t_list *content, char *av)
{
    char	*line;
    char	*all_lines;
	int		fd;

    fd = open(av, O_RDONLY);
	if(fd == -1)
	{
		write (1, "MAP NOT FOUND!\n", 15);
		exit(1);
	}
    while(1)
    {
		line = get_next_line(fd);
		if(!line)
			break ;
		all_lines = ft_strjoin(all_lines ,line);
        free(line);
    }
    content->map = ft_split(all_lines, '\n');
    free (all_lines);
    // str[j] = '\0';
}


int ft_close_win(t_list *content)
{
    free(content->map);
    exit(1);
    return (0);
}