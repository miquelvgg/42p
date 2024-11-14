/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:57:33 by mvives-s          #+#    #+#             */
/*   Updated: 2024/10/06 11:57:43 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a_list;

	a_list = (t_list *)malloc(sizeof(t_list));
	if (a_list == NULL)
		return (NULL);
	a_list->content = content;
	a_list->next = NULL;
	return (a_list);
}
