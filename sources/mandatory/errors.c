/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:20:05 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 15:19:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ps_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ps_free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*node;

	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}
