/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:39:09 by mvives-s          #+#    #+#             */
/*   Updated: 2024/09/24 18:39:52 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)s;
	while ((p[i] != (char)c) && (p[i] != '\0'))
		i++;
	if ((p[i] == '\0') && ((char)c != 0))
		return (NULL);
	else
		return (p + i);
}
