/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:14:56 by romukena          #+#    #+#             */
/*   Updated: 2025/08/06 01:46:43 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_piles;

int		push_swap(char **av);
int		push_swap_strlen(char **av);
int		push_swap_atoi(char *str, int *error);
int		check_doubles(int *pile, int size);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char *charset);
void	free_tab(char **tab);
/*Instructions*/
void	swap_a(t_piles *pile, int bonus);
void	swap_b(t_piles *pile, int bonus);
void	swap_s(t_piles *pile, int bonus);
void	rotate_a(t_piles *pile, int bonus);
void	rotate_b(t_piles *pile, int bonus);
void	rotate_r(t_piles *pile, int bonus);
void	reverse_rotate_a(t_piles *pile, int bonus);
void	reverse_rotate_b(t_piles *pile, int bonus);
void	reverse_rotate_r(t_piles *pile, int bonus);
void	push_b(t_piles *pile, int bonus);
void	push_a(t_piles *pile, int bonus);
/*Sort*/
int		sort(t_piles *pile, int size);
int		check_sorted(int *pile, int size, int order);
void	sort_3_pile_a(t_piles *three);
void	bubble_sort(int *pile_temporaire, int size);
/*Quicksort*/
int		quicksort_a(t_piles *pile, int len, int count_r);
int		quicksort_b(t_piles *pile, int len, int count_r);
void	quicksort_3_a_and_b(t_piles *p, int len);
int		sort_3_b(t_piles *pile, int len);

#endif