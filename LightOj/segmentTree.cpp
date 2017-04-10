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


void build()
{
   for(int i=nmbrOfData-1; i>0; i--)
        tree[i] = myMin(tree[i*2],tree[i*2+1]);
}

int query()
{

}

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        scanf("%d",&t);
        for(int i=1; i<t; i++)
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
                int result = query(startRange,endRange);
                printf("%d\n",result);
           }
        }
    }

}
