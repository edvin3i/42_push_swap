/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:39 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 06:46:33 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	move_s(t_node **stack)
{
	int		tmp_num;
	int		tmp_index;
	t_node	*node;
	t_node	*next;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	next = node->next;
	if (!node && !next)
		error();
	tmp_num = node->num;
	tmp_index = node->index;
	node->num = next->num;
	node->index = next->index;
	next->num = tmp_num;
	next->index = tmp_index;
	return (0);
}

int	sa(t_node **stack, int p)
{
	if (move_s(stack) < 0)
		return (-1);
	if (p)
		ft_printf("sa\n");
	return (0);
}

int	sb(t_node **stack, int p)
{
	if (move_s(stack) < 0)
		return (-1);
	if (p)
		ft_printf("sb\n");
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b, int p)
{
	if ((ps_lstsize(*stack_a) < 2) \
	|| (ps_lstsize(*stack_b) < 2))
		return (-1);
	move_s(stack_a);
	move_s(stack_b);
	if (p)
		ft_printf("ss\n");
	return (0);
}
