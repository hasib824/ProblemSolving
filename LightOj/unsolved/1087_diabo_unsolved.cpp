#include<bits/stdc++.h>
#include <exception>
#include <stdio.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

#define MAXX 160000

int  data[MAXX*3];
int  tree[MAXX*3] ;
int queryLow=0;
int queryHigh=0;
int idx=0; int ghore = 0;
void initializeTree()
{
    for(int i=0;i<MAXX;i++)
    {
        data[i]=-1;
        tree[i]=0;
    }

}


void update(int low,int high,int pos)
{
   if(low<0 || high<0 || pos<0) printf("Something wrong\n");
   if(low>idx || high<idx) return;
   if(low==idx && idx==high)
   {
       tree[pos]+=1;
       return;
   }
   int mid = (high-low)/2+low;
   update(low,mid,pos*2);
   update(mid+1,high,pos*2+1);
   tree[pos]= tree[pos*2]+tree[pos*2+1];
}

int query(int low,int high,int pos)
{   //printf("Ghore re mona ghore %d\n",ghore++);
    if(low>queryHigh) return 0;
    if(queryLow<=low && high<=queryHigh) {return tree[pos];}
    int mid=(high-low)/2+low;
    int r1 = query(low,mid,pos*2);
    int r2 = query(mid+1,high,pos*2+1);
    return r1+r2;
}

int quer(int low,int high,int pos,int idxToRemove)
{
    int res1=query(low,high,pos); int res2=-1;
    while(res1!=res2)
    {
        queryHigh = idxToRemove+res1;
        res2 = query(low,high,pos);
        if(res1<res2) { res1=res2; res2=-1 ;}
        else if(res1==res2)
        {
            res1=res2; break;
        }
    }

    return res1;

}
int main()
{
    read ; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
       int numbrOfData; int nmbrOfQuery;
       scanf("%d %d",&numbrOfData,&nmbrOfQuery);
        printf("Case %d:\n",t);
       int idxOfLastData = numbrOfData;
       numbrOfData+=nmbrOfQuery;
       initializeTree();
       for(int i=1;i<=idxOfLastData;i++) scanf("%d",(data+i));
       for(int i=0;i<nmbrOfQuery;i++)
       {
          char operation[5];
          scanf("%s",operation);

          if(operation[0]=='c')
          {
                int idxToRemove;
                scanf("%d",&idxToRemove);
                queryLow = 1 ; queryHigh = idxToRemove;
                int res1=quer(1,numbrOfData,1,idxToRemove);
                int res = data[res1+idxToRemove];
                if(res!=-1)
                {  printf("%d\n",res);
                   idx = res1+idxToRemove ;
                   update(1,numbrOfData,1);
                }
                else printf("none\n");
          }

          else if(operation[0]=='a')
          {
                int dataToAdd; scanf("%d",&dataToAdd);
                ++idxOfLastData;
                //printf("idx of last : %d\n",idxOfLastData);
                data[idxOfLastData]=dataToAdd;
          }

       }
       queryLow = 0; queryHigh = 0; idx = 0;

    }

    return 0;
}

/* Test Cases
2
5 5
6 5 3 2 1
c 1
c 1
a 20
c 4
c 4
2 1
18811 1991
c 1



1

0 5

c 1
a 40
c 2
c 1
c 1
*/
