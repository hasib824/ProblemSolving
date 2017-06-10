#include<bits/stdc++.h>

using namespace std;

const int n = 100000;
int nmbrOfData =0;
int tree[n*2+5] ;

int myMin(int a,int b)
{
    if(b>a) return a;
    else return b;
}

void printTree()
{
   for(int i=nmbrOfData-1;i>0;i--)
   {
      printf("parent : %d data : %d \n left child %d data %d, right child %d data %d\n",i,tree[i],i*2,tree[i*2],i*2+1,tree[i*2+1]);
   }
}


void build()
{
   for(int i=nmbrOfData-1; i>0; i--)
        tree[i] = myMin(tree[i*2],tree[i*2+1]);
    //printTree();
}



int query(int startRange,int endRange)
{    startRange=startRange+nmbrOfData-1 ; endRange=endRange+nmbrOfData-1;
    int minimum=tree[startRange];
   // printf("Start %d, End %d %d, %d\n",startRange,endRange,tree[startRange],tree[endRange]);
    while(startRange<=endRange)
    {
        if(startRange%2 == 1)
        {
            minimum = myMin(minimum,tree[startRange]);
            // printf("Testing startRange %d  min %d\n",startRange,minimum);
            startRange+=1;
        }
        if(endRange%2 == 0)
        {
            minimum = myMin(minimum,tree[endRange]);
            //printf("Testing endRange %d  min %d\n",endRange,minimum);
            endRange-=1;
            //printf("kere\n");
        }
       // printf("Now Start %d, End %d\n",startRange,endRange);
        startRange/=2; endRange/=2;
    }

    return minimum;
}

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        for(int i=1; i<=t; i++)
        {  int nmbrOfQuery=0;
           scanf("%d %d",&nmbrOfData,&nmbrOfQuery);
           int uplimit = nmbrOfData*2 ;
           for(int j=nmbrOfData;j<uplimit;j++)
                scanf("%d",&tree[j]);

           build();
           printf("Case %d:\n",i);
           for(int j=0;j<nmbrOfQuery;j++)
           {
                int startRange, endRange ;
                scanf("%d %d",&startRange,&endRange);
                int result = query(startRange,endRange);
                printf("%d\n",result);
           }
        }
    }

}


/*

2
13 4
2
3
5
8
11
7
6
13
4
9
10
1
14

3 9


2
14 4
5
4
2
3
15
7
6
12
11
4
23
17
15
16

6 9
1 2
3 5
3 11
*/
