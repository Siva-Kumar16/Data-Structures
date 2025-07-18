#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check whether queue is empty
int isEmptyQueue(Queue *q) {
    return q->front > q->rear;
}

// Check wheteher queue is full
int isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue 
void enqueue(Queue *q, int val) {
    if (isFullQueue(q)) {
        printf("Queue full\n");
        return;
    }
    q->data[++(q->rear)] = val;
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue empty\n");
        return -1;
    }
    return q->data[(q->front)++];
}

// Peek
int peekQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue empty\n");
        return -1;
    }
    return q->data[q->front];
}

#endif
