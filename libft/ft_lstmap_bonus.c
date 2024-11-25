/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramire2 <jramire2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:29 by jramire2          #+#    #+#             */
/*   Updated: 2024/09/17 15:42:58 by jramire2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_cnt_and_lst(t_list *lst, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	mapped = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		node = ft_lstnew(content);
		if (!node)
		{
			free_cnt_and_lst(mapped, content, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, node);
		lst = lst->next;
	}
	return (mapped);
}
