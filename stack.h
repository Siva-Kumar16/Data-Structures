#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

// Checkvempty
int empty(Stack *s) {
    return s->top == -1;
}

// Check full
int full(Stack *s) {
    return s->top == MAX - 1;
}

// Push element
void push(Stack *s, int val) {
    if (full(s)) {
        printf("Stack full\n");
        return;
    }
    s->data[++(s->top)] = val;
}

// Pop element
int pop(Stack *s) {
    if (empty(s)) {
        printf("Stack empty\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Peek element
int peek(Stack *s) {
    if (empty(s)) {
        printf("Stack empty\n");
        return -1;
    }
    return s->data[s->top];
}

#endif
