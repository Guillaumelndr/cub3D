/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 14:53:47 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 14:48:17 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		verif(char *tmp, char c)
{
	int		i;

	i = -1;
	while (tmp[++i])
		if (tmp[i] == c)
			return (1);
	return (0);
}

static char		*trim_s(char *s1, char *set)
{
	int		i;

	i = 0;
	while (verif(set, s1[i]) == 1 && s1[i])
		i++;
	return (s1 + i);
}

static int		trim_e(char *s1, char *set)
{
	int		i;

	i = ft_strlen(s1) - 1;
	while (verif(set, s1[i]) == 1)
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	if (!s1)
		return (ft_calloc(1, 1));
	else if (!set)
		return (ft_strdup(s1));
	s1 = trim_s((char *)s1, (char *)set);
	if (!*s1)
		return (ft_calloc(1, 1));
	len = trim_e((char *)s1, (char *)set);
	if (!(new = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (i != len)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
