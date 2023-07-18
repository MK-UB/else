/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:35:52 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/20 16:08:57 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	found_newline(char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*update_it(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	new = ft_substr(s, i + 1, ft_strlen(s) - i + 1);
	free(s);
	return (new);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (*src != '\0')
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *s, unsigned int start, size_t	len)
{
	char	*sub;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc (sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
