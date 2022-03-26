/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:15:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/26 09:15:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

t_node		*init_list(int index)
{
	t_node	*list;
	list = (t_node *) malloc(sizeof (t_node));
	if (!list)
		exit(1);
	list->index = index;
	list->flag = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_common	*init_param(char **nums)
{
	t_common *common;
	int len_a;

	common = NULL;
	len_a = 0;
	while (nums)
		len_a++;
	common = (t_common *) malloc(sizeof (t_common));
	if (!common)
		exit(1);
	common->index_min = 1;
	common->len_a = len_a;
	common->len_b = 0;
	common->mid = 0;
	common->stack_a = NULL;
	common->stack_b = NULL;
	return (common);
}
