#include "prioritas.h"
#include <stdio.h>

void prioritizeValue(Queue *q, int x) {
    Queue priorityQueue;
    Queue normalQueue;
    CreateQueue(&priorityQueue);
    CreateQueue(&normalQueue);

    // Pisahkan elemen x dan non-x
    while (!isEmpty(*q)) {
        ElType val;
        dequeue(q, &val);
        if (val == x) {
            enqueue(&priorityQueue, val);
        } else {
            enqueue(&normalQueue, val);
        }
    }

    // Gabungkan priorityQueue dan normalQueue kembali ke q
    while (!isEmpty(priorityQueue)) {
        ElType val;
        dequeue(&priorityQueue, &val);
        enqueue(q, val);
    }
    while (!isEmpty(normalQueue)) {
        ElType val;
        dequeue(&normalQueue, &val);
        enqueue(q, val);
    }

    // Cetak hasil dalam format yang diminta
    printf("[");
    int printed = 0;
    Queue tempQ;
    CreateQueue(&tempQ);
    while (!isEmpty(*q)) {
        ElType val;
        dequeue(q, &val);
        enqueue(&tempQ, val);
        if (printed) printf(",");
        printf("%d", val);
        printed = 1;
    }
    printf("]\n");

    // Salin kembali isi tempQ ke q agar tidak kosong
    while (!isEmpty(tempQ)) {
        ElType val;
        dequeue(&tempQ, &val);
        enqueue(q, val);
    }
}

