#include "queue.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", peekQueue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Front after dequeue: %d\n", peekQueue(&q));

    return 0;
}
