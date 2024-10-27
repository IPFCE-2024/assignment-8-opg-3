#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"
#include "queue.c"
int main() {
queue q;
initialize(&q);
assert(empty(&q) == true); //After initializing the queue must be empty
assert(q.front == NULL);
assert(q.rear == NULL);
assert(q.size == 0);
printf("Test one passed.\n");

int x = 10;
enqueue(&q,x);
int y = dequeue(&q);

assert(empty(&q) == true);
assert(q.front == NULL);
assert(q.rear == NULL);
assert(q.size == 0);
assert(x==y);

printf("Test two passed.\n");
//x = 10 and y = 10. The queue also looks the same as before the test.

int x0 = 20;
int x1 = 30;

enqueue(&q, x0);
enqueue(&q, x1);
int y0 = dequeue(&q);
int y1 = dequeue(&q);
assert(empty(&q) == true);
assert(q.front == NULL);
assert(q.rear == NULL);
assert(q.size == 0);
assert(x0==y0);
assert(x1==y1);

//x0 = 20, x1 = 30, y0 = 20 and y1 = 30. The queue looks the same as before all four commands.
printf("All tests passed.\n");

return 0;

}