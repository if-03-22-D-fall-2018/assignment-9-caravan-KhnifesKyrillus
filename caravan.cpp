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
#define HORSE_MAX 50
#define CAMEL_MAX 20

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
      current=current->next;
    }
    current->next=newNode;
    caravan->length++;
  }
  add_to_caravan(animal,caravan);
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  return 1000;
}

void unload(Caravan caravan)
{

}

int get_caravan_speed(Caravan caravan)
{
  return 1000;
}
void optimize_load(Caravan caravan)
{

}
