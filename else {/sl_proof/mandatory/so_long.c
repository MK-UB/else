/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:47:05 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/24 14:32:31 by melayoub         ###   ########.fr       */
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

static void	ft_extra_line_or_none(char *all_lines)
{
	int	i;

	i = 0;
	if (all_lines == '\0')
		ft_error("empty file");
	while (all_lines[i])
	{
		if (all_lines[i] == '\n' && all_lines[i + 1] == '\0')
			ft_error("extra line");
		i++;
	}
}

void	remove_newline(t_list *content, char *av)
{
	char	*line;
	char	*all_lines;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("map not found");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	ft_extra_line_or_none(all_lines);
	content->map = ft_split(all_lines, '\n');
	ft_parssing(content);
	free (all_lines);
}
