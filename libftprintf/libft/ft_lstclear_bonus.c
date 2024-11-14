/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:59:54 by mvives-s          #+#    #+#             */
/*   Updated: 2024/10/06 11:59:56 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*prev;

	if (lst != NULL && *lst != NULL && del != NULL)
	{
		prev = (t_list *)*lst;
		while (prev != NULL)
		{
			tmp = prev->next;
			ft_lstdelone(prev, del);
			prev = tmp;
		}
		*lst = NULL;
	}
}
