/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:14:17 by melayoub          #+#    #+#             */
/*   Updated: 2023/02/20 16:46:29 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	count_word(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
		i++;
		if (str[i] != c && str[i])
		count += 1;
		while (str[i] != c && str[i])
		i++;
	}
	return (count);
}

static void	free_all(char **str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		while (str[i] != '\0')
		{
			free (str[i]);
			i++;
		}
		free (str);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	start;
	size_t	end;
	int		i;

	if (!s)
		return (0);
	str = (char **)malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	start = 0;
	i = 0;
	while (i < count_word((char *)s, c))
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		str[i++] = ft_substr((char *)s, start, end - start);
		free_all(str);
		start = end;
	}
	*(str + i) = NULL;
	return (str);
}

static int	ft_count(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	count += 1;
	while (nb != 0)
	{
	count++;
	nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = ft_count(nb);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	if (nb < 0)
	{
	str[0] = '-';
	nb *= -1;
	}
	str[i] = '\0';
	i -= 1;
	if (nb == 0)
		str[0] = 48;
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
