/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_heappush_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:49:25 by cebouhad          #+#    #+#             */
/*   Updated: 2026/10/29 18:56:24 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

t_heap      *heap_init(void);
t_heap_node *heap_new_node(void *content);
int	get_path(int target_node_idx, char buffer[HEAP_BIT_MAX + 1]);

static void unit_heap_get_path(void)
{
	START_TEST;	

	char buffer[HEAP_BIT_MAX + 1];	
	memset(buffer, 0, HEAP_BIT_MAX + 1);
	get_path(-1, buffer);
	assert(!strcmp(buffer,""));
	get_path(0, buffer);
	assert(!strcmp(buffer,""));
	get_path(1, buffer);
	assert(!strcmp(buffer,""));
	get_path(2, buffer);
	assert(!strcmp(buffer,"0"));
	get_path(3, buffer);
	assert(!strcmp(buffer,"1"));
	get_path(4, buffer);
	assert(!strcmp(buffer,"00"));
	get_path(5, buffer);
	assert(!strcmp(buffer,"01"));
	get_path(6, buffer);
	assert(!strcmp(buffer,"10"));
	get_path(7, buffer);
	assert(!strcmp(buffer,"11"));
	get_path(8, buffer);
	assert(!strcmp(buffer,"000"));
	get_path(9, buffer);
	assert(!strcmp(buffer,"001"));
	get_path(10, buffer);
	assert(!strcmp(buffer,"010"));
	get_path(42, buffer);
	assert(!strcmp(buffer,"01010"));
	get_path(4200, buffer);
	assert(!strcmp(buffer,"000001101000"));
	get_path(42000, buffer);
	assert(!strcmp(buffer,"010010000010000"));
	get_path(420000, buffer);
	assert(!strcmp(buffer,"100110100010100000"));
	get_path(INT_MAX, buffer);
	assert(!strcmp(buffer,"111111111111111111111111111111"));
	get_path(0, NULL);

	END_TEST;
}

static void unit_heap_get_node(void)
{

	START_TEST;
	t_heap *heap;

	heap = heap_init();
	assert(heap);
	
	t_heap_node n0;
	t_heap_node n1;
	t_heap_node n2;
	t_heap_node n3;
	t_heap_node n4;
	t_heap_node n5;
	t_heap_node n6;
	t_heap_node n7;
	t_heap_node n8;
	t_heap_node n9;
	t_heap_node n10;

	n0.left = &n1;
	n0.right = &n2;

	n1.left = &n3;
	n1.right = &n4;

	n2.left = &n5;
	n2.right = &n6;

	n3.left = &n7;
	n3.right = &n8;

	n4.left = &n9;
	n4.right = &n10;
	
	*heap->queue = &n0;
	heap->size_queue = 11;
	assert(heap_get_node(NULL, -1) == NULL);
	assert(heap_get_node(NULL, 0) == NULL);
	assert(heap_get_node(heap, 1) == &n0);
	assert(heap_get_node(heap, 2) == &n1);
	assert(heap_get_node(heap, 1000) == NULL);
	assert(heap_get_node(heap, 11) == &n10);
	assert(heap_get_node(NULL, INT_MAX) == NULL);
	
	heap_destroy(&heap);

	END_TEST;
}

int heap_min_compare(void *ptr_1, void *ptr_2)
{
	int a;
	int b;

	if (ptr_1 == NULL || ptr_2 == NULL)
		return (FALSE);
	a = *((int *)ptr_1);
	b = *((int *)ptr_2);
	if(a < b)
		return (TRUE);
	return (FALSE);
}

int heap_max_compare(void *ptr_1, void *ptr_2)
{
	int a;
	int b;

	if (ptr_1 == NULL || ptr_2 == NULL)
		return (FALSE);
	a = *((int *)ptr_1);
	b = *((int *)ptr_2);
	if(a > b)
		return (TRUE);
	return (FALSE);
}
void unit_heap_compare(void)
{
	int a;
	int b;

	a = 42;
	b = 0;
	assert(heap_min_compare(&a, &b) == FALSE);
	assert(heap_min_compare(&b, &a) == TRUE);
	assert(heap_min_compare(&b, NULL) == FALSE);
	assert(heap_min_compare(NULL, &a) == FALSE);
	assert(heap_min_compare(NULL, NULL) == FALSE);
	assert(heap_max_compare(&a, &b) == TRUE);
	assert(heap_max_compare(&b, &a) == FALSE);
	assert(heap_max_compare(NULL, &a) == FALSE);
	assert(heap_max_compare(&a, NULL) == FALSE);
	assert(heap_max_compare(NULL, NULL) == FALSE);

}



static void unit_heap_push_pop()
{
	START_TEST;

	t_heap *heap;
	t_heap_node *node;
	int i;
	int arr_1[10] = {0, 1,2,3,4,5,6,7,8,9};
	int arr_2[10] = {0, 1,2,3,4,5,6,7,8,9};
	int *value;

	heap = heap_init();
	assert(heap);

	i = sizeof(arr_1) / sizeof(arr_1[0]) - 1;
	assert(i == 9);
	while (i <= 0)
	{
		value = &arr_1[i];
		node = heap_new_node(value);
		assert(node->content == &arr_1[i]);
		heappush(heap, node, heap_min_compare);
		assert(*((int *)(*heap->queue)) == arr_1[i]);
		i--;
	}
	i = 8;
	while (heap->size_queue)
	{
		heappop(heap, heap_min_compare,NULL);
		assert(*((int *)(*heap->queue)->content) == arr_1[i--]);
	}
	
	assert(*heap->queue == NULL && heap->size_queue == 0);

	i = 0;
	while (i < (int)(sizeof(arr_2) / sizeof(arr_2[0])))
	{
		value = &arr_2[i];
		node = heap_new_node(value);
		assert(node->content == &arr_2[i]);
		heappush(heap, node, heap_max_compare);
		//printf("La value du premier noeud est %d et la valuer de i : %d\n", *(int *)(t_heap_node *)(*heap->queue)->content, i);
		assert((int *)((t_heap_node *)(*heap->queue)->content) == &arr_2[i]);
		assert(*(int *)(t_heap_node *)(*heap->queue)->content == arr_2[i]);
		i++;
	}
	assert(*(int *)(t_heap_node *)(*heap->queue)->content == 9);
	assert(heap->size_queue == 10);
	i = 8;
	while (heap->size_queue)
	{

		heappop(heap, heap_max_compare ,NULL);
		if (heap->size_queue > 0)
			assert(*(int *)(t_heap_node *)(*heap->queue)->content == arr_2[i--]);
	}
	
	node = heap_new_node(NULL);
	assert(heappush(NULL, NULL, NULL) == FALSE);
	assert(heappush(NULL, node , heap_min_compare) == FALSE);
	assert(heappush(heap, NULL , heap_min_compare) == FALSE);

	free(node);
	heap_clear(heap, NULL);
	heap_destroy(&heap);

	

	END_TEST;
}

void test()
{
	START_TEST;
	t_heap *heap;
	t_heap_node *node;

	heap = heap_init();
	node = heap_new_node(NULL);

	
	heappush(heap,node, heap_min_compare);
	assert(heap->size_queue == 1);

	heappop(heap,heap_min_compare,NULL);

	assert(heap->size_queue == 0);

	END_TEST;
}

void unit_heappush(void)
{
	unit_heap_get_path();
	unit_heap_get_node();
	unit_heap_compare();
	unit_heap_push_pop();
	
}
