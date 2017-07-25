/*
Segment tree problem
practice on khata link : https://drive.google.com/file/d/0B_wpV0CZvtDbamtjbk9SMHQybFE/view?usp=sharing


*/

#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

struct Node
{
   int max,min ;
   Node(int nmbr)
   {
       max = nmbr ; min = nmbr ;
   }
};

int const n= 400100;
Node *tree[n];
int nmbrOfData=0,timeLimit=0;
int queryLow=0,queryHigh=0;


void initializeTree()
{
    for(int i=0;i<n;i++)
        tree[i]=NULL;
}

Node* getMaxMin(Node* left,Node* right)
{
   Node* temp = new Node(0);
   if(left->max > right->max ) temp->max = left->max ;
   else temp->max = right->max ;
   if(left->min < right->min ) temp->min = left->min ;
   else temp->min = right->min;

   return temp;

}

void buildTree(int low,int high,int pos)
{
    if(low==high) // leaf node
    {
        int data; scanf("%d",&data); // Scan and input the data exactly in the position of segment tree
        tree[pos] = new Node(data);
        return ;
    }
    int mid = (high-low)/2+low;
    buildTree(low,mid,pos*2+1);
    buildTree(mid+1,high,pos*2+2);
    tree[pos]=getMaxMin(tree[pos*2+1],tree[pos*2+2]);

}

Node* query(int low,int high,int pos)
{
   if(low>queryHigh || high<queryLow)
   {
      Node* temp = new Node(0);
      temp->max = 0; temp->min = 100001000;
      return temp;
   }
   if(queryLow<=low && high<=queryHigh)
   {
       Node* temp = new Node(0); // took a completely different node beacuse we will Free the memory later ;
       temp->max= tree[pos]->max;
       temp->min= tree[pos]->min;
       return temp;
   }

   int mid = (high-low)/2+low;
   Node* left=query(low,mid,pos*2+1);
   Node* right=query(mid+1,high,pos*2+2);
   Node* temp = getMaxMin(left,right);
   delete left; delete right;  // freeing the memory allocated on heap
   left =NULL;  right = NULL;
   return temp;

}


int main()
{
    //read;write;

    int tc;
    scanf("%d",&tc);
    initializeTree();
    for(int t=1;t<=tc;t++)
    {
       scanf("%d %d",&nmbrOfData,&timeLimit);
       buildTree(0,nmbrOfData-1,0);
       int maxResult=-1;
       int limit = nmbrOfData-timeLimit;
       for(int i=0;i<=limit;i++)
       {
           queryLow = i;
           queryHigh = i+timeLimit-1;
           Node* res = query(0,nmbrOfData-1,0);
           int large =res->max-res->min ;
           if(maxResult<large) maxResult= large;
           delete res; res=NULL;
       }
       printf("Case %d: %d\n",t,maxResult);

       for(int i=0;i<n;i++)  // freeing the memory allocated on heap
       {
           if(tree[i]!=NULL)
           {
             delete tree[i];
             tree[i]=NULL;
           }
       }
    }
    return 0;
}

/* Test Cases

3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1

*/
