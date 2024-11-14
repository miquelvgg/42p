/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:00:30 by mvives-s          #+#    #+#             */
/*   Updated: 2024/10/06 12:00:41 by mvives-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	n_elem = ft_lstnew(f(lst->content));
	if (n_elem == NULL)
		return (NULL);
	n_lst = n_elem;
	lst = lst->next;
	while (lst != NULL)
	{
		n_elem = ft_lstnew(f(lst->content));
		if (n_elem == NULL)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&n_lst, n_elem);
	}
	return (n_lst);
}
