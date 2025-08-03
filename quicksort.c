/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:44 by romukena          #+#    #+#             */
/*   Updated: 2025/08/02 15:30:25 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_three_a_and_b(t_piles *p, int len)
{
	if (len == 3 && p->size_a == 3)
		sort_3_pile_a(p);
	else if (len == 2)
	{
		if (p->a[0] > p->a[1])
			swap_a(p, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(p->a[0] < p->a[1]
				&& p->a[1] < p->a[2]))
		{
			if (len == 3 && p->a[0] > p->a[1] && p->a[2])
				swap_a(p, 0);
			else if (len == 3 && !(p->a[2] > p->a[0] && p->a[2] > p->a[1]))
			{
				push_b(p, 0);
				len--;
			}
			else if (p->a[0] > p->a[1])
				swap_a(p, 0);
			else if (len++)
				push_a(p, 0);
		}
	}
}

int	sort_3_b(t_piles *pile, int len)
{
	if (len == 1)
		return (push_a(pile, 0), 0);
	if (len == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile, 0);
		while (len--)
			push_a(pile, 0);
		return (0);
	}
	while (len > 0 || !(pile->a[0] < pile->a[1] && pile->a[1] < pile->a[2]))
	{
		if (len == 1 && pile->a[0] > pile->a[1])
			swap_a(pile, 0);
		else if (len == 1 || (len >= 2 && pile->b[0] > pile->b[1])
			|| (len == 3 && pile->b[0] > pile->b[2])
		)
		{
			push_a(pile, 0);
			len--;
		}
		else
			swap_b(pile, 0);
	}
	return (0);
}

static int	find_mediane(int *pivot, int *pile, int size)
{
	int		*temporaire_pile;
	int		i;

	temporaire_pile = (int *)malloc(size * sizeof(int));
	if (!temporaire_pile)
		return (0);
	i = 0;
	while (i < size)
	{
		temporaire_pile[i] = pile[i];
		i++;
	}
	bubble_sort(temporaire_pile, size);
	*pivot = temporaire_pile[size / 2];
	free(temporaire_pile);
	return (1);
}

int	quicksort_a(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_three_a_and_b(pile, len);
		return (1);
	}
	if (!find_mediane(&pivot, pile->a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (pile->a[0] < pivot && (len--))
			push_b(pile, 0);
		else if (++count_r)
			rotate_a(pile, 0);
	}
	while (numbers / 2 + numbers % 2 != pile->size_a && count_r--)
		reverse_rotate_a(pile, 0);
	return (quicksort_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(pile, numbers / 2, 0));
	return (1);
}

int	quicksort_b(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->b, len, 1) == 1)
		while (len--)
			push_a(pile, 0);
	if (len <= 3)
	{
		sort_3_b(pile, len);
		return (1);
	}
	numbers = len;
	if (!find_mediane(&pivot, pile->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (pile->b[0] >= pivot && len--)
			push_a(pile, 0);
		else if (++count_r)
			rotate_b(pile, 0);
	}
	while (numbers / 2 != pile->size_b && count_r--)
		reverse_rotate_b(pile, 0);
	return (quicksort_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(pile, numbers / 2, 0));
}
