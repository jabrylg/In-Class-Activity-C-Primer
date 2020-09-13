// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


list_t *list_alloc() { 
  list_t * head = NULL;
  head = malloc(sizeof(list_t));
  return head; 
}

void list_free(list_t *l) {
  free(l);
}

void list_print(list_t *l) {
  node_t* temp = l->head;
  
  while(temp != NULL){
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

int list_length(list_t *l) { 
  node_t* temp = malloc(sizeof(node_t*));
  int i = 0;
  if(l == NULL){
    return i;
  }
  temp = l->head;
  i++;
  while(temp->next != NULL){
    temp = temp->next;
    i++;
  }
  printf("The length is: %d", i);
  printf("\n");
}

bool out_of_bounds(int index, int length){
  if(index < 0 || index > length){
    return true;
  }
  return false;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  
  node_t* newHead = malloc(sizeof(node_t*));
  newHead->value = value;
  temp->next = newHead;
}

void list_add_to_front(list_t *l, elem value) {
  node_t* newHead = malloc(sizeof(node_t*));
  newHead->value = value;
  newHead->next = l->head;
  l->head = newHead;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if(out_of_bounds(index, list_length(l) == true))
     return;
  
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  int i = 0;
  
  if(index == 0){
    list_add_to_front(l, value);
  }
  while(i != index-1){
    temp = temp->next;
    i++;
  }
  
  node_t* newHead = malloc(sizeof(node_t*));
  newHead->value = value;
  newHead->next = temp->next;
  temp->next = newHead;
}

elem list_remove_from_back(list_t *l) {
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  int x = temp->next->value;
  temp->next = NULL;
  return x;
}

elem list_remove_from_front(list_t *l) {
  int x = l->head->value;
  l->head = l->head->next;
  return x;
}

elem list_remove_at_index(list_t *l, int index) {
  if(out_of_bounds(index, list_length(l) == true))
     return;
  
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  int i = 0;
  int x = -1;

  
  if(index == 0){
    x = l->head->value;
    l->head = l->head->next;
    return x;
  }
  while(i != index-1){
    temp = temp->next;
    i++;
    if(index == i){
      x = temp->next->value;
      temp->next = temp->next->next;
      return x;
    }
  }
  
  return x;
}

bool list_is_in(list_t *l, elem value) {
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  while(temp != NULL){
    if(temp->value == value)
      return true;
    temp = temp->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if(out_of_bounds(index, list_length(l) == true))
     return;
  
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  int i = 0;
  
  while(i != index-1){
    temp = temp->next;
    i++;
  }
  return temp->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t* temp = malloc(sizeof(node_t*));
  temp = l->head;
  int i = 0;
  while(temp != NULL){
    if(temp->value == value)
      return i;
    i++;
    temp = temp->next;
  }
  return -1;
}