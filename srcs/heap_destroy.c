/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:06:08 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/29 16:21:24 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/heap.h"

void	heap_destroy(t_heap **heap)
{
	free((*heap)->queue);
	(*heap)->queue = NULL;
	free(*heap);
	*heap = NULL;
}
