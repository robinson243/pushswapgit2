/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:47 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 15:29:32 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *pile_temporaire, int size)
{
	int	i;
	int	j;
	int	temporaire;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_temporaire[i] > pile_temporaire[j])
			{
				temporaire = pile_temporaire[i];
				pile_temporaire[i] = pile_temporaire[j];
				pile_temporaire[j] = temporaire;
			}
			j++;
		}
		i++;
	}
}

void	sort_3_pile_a(t_piles *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		swap_a(three, 0);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three, 0);
		reverse_rotate_a(three, 0);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] < three->a[2])
		rotate_a(three, 0);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three, 0);
		rotate_a(three, 0);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
		reverse_rotate_a(three, 0);
}

int	sort(t_piles *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile, 0);
		else if (size == 3)
			sort_3_pile_a(pile);
		else
			quicksort_a(pile, size, 0);
	}
	return (0);
}
