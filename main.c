
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 50

typedef struct node{
    char info;
    struct node *next;
} node;

typedef node * Nodeptr;

typedef struct queue{
    Nodeptr front, rear;
} queue;

typedef queue * Queueptr;

void init_queue(Queueptr queue){
    queue->front = queue->rear = NULL;
}

int isempty(Queueptr queue){
    if(queue->front == NULL)
        return 1;
    else return 0;
}

void insert(Queueptr queue, char info){
    Nodeptr p = (Nodeptr)malloc(sizeof(node));

    if(queue->front == NULL)
        queue->front = p;
    else
        queue->rear->next = p;

    p->info = info;
    p->next = queue->front;
    queue->rear = p;
}

char Remove(Queueptr queue){
    Nodeptr p;
    char data;

    if(isempty(queue)){
        printf("Queue is empty");
        return 0;
    }

    if(queue->front == queue->rear){
        data = queue->front->info;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        p =queue->front;
        data =queue->front->info;
       queue->front = queue->front->next;
       queue->rear->next = queue->front;
        free(p);
    }

    return data;
}

int main()
{
    Queueptr q = (Queueptr)malloc(sizeof(queue));
    init_queue(q);
    char symb;
    do{
        printf("Enter a character: ");
        scanf("%c", &symb);

        if(isalpha(symb)){
            if(islower(symb))
                symb = toupper(symb);
            insert(q, symb);
        }
        else if(isdigit(symb));
        else if(ispunct(symb));
        else if(isspace(symb))
            insert(q, symb);
        else;
        while(getchar() != '\n');

    } while(symb != '\n');

    while(!isempty(q)){
        printf("%c", Remove(q));
    }
    return 0;
}
