/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:43:00 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 11:43:12 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 * Structures
 */
typedef struct s_node
{
	int				index;
	int				flag;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

typedef struct s_common
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		index_min;
	int		mid;
	int		len_a;
	int		len_b;
}				t_common;
/*
 * Parser's functions
 */
char	**ft_parser(int ac, char **av);
char	**ft_getstring(int ac, char **av);
void	err_handler(void);
int		validation(char **str);
int		is_allnums(char **str);
int		is_nodup(char **str);
int		is_sorted(char **str);
/*
 * Init
 */
t_node		*init_list(int index);
t_common	*init_param(char **nums);

#endif
