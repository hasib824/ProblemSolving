#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

int const maxi = 3*100005;

void initializeTree(int *tree,int *data,int n)
{ // printf("Ki hoile \n");
    for(int i=1;i<n;i++)
    {
        data[i]=-1;
        tree[i]=0;
    }
    // printf("Ajob kahani \n");
}

void update(int *tree,int low,int high,int pos,int idx)
{
   if(low>idx || high<idx) return;
   if(low==idx && idx==high)
   {
       tree[pos]+=1;
       return;
   }
   int mid = (high-low)/2+low;
   update(tree,low,mid,pos*2,idx);
   update(tree,mid+1,high,pos*2+1,idx);
   tree[pos]= tree[pos*2]+tree[pos*2+1];
}

int query(int *tree,int low,int high,int pos,int queryLow,int queryHigh)
{
    if(low>queryHigh) return 0;
    if(queryLow<=low && high<=queryHigh) return tree[pos];
    int mid=(high-low)/2+low;
    int r1 = query(tree,low,mid,pos*2,queryLow,queryHigh);
    int r2 = query(tree,mid+1,high,pos*2+1,queryLow,queryHigh);
    return r1+r2;
}
int main()
{
    read; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
       int numbrOfData,nmbrOfQuery;
       scanf("%d",&numbrOfData);
       scanf("%d",&nmbrOfQuery);
       //printf("n : %d\n",numbrOfData);
       //printf("q : %d\n",nmbrOfQuery);
       int idxOfLastData = numbrOfData; numbrOfData+=nmbrOfQuery;
       int data[3*numbrOfData]; data[0]=0;
       int tree[3*numbrOfData];
       //printf("kita hoise 2\n");
       initializeTree(tree,data,3*numbrOfData);
       //printf("kita hoise \n");
       for(int i=1;i<=idxOfLastData;i++) scanf("%d",&data[i]);
       //printf();
       printf("Case %d:\n",t);
       for(int i=0;i<nmbrOfQuery;i++)
       {  getchar();
          char operation;
          operation = getchar();
          if(operation=='c')
          {
                int idxToRemove;
                scanf("%d",&idxToRemove);
                int res1=query(tree,1,numbrOfData,1,1,idxToRemove); int res2=-1;
                //printf("for %d ",idxToRemove,resddd);
                while(res1!=res2)
                {
                    res2 = query(tree,1,numbrOfData,1,1,idxToRemove+res1);
                    if(res1!=res2) { res1=res2; res2=-1 ;}
                }
                int res = data[res1+idxToRemove];
                if(res!=-1)printf("%d\n",res);
                else printf("none\n");
                /*for(int i=0;i<3*numbrOfData;i++)
                {
                    printf("%d : %d data[%d] : %d\n",i,tree[i],i,data[i]);
                }*/
                update(tree,1,numbrOfData,1,res1+idxToRemove);

          }

          else if(operation=='a')
          {    // printf("Agdom\n");
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
