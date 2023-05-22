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
    x.isQueued++;
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
    int count;
    int month;
    printf("조회 하고싶은 달을 입력하세요: ");
    scanf("%d",&month);

    //대기가 존재하는 날짜와 테이블 손님을 찾기(날짜를 출력하기 위해서)
    
    for(int i = 0; i < 31; i++){
        if(dates[month-1][i].isQueued > 0){
            //[날짜]
            printf("[%d월 %d일]\n",month,i+1);
        }
        for(int j = 0; j < MAX_TABLES; j++){
            for(int n = 0; n < MAX_CUSTOMERS; n++){
                if(dates[month][i].tables[j].customer[n].isQueued > 0){
                    //[시간] [테이블 No] [이름] 출력
                    printf("[%s] [%d] [%s]",dates[month][i].tables[j].customer[n].orderedTime,dates[month][i].tables[j].customer[n].tableNum,dates[month][i].tables[j].customer[n].name);
                }
            }
        }
    }
        
    
    
    
}


