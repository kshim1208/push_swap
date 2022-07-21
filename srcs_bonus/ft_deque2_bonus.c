/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:30:11 by kshim             #+#    #+#             */
/*   Updated: 2022/07/21 15:20:22 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include <stdlib.h>

void	ft_deque_add_back(t_detower *detower, t_d_list *new_elem)
{
	if (new_elem == 0)
		return ;
	new_elem -> prev = 0;
	new_elem -> next = 0;
	if (detower -> head == 0)
		detower -> head = new_elem;
	else
	{
		detower -> tail -> next = new_elem;
		new_elem -> prev = detower -> tail;
	}
	detower -> tail = new_elem;
	detower -> tail -> next = 0;
	return ;
}

void	ft_deque_add_front(t_detower *detower, t_d_list *new_elem)
{
	if (new_elem == 0)
		return ;
	new_elem -> prev = 0;
	new_elem -> next = 0;
	if (detower -> head == 0)
	{
		detower -> head = new_elem;
		detower -> tail = new_elem;
	}
	else
	{
		new_elem -> next = detower -> head;
		detower -> head -> prev = new_elem;
		detower -> head = new_elem;
	}
	detower -> head -> prev = 0;
	return ;
}

void	ft_deque_del_back(t_detower *detower, int free_node)
{
	t_d_list	*tmp;

	tmp = detower -> tail;
	if (detower -> tail == 0)
		return ;
	if (detower -> tail -> prev == 0)
	{
		detower -> head = 0;
		detower -> tail = 0;
	}
	else
	{
		detower -> tail -> prev -> next = 0;
		detower -> tail = detower -> tail -> prev;
	}
	tmp -> next = 0;
	tmp -> prev = 0;
	if (free_node == 1)
		ft_d_lstdelone(tmp, (&ft_ps_content_del));
	return ;
}

void	ft_deque_del_front(t_detower *detower, int free_node)
{
	t_d_list	*tmp;

	tmp = detower -> head;
	if (detower -> head == 0)
		return ;
	if (detower -> head -> next == 0)
	{
		detower -> head = 0;
		detower -> tail = 0;
	}
	else
	{
		detower -> head -> next -> prev = 0;
		detower -> head = detower -> head -> next;
	}
	tmp -> next = 0;
	tmp -> prev = 0;
	if (free_node == 1)
		ft_d_lstdelone(tmp, &ft_ps_content_del);
	return ;
}

void	ft_d_lstdelone(t_d_list *lst, void (*del)(void *))
{
	if (lst -> content != 0 && del != 0)
		del(lst -> content);
	if (lst != 0)
		free(lst);
	return ;
}
