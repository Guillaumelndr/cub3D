/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:31:34 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

static int	word(char *str, char sep)
{
	int i;
	int w;

	i = 0;
	w = 0;
	if (!str)
		return (1);
	while (str[i] == sep && str[i])
		i++;
	if (i == (int)ft_strlen(str))
		return (0);
	while (str[i])
	{
		if (str[i] == sep)
		{
			while (str[i] == sep && str[i])
				i++;
			w++;
			if (!str[i])
				return (w);
		}
		i++;
	}
	return (w + 1);
}

static int	len_word(char *str, char c)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str == c && *str)
		str++;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*fillstr(char *dst, char *src, int len, char c)
{
	int		i;

	i = 0;
	if (src)
	{
		while (*src == c && *src)
			src++;
		while (i != len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		w;
	int		len;
	char	*str;

	i = 0;
	str = (char *)s;
	w = word(str, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (w + 1))))
		return (0);
	while (i != w)
	{
		len = len_word(str, c);
		strs[i] = (char *)malloc(sizeof(char) * (len + 1));
		strs[i] = fillstr(strs[i], str, len, c);
		i++;
		while (str && *str == c && *str)
			str++;
		str += len;
	}
	strs[w] = NULL;
	return (strs);
}
