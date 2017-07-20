#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

int const maxi = 3*100000;

int data[3*maxi];
int tree[3*maxi];

void initializeTree()
{
    for(int i=0;i<maxi;i++)
    {
        data[i]=-1;
        tree[i]=0;
    }

}

void update(int low,int high,int pos,int idx)
{
   if(low>idx || high<idx) return;
   if(low==idx && idx==high)
   {
       tree[pos]+=1;
       return;
   }
   int mid = (high-low)/2+low;
   update(low,mid,pos*2,idx);
   update(mid+1,high,pos*2+1,idx);
   tree[pos]= tree[pos*2]+tree[pos*2+1];
}

int query(int low,int high,int pos,int queryLow,int queryHigh)
{
    if(low>queryHigh) return 0;
    if(queryLow<=low && high<=queryHigh) return tree[pos];
    int mid=(high-low)/2+low;
    int r1 = query(low,mid,pos*2,queryLow,queryHigh);
    int r2 = query(mid+1,high,pos*2+1,queryLow,queryHigh);
    return r1+r2;
}
int main()
{
    //read; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
       int numbrOfData,nmbrOfQuery;
       scanf("%d",&numbrOfData);
       scanf("%d",&nmbrOfQuery);
       int idxOfLastData = numbrOfData;
       numbrOfData+=nmbrOfQuery; // beacuse "nmbrOfQuery-1" numbers can be add
       initializeTree();
       for(int i=1;i<=idxOfLastData;i++) scanf("%d",&data[i]);
       printf("Case %d:\n",t);
       for(int i=0;i<nmbrOfQuery;i++)
       {
          char operation;
          scanf(" %c",&operation);
          if(operation=='c')
          {
                int idxToRemove;
                scanf("%d",&idxToRemove);
                int res1=query(1,numbrOfData,1,1,idxToRemove); int res2=-1;
                while(res1!=res2)   // Getting the exact index , beacuase the pointing index might have been removed
                {
                    res2 = query(1,numbrOfData,1,1,idxToRemove+res1);
                    if(res1<res2) { res1=res2; res2=-1 ;}
                    else if(res1==res2) res1=res2;
                }
                int res = data[res1+idxToRemove];
                if(res!=-1)
                {  printf("%d\n",res);
                   // if the number is removed then this index number can be found "res1+idxToRemove" th index
                   update(1,numbrOfData,1,res1+idxToRemove);
                }
                else printf("none\n"); // not updating the index beacause there is no number

          }

          else if(operation=='a')
          {
                int dataToAdd; scanf("%d",&dataToAdd);
                data[++idxOfLastData]=dataToAdd;
          }



       }
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
*/
