/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:39:09 by mvives-s          #+#    #+#             */
/*   Updated: 2024/10/10 18:04:37 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lenstr(char const *s1, char const *s2, size_t *l1, size_t *l2)
{
	*l1 = 0;
	while (s1[*l1] != '\0')
		(*l1)++;
	*l2 = 0;
	while (s2[*l2] != '\0')
		(*l2)++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		l1;
	size_t		l2;
	char		*p_res;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	ft_lenstr(s1, s2, &l1, &l2);
	p_res = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (p_res == NULL)
		return (NULL);
	i = 0;
	while (i < (l1 + l2))
	{
		if (i < l1)
			p_res[i] = s1[i];
		else
			p_res[i] = s2[i - l1];
		i++;
	}
	p_res[i] = '\0';
	return (p_res);
}
