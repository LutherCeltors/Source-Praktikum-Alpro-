#include <stdio.h>
#include "queue.h"

int main(){
    Queue q;
    int X;
    CreateQueue(&q);
    displayQueue(q);
    scanf("%d", &X);

    for (int i = 0; i < 100; i++){
        enqueue(&q, X);
        displayQueue(q);
        X++;
    }
    dequeue(&q, &X);
    printf("on : %d\n", X);
    displayQueue(q);
    dequeue(&q, &X);
    printf("on : %d\n", X);
    displayQueue(q);
    dequeue(&q, &X);
    printf("on : %d\n", X);
    displayQueue(q);
    printf("tail : %d\n", IDX_TAIL(q));
    printf("head : %d\n", IDX_HEAD(q));

    printf("%d\n", q.buffer[2]);
    printf("%d\n", q.buffer[3]);

    scanf("%d", &X);
    enqueue(&q, X);
    displayQueue(q);
    printf("%d\n", q.buffer[0]);
    printf("tail : %d\n", IDX_TAIL(q));
    printf("head : %d\n", IDX_HEAD(q));
    printf("%d\n", length(q));

    scanf("%d", &X);
    enqueue(&q, X);
    displayQueue(q);
    printf("%d\n", q.buffer[1]);
    printf("tail : %d\n", IDX_TAIL(q));
    printf("head : %d\n", IDX_HEAD(q));
    printf("%d\n", length(q));

    scanf("%d", &X);
    enqueue(&q, X);
    displayQueue(q);
    printf("%d\n", q.buffer[2]);
    printf("tail : %d\n", IDX_TAIL(q));
    printf("head : %d\n", IDX_HEAD(q));
    printf("%d\n", isFull(q));
    printf("%d\n", length(q));

    for (int i = 0; i < 100; i++){
        dequeue(&q, &X);
        displayQueue(q);
        printf("%d\n", length(q));
        printf("idx_head : %d;", IDX_HEAD(q));
        printf("idx_tail : %d\n", IDX_TAIL(q));
    }
}
