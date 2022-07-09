/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:16:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 20:17:07 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	sort_radix(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		len_a;
	int		bmax;
	t_node	*node;

	i = 0;
	node = *stack_a;
	len_a = ps_lstsize(node);
	bmax = ps_index_bmax(stack_a);
	while (i < bmax)
	{
		j = 0;
		while (j++ < len_a)
		{
			node = *stack_a;
			if (((node->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ps_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
