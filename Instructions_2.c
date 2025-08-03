/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:31:16 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 12:28:38 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_a <= 1)
		return ;
	tmp = pile->a[0];
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->a[pile->size_a - 1] = tmp;
	if (!bonus)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_b <= 1)
		return ;
	tmp = pile->b[0];
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->b[pile->size_b - 1] = tmp;
	if (!bonus)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_piles *pile, int bonus)
{
	if (pile->size_a <= 1 && (pile->size_b <= 1))
		return ;
	rotate_a(pile, 1);
	rotate_b(pile, 1);
	if (!bonus)
		ft_putstr_fd("rr\n", 1);
}
