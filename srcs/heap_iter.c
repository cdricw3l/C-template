/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 09:58:53 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/30 16:14:44 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

/**
 * heap_iter itere over heap and change the content of the node
 */
void	heap_iter(t_heap_node *root, void (*f)(t_heap_node *node))
{
	if (!root || !f)
		return ;
	heap_iter(root->left, f);
	f(root);
	heap_iter(root->right, f);
}
