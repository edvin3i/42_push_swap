/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:14 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 15:19:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	move_p(t_node **dst_st, t_node **src_st)
{
	t_node	*tmp;
	t_node	*src;
	t_node	*dst;

	if (!ps_lstsize(*src_st))
		return (-1);
	src = *src_st;
	dst = *dst_st;
	tmp = src;
	src = src->next;
	*src_st = src;
	if (!dst)
	{
		dst = tmp;
		dst->next = NULL;
		*dst_st = dst;
	}
	else
	{
		tmp->next = dst;
		*dst_st = tmp;
	}
	return (0);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	if (move_p(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_node **stack_a, t_node **stack_b)
{
	if (move_p(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
