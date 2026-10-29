/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 09:58:53 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 20:42:49 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

void	heap_iter(t_heap_node *root,
	void (*f)(t_heap_node *, void (*content)(void *)), void (*content)(void *))
{
	if (!root)
		return ;
	heap_iter(root->left, f, content);
	f(root, content);
	heap_iter(root->right, f, content);
}
