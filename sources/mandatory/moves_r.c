/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:24 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 06:47:47 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	move_r(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	last = ps_lstlast(first);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

int	ra(t_node **stack, int p)
{
	if (move_r(stack) < 0)
		return (-1);
	if (p)
		ft_printf("ra\n");
	return (0);
}

int	rb(t_node **stack, int p)
{
	if (move_r(stack) < 0)
		return (-1);
	if (p)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_node **stack_a, t_node **stack_b, int p)
{
	if ((ps_lstsize(*stack_a) < 2) \
	|| (ps_lstsize(*stack_b) < 2))
		return (-1);
	move_r(stack_a);
	move_r(stack_b);
	if (p)
		ft_printf("rr\n");
	return (0);
}

void	ps_movetotop(t_node **stack, int count)
{
	int		len;
	t_node	*node;

	if (!count)
		return ;
	node = *stack;
	len = ps_lstsize(node);
	if (count <= len / 2)
	{
		while (!count--)
			ra(stack, 1);
	}
	else
	{
		while (!len--)
			rra(stack, 1);
	}
}
