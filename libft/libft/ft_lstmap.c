/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:50 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:50 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*add_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		add_lst = ft_lstnew(f(lst->content));
		if (add_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}	
		ft_lstadd_back(&new_lst, add_lst);
		lst = lst->next;
	}
	return (new_lst);
}
