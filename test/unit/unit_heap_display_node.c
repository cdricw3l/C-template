/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_display_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:38:09 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/23 23:48:37 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	heap_display_node(t_heap_node *node, void (*display_content)(void *));

static void print_str(void *ptr)
{
    char *str;

    str = (char *)ptr;
    write(STDIN_FILENO, str, strlen(str));
}

void unit_heap_display_node(void)
{
	START_TEST;
    
    t_heap_node node;

    node.content = strdup("hello");
    node.left = NULL;
    node.right = NULL;
    node.parent = NULL;
    heap_display_node(NULL, NULL);
    heap_display_node(&node, NULL);
    free(node.content);
    heap_display_node(NULL, print_str);
	END_TEST;
}
