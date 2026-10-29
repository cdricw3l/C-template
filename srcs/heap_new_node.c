/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:39:14 by cdric.b           #+#    #+#             */
/*   Updated: 2026/10/23 20:42:51 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

t_heap_node	*heap_new_node(void *content)
{
	t_heap_node	*node;

	node = malloc(sizeof(t_heap_node));
	if (!node)
	{
		perror("Node allocation error:");
		return (NULL);
	}
	node->content = content;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
