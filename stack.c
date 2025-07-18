#include "stack.h"

int main() {
    Stack s;
    init(&s);

    push(&s, 5);
    push(&s, 10);

    printf("Top: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top after pop: %d\n", peek(&s));

    return 0;
}
