/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:12:24 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:36:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

void	heap_swap_node(t_heap_node *src, t_heap_node *dst)
{
	void	*tmp;

	if (!src || !dst)
		return;
	tmp = src->content;
	src->content = dst->content;
	dst->content = tmp;
}
