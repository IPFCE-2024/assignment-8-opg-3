#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"
#include "queue.c"
int main() {
    queue q;
    initialize(&q);
    assert(q.front == NULL);
    assert(q.rear == NULL);
    printf("Test one passed.\n");//stack/queue is empty after initialization


    int x = 10;
    enqueueStack(&q,x);
    int y = dequeueStack(&q);

    assert(q.front == NULL);
    assert(q.rear == NULL);
    assert(x==y);

    printf("Test two passed.\n");
//x = 10 and y = 10. The stack/queue also looks the same as before the test.

    int x0 = 20;
    int x1 = 30;

    enqueueStack(&q, x0);
    enqueueStack(&q, x1);
    int y0 = dequeueStack(&q);
    int y1 = dequeueStack(&q);

    assert(q.front == NULL);
    assert(q.rear == NULL);
    assert(x0==y0);
    assert(x1==y1);

//x0 = 20, x1 = 30, y0 = 20 and y1 = 30. The queue looks the same as before all four commands.
printf("All tests passed.\n");

return 0;

}