#include "setting.h"

void initialize_queue(my_queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void insert_q(my_queue *queue, Customer x) {
    if ((queue->rear + 1) % Q_SIZE == queue->front) {
        printf("[추가 실패] 대기 명단이 꽉 차있습니다\n");
        return;
    }

    queue->rear = (queue->rear + 1) % Q_SIZE;
    queue->q[queue->rear] = x;
}

void delete_q(my_queue *queue) {
    if (queue->front == (queue->rear + 1) % Q_SIZE) {
        printf("[삭제 실패] 대기 명단이 비어있습니다\n");
        return -1;
    }
}

bool queue_full(my_queue *queue) {
    return (queue->rear + 1) % Q_SIZE == queue->front;
}

bool queue_empty(my_queue *queue) {
    return queue->front == (queue->rear + 1) % Q_SIZE;
}

void showQueue(my_queue *queue){

    if (queue_empty(queue)) {
        printf("대기 명단이 비어있습니다.\n");
        return;
    }
    
    while(queue_empty(queue) != true){
        printf("%d");
    }
}


