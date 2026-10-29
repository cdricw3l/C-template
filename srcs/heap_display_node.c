/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_display_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:21:25 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:40:33 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

void	heap_display_node(t_heap_node *node, void (*display_content)(void *))
{
	if (!node || !display_content)
		return ;
	printf("\n");
	printf(UGRN"Content:"CRESET);
	display_content(node->content);
	printf(UYEL"Data:"CRESET"\n");
	printf("Node: %p\n", node);
	printf("Parent: %p\n", node->parent);
	printf("Left: %p\n", node->left);
	printf("Right: %p\n", node->right);
}
