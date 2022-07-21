/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_structs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:00:34 by kshim             #+#    #+#             */
/*   Updated: 2022/07/21 15:20:27 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include <stdlib.h>

t_ps_struct_list	*ft_ps_set_struct_list(t_detower *stack_a,
		t_detower *stack_b, t_detower *oper_list)
{
	t_ps_struct_list	*new_list;

	new_list = (t_ps_struct_list *)malloc(sizeof(t_ps_struct_list));
	if (new_list == 0)
		return (0);
	new_list -> st_a = stack_a;
	new_list -> st_b = stack_b;
	new_list -> list = oper_list;
	return (new_list);
}
