#ifndef QUEUE_H
#define QUEUE_H
#include "setting.h"

void initialize_queue(my_queue *queue);
void insert_q(my_queue *queue, Customer x);
void delete_q(my_queue *queue);
bool queue_full(my_queue *queue);
bool queue_empty(my_queue *queue);
void showQueue(my_queue *queue);

#endif
