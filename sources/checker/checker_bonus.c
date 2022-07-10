/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:38:10 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 08:24:00 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	read_command(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(stack_a, stack_a, 0);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(stack_a, stack_a, 0);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		error();
}

void	ps_check(t_node **stack_a, t_node **stack_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		read_command(stack_a, stack_b, cmd);
	}
	if (is_sorted_stack(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc == 2)
		error();
	validation(argc, argv, 1);
	stack_a = ps_lstcreate();
	stack_b = ps_lstcreate();
	ps_init_stack(stack_a, argc, argv);
	ps_check(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	return (0);
}
