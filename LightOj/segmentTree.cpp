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
        tree[i] = myMin()
}

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        scanf("%d",&t);
        for(int i=0; i<=t; i++)
        {  int nmbrOfOpearton=0;
           scanf("%d %d",&nmbrOfData,&nmbrOfOpearton);
           int uplimit = nmbrOfData*2 ;
           for(int j=nmbrOfData;j<uplimit;j++)
                scanf("%d",&tree[j]);

        }
    }

}
