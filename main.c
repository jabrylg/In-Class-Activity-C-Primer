#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *myList = list_alloc();
  
  list_print(myList);
  
  list_add_to_front(myList, 5);
  list_add_to_front(myList, 4);
  list_add_to_front(myList, 3);
  list_add_to_front(myList, 2);
  
  list_add_to_back(myList, 7);
  list_add_at_index(myList, 6, 4);
  list_print(myList);
  printf("This is the item that was removed from the end: %d \n", list_remove_from_back(myList));
  list_print(myList);
  printf("This is the item that was removed from the front: %d \n", list_remove_from_front(myList));
  list_print(myList);
  list_length(myList);
  return 0;
}