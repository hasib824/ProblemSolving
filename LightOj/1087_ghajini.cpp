#include<bits/stdc++.h>
#include<stdio.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;
int data[110000];

// Creating DQ using LINKEDLIST
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

//Node* head=NULL;
//Node* tail=NULL;

class DQ
{
  Node* head=NULL;
  Node* tail=NULL;

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
    Node* getHead()
    {
       return head;
    }
    Node* getEnd()
    {
        return tail;
    }
    bool dq_empty()
    {
        return head==NULL;
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
            delete tail ;
            head = NULL; tail = NULL;
             return ;
        }
        Node *temp=head;
        head = head->next ;
        delete temp;
        head->prev = NULL ;
    }

    void dq_pop_end()
    {
        if(tail==head)
        {
            delete head;
            head = NULL; tail = NULL; return ;
        }
        Node* temp=tail;
        tail = tail->prev;
        delete temp;
        tail->next= NULL;

    }

    void dq_free(Node* dqtail)
    {
        while(dqtail->prev!=NULL)
        {
            Node* temp = dqtail;
            dqtail = dqtail->prev;
            delete temp;
        }
        delete dqtail; head = NULL ; tail = NULL ;
    }


};

// here starts Sliding Window algo

int getMaxDiff(int nmbrOfData,int duration,int mint)
{
    int maxi=-1; int mini=mint;
    int resMax= -1;
    DQ minQ; DQ maxQ;
    for(int i=0;i<duration;i++)
    {   //printf("Ki problem 1\n");
        while(!maxQ.dq_empty() && data[maxQ.dq_end()]<data[i])
             {
               maxQ.dq_pop_end();
               //printf("aJIB, ");
             }

        while(!minQ.dq_empty() && data[minQ.dq_end()]>data[i])
           {
             //printf("min Q end : %d\n",minQ.dq_end());
             minQ.dq_pop_end();
           }
        //printf("MinQ :  : \n");
        minQ.push(i);
        maxQ.push(i);

    }
     //printf("Min is found : %d ", data[minQ.dq_front()]);
    //printf("Ashe nai \n");
    for(int i=duration;i<nmbrOfData;i++)
    {
        int temp = data[maxQ.dq_front()] ;
        int temp1= data[minQ.dq_front()];
        if(temp>maxi) maxi = temp;
        if(temp1<mini) mini= temp1;
        if(temp-temp1>resMax) resMax = temp-temp1;
        //printf("Big  : %d , small : %d\n",temp,temp1);
        while(!maxQ.dq_empty() && maxQ.dq_front()<=i-duration)
            maxQ.dq_pop_front();
        while(!minQ.dq_empty() && minQ.dq_front()<=i-duration)
            minQ.dq_pop_front();

        while(!minQ.dq_empty() && data[minQ.dq_end()]>data[i])
            minQ.dq_pop_end();

        while(!maxQ.dq_empty() && data[maxQ.dq_end()]<data[i])
            maxQ.dq_pop_end();

        maxQ.push(i); minQ.push(i);
    }
        int temp = data[maxQ.dq_front()] ;
        int temp1= data[minQ.dq_front()];
        if(temp>maxi) maxi = temp;
        if(temp1<mini) mini= temp1;
        //printf("Big  : %d , small : %d\n",temp,temp1);
        if(temp-temp1>resMax) resMax = temp-temp1;

        //printf("The result is : %d\n",resMax);
        maxQ.dq_free(maxQ.getHead()); minQ.dq_free(minQ.getHead());
       // maxQ.setNull(); minQ.setNull();

        return resMax;
}

int main()
{   //read ; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
     //   DQ Q;

        int nmbrOfData,duration;
        scanf("%d %d",&nmbrOfData,&duration);
        //cout<<"if empty : "<<Q.dq_empty()<<"\n";
        scanf("%d",&data[0]); int mini = data[0];
        for(int i=1; i<nmbrOfData; i++)
        {
            scanf("%d",&data[i]);
            if(mini<data[i]) mini = data[i];
           // Q.push(data[i]);

        }
        printf("Case %d: %d\n",t,getMaxDiff(nmbrOfData,duration, mini));
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



3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1

*/
