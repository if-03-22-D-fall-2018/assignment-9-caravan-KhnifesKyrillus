/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include <stdlib.h>
#include "general.h"

#define COUNT_CARAVANS 5

typedef struct NodeImplementation* Node;

struct NodeImplementation
{
  PackAnimal animal;
  struct NodeImplementation* next;
};

struct CaravanImplementation
{
  int length;
  Node head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  caravan->length = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0)
  {
    Node deleted = current;
    current = current->next;
    sfree(deleted);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal==0) return;
  Node newNode=(Node)malloc(sizeof(struct NodeImplementation));
  newNode->animal=animal;
  newNode->next=0;
  if (caravan->head == 0)
  {
    caravan->head=newNode;
    caravan->length++;
  }
  else
  {
    Node current=caravan->head;
    while (current->next!=0)
    {
      if(current->animal==animal) return;
      current=current->next;
    }
    if(current->animal==animal) return;
    current->next=newNode;
    caravan->length++;
  }
  add_to_caravan(animal,caravan);
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (caravan->head->animal==animal)
  {
    Node deleted=caravan->head;
    caravan->head=caravan->head->next;
    sfree(deleted);
    remove_from_caravan(animal,caravan);
    caravan->length--;
  }
  else
  {
    Node current=caravan->head;
    while (current->next!=0&&current->next->animal!=animal)
    {
      current=current->next;
    }
    if (current->next==0) return;
    remove_from_caravan(animal,caravan);
    Node deleted=current->next;
    current->next=current->next->next;
    sfree(deleted);
    caravan->length--;
  }
}

int get_caravan_load(Caravan caravan)
{
  Node current=caravan->head;
  int load=0;
  while (current!=0)
  {
    load+=get_load(current->animal);
    current=current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node current=caravan->head;
  while (current!=0)
  {
    unload(current->animal);
    current=current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  Node current=caravan->head;
  int lowest_speed=10000;
  while (current!=0)
  {
    if (get_actual_speed(current->animal)<lowest_speed)
    {
      lowest_speed=get_actual_speed(current->animal);
    }
    current=current->next;
  }
  return lowest_speed;
}
void optimize_load(Caravan caravan)
{

}
