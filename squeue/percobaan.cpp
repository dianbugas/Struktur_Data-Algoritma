#include <iostream>
#include <stdlib.h>

#define MAX 30

using namespace std;

typedef struct pqueue
{
    int data[MAX];
    int rear,front;
}pqueue;

void initialize(pqueue *p);
int empty(pqueue *p);
int full(pqueue *p);
void enqueue(pqueue *p, int x);
int dequeue(pqueue *p);
void print(pqueue *p);

int main()
{
    int x,op,n,i;
    pqueue q;
    initialize(&q);

    do
    {
        cout<<"\n1)Create \n2)Insert \n3)Delete \n4)Print \n5)EXIT";
        cout<<"\nEnter Choice: ";
        cin>>op;

        switch (op) {
            case 1: cout<<"\nEnter Number of Elements";
                    cin>>n;
                    initialize(&q);
                    cout<<"Enter the data";

                    for(i=0; i<n; i++)
                    {
                        cin>>x;
                        if(full(&q))
                        {
                            cout<<"\nQueue is Full..";
                            exit(0);
                        }
                        enqueue(&q,x);
                    }
                    break;

            case 2: cout<<"\nEnter the element to be inserted";
                    cin>>x;
                    if(full(&q))
                    {
                        cout<<"\nQueue is Full";
                        exit(0);
                    }
                    enqueue(&q,x);
                    break;

            case 3: if(empty(&q))
                    {
                        cout<<"\nQueue is empty..";
                        exit(0);
                    }

                    x=dequeue(&q);
                    cout<<"\nDeleted Element="<<x;
                    break;

            case 4: print(&q);
                    break;
            default: break;
        }
    }while (op!=5);

    return 0;

}

void initialize(pqueue *p)
{
    p->rear=-1;
    p->front=-1;
}

int empty(pqueue *p)
{
    if(p->rear==-1)
        return(1);

    return(0);
}

int full(pqueue *p)
{
    if((p->rear+1)%MAX==p->front)
        return(1);

    return(0);
}

void enqueue(pqueue *p, int x)
{
    int i;
    if(full(p))
        cout<<"\nOverflow";
    else
    {
        if(empty(p))
        {
            p->rear=p->front=0;
            p->data[0]=x;
        }
        else
        {
            i=p->rear;

            while(x>p->data[i])
            {
                p->data[(i+1)%MAX]=p->data[i];
                i=(i-1+MAX)%MAX; //anticlockwise movement inside the queue
                if((i+1)%MAX==p->front)
                    break;
            }

            //insert x
            i=(i+1)%MAX;
            p->data[i]=x;

            //re-adjust rear
            p->rear=(p->rear+1)%MAX;
        }
    }
}

int dequeue(pqueue *p)
{
    int x;

    if(empty(p))
    {
        cout<<"\nUnderflow..";
    }
    else
    {
        x=p->data[p->front];
        if(p->rear==p->front)   //delete the last element
            initialize(p);
        else
            p->front=(p->front +1)%MAX;
    }

    return(x);
}

void print(pqueue *p)
{
    int i,x;

    if(empty(p))
    {
        cout<<"\nQueue is empty..";
    }
    else
    {
        i=p->front;

        while(i!=p->rear)
        {
            x=p->data[i];
            cout<<x;
            i=(i+1)%MAX;
        }

        //prints the last element
        x=p->data[i];
        cout<<"\n"<<x;
    }
}
