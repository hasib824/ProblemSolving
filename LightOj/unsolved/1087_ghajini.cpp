#include<bits/stdc++.h>
using namespace std;
int maxi=-1; int mini;
int data[110000];
struct Node
{
    Node* prev;
    int a;
    Node* next;
    Node()
    {
        prev = NULL;
        a=0;
        next = NULL ;
    }
};

Node* head=NULL;
Node* tail=NULL;

class DQ
{
public:
    void push(int a)
    {
        if(head==NULL)
        {
            head = new Node;
            head->a = a;
            tail = head;
            return;
        }
        Node* temp = new Node;
        temp->prev = tail ;
        tail->next = temp;
        tail = tail->next;
        tail->a = a ;
    }
    bool dq_empty()
    {
        return head==NULL ;
    }

    int dq_front()
    {
        return head->a;
    }

    int dq_end()
    {
        return tail->a;
    }

    void dq_pop_front()
    {

        if(tail==head)
        {
            delete head; delete tail ;
            head = NULL; tail = NULL; return ;
        }
        head = head->next ;
        delete head->prev;
        head->prev = NULL ;
    }

    void dq_pop_end()
    {
        if(tail==head)
        {
            delete head; delete tail ;
            head = NULL; tail = NULL; return ;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next= NULL;

    }


    void dq_free(Node* dqHead)
    {
        if(dqHead->next== NULL)
        {
            delete dqHead;
            return;
        }
        dq_free(dqHead->next);
        delete dqHead;
        dqHead = NULL;
    }
};
// here starts Sliding Window algo

int getMaxDiff(int nmbrOfData,int duration)
{

    DQ minQ; DQ maxQ;
    for(int i=0;i<duration;i++)
    {   //printf("Ki problem 1\n");
        while(!maxQ.dq_empty() && data[maxQ.dq_end()]<data[i])
             {
               maxQ.dq_pop_end();
               printf("aJIB, ");
             }
        minQ.push(i);
        while(!minQ.dq_empty() && data[minQ.dq_end()]>data[i])
           {
             printf("min Q end : %d\n",minQ.dq_end());
             minQ.dq_pop_end();
           }
        printf("MinQ :  : \n");

        maxQ.push(i);

    }
     printf("Min is found : %d ", data[minQ.dq_front()]);
    //printf("Ashe nai \n");
    /*for(int i=duration;i<nmbrOfData;i++)
    {
        int temp = data[maxQ.dq_front()] ;
        int temp1= data[minQ.dq_front()];
        if(temp>maxi) maxi = temp;
        if(temp1<mini) mini= temp1;
        printf("Big  : %d , small : %d\n",temp,temp1);
        while(!maxQ.dq_empty() && maxQ.dq_front()<=i-duration)
            maxQ.dq_pop_front();

        while(!maxQ.dq_empty() && data[minQ.dq_end()]>data[i])
            minQ.dq_pop_end();

        while(!maxQ.dq_empty() && data[maxQ.dq_end()]<data[i])
            maxQ.dq_pop_end();
        maxQ.push(i);
    } */
    return 0;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        DQ Q;

        int nmbrOfData,duration;
        scanf("%d %d",&nmbrOfData,&duration);
        cout<<"if empty : "<<Q.dq_empty()<<"\n";
        scanf("%d",&data[0]); mini = data[0];
        for(int i=1; i<nmbrOfData; i++)
        {
            scanf("%d",&data[i]);
            if(mini>data[i]) mini = data[i];
            Q.push(data[i]);


        }
        cout<<"if empty : "<<Q.dq_empty()<<"\n";
        printf("front : %d back %d\n",Q.dq_front(),Q.dq_end());
        Q.dq_pop_front();
        Q.dq_pop_end();
        printf("front : %d back %d\n",Q.dq_front(),Q.dq_end());
        //Q.dq_pop_front();
        Q.dq_pop_end();
        printf("front : %d back %d\n",Q.dq_front(),Q.dq_end());
        Q.dq_pop_end();
        printf("front : %d back %d\n",Q.dq_front(),Q.dq_end());

        Q.dq_free(head);
        head = NULL;
        tail = NULL;
        cout<<"Freeing DQ \n"<<"if empty : "<<Q.dq_empty()<<"\n";

        getMaxDiff(nmbrOfData,duration);
    }
    return 0;
}



/*
1
7
3

3
4
5
6
7
12
4

*/
