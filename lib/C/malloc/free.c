/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
** free
*/

#include <unistd.h>

#include "my_malloc.h"

#include "my.h"
#include "defines.h"

static void concat_block(alloc_header_t *node)
{
  if (node->next != NULL && node->next->data == NULL) {
    node->size += node->next->size + SIZE;
    node->next = node->next->next;
    if (node->next != NULL)
      node->next->prev = node;
  }
  if (node->prev != NULL && node->prev->data == NULL) {
    node = node->prev;
    concat_block(node);
  }
}

static int move_break(void)
{
  intptr_t size;
  void *brk;

  brk = sbrk(0);
  if (brk == (void *)-1)
    return (-1);
  if ((void *)last + SIZE + last->size == brk) {
    size = last->size;
    last = last->prev;
    if (last == NULL)
      size += SIZE;
    if (sbrk(-size) == (void *)-1)
      return (-1);
  }
  return (0);
}

int	my_frees(void)
{
  alloc_header_t *node;

  node = last;
  while (node != NULL) {
    node->data = NULL;
    concat_block(node);
    last = node;
    node = node->prev;
  }
  move_break();
  return (0);
}

void memheap(bool disp_data)
{
  alloc_header_t *node;

  node = last;
  while (node != NULL && node->prev != NULL)
    node = node->prev;
  mprintf("\nMapping of my_malloc : \n\n");
  if (node == NULL)
    mprintf("There is no allocated block\n");
  while (node != NULL) {
    mprintf("----------------------------\n"
						"prev : %p\n"
						"addr : %p\n"
						"size : %u bytes\n"
						"data : ",
						node->prev,
						node,
						node->size);
		if (disp_data)
			display_inside(node->data, "%c", node->size);
    mprintf("\nnext : %p\n", node->next);
    node = node->next;
  }
}

int my_free(void *ptr)
{
	alloc_header_t *node;

	if (ptr) {
		node = ptr - ((void *)(&node->data) - (void *)node) - sizeof(void *);
		node->data = NULL;
		concat_block(node);
		if (last->data == NULL && move_break() == -1)
			return (-1);
	}
	return (0);
}

int	my_sfree(void *pptr)
{
  alloc_header_t *node;
	void **ptr;

	ptr = pptr;
  if (*ptr == NULL)
    return (0);
  node = last;
  while (node != NULL) {
    if (node->data == *ptr) {
      node->data = NULL;
      concat_block(node);
      if (last->data == NULL && move_break() == -1)
				return (-1);
			*ptr = NULL;
      return (0);
    }
    node = node->prev;
  }
  mdprintf(2, "[Error] Tried to free an unexisting pointer %p\n", *ptr);
  return (-1);
}
