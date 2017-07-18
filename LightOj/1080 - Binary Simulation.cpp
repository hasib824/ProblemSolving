#include<bits/stdc++.h>
#include <stdio.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

int const maxi = 3*100005;
char binary[maxi];
char tree[maxi];
char lazy[maxi];

void initialize()
{
    for(int i=0;i<maxi;i++)
    {
      binary[i] = '0';
      tree[i] = '0';
      lazy[i] = '0';
    }
}

void printTree(int length)
{
    for(int i=0;i<length;i++)
      printf("%d : %c , \n",i,tree[i]);
}

void buildTree(int low,int high,int pos)
{
   if(low==high) { tree[pos] = binary[low]; return; }
   int mid=(high-low)/2+low ;
   buildTree(low,mid,pos*2+1);
   buildTree(mid+1,high,pos*2+2);
}

void lazyHelper(int pos,int low,int high)
{

    if(tree[pos]=='0') tree[pos]='1';
    else tree[pos]='0';
    lazy[pos] = '0';
    if(low!=high) // if not a leaf
    {   int left= pos*2+1; int right = pos*2+2;
        if(lazy[left]=='0') lazy[left]='1';
        else lazy[left]='0';

        if(lazy[right]=='0') lazy[right]='1';
        else lazy[right]='0';
    }
}
void update(int low,int high,int pos,int updateLow,int updateHigh)
{   //printf("Ki problem\n");
    if(low>updateHigh || high<updateLow) return;

    if(lazy[pos]=='1') lazyHelper(pos,low,high);

    if(updateLow<=low && high<=updateHigh)
    {
       lazyHelper(pos,low,high);
        return;
    }
    int mid= (high-low)/2+low;
    update(low,mid,pos*2+1,updateLow,updateHigh);
    update(mid+1,high,pos*2+2,updateLow,updateHigh);
}
int in;
char query(int low,int high,int pos,int queryIndex)
{
    if(low>queryIndex || high<queryIndex) return '0';
    if(lazy[pos]=='1') lazyHelper(pos,low,high);
    if(low==high && low==queryIndex){ in = pos ;return tree[pos]; }

    int mid= (high-low)/2+low;

    query(low,mid,pos*2+1,queryIndex);
    query(mid+1,high,pos*2+2,queryIndex);

    return tree[in];

}

int main()
{
     //read; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
       int nmbrOfQuery;
       initialize();
       scanf("%s",binary);
       int length = strlen(binary); //printf("length %d : \n",length);
       buildTree(0,length-1,0); //printTree(length*3);
       scanf("%d",&nmbrOfQuery); getchar();
       printf("Case %d:\n",t);
       for(int i=0;i<nmbrOfQuery;i++)
       {
          char c=getchar();
          switch(c)
          {
             case 'I' :
                    int updateLow,updateHigh;
                   // printf("Kita hoise \n");
                    scanf("%d %d",&updateLow,&updateHigh); getchar();
                    update(0,length-1,0,updateLow-1,updateHigh-1);
                    break;
             case 'Q'  :
                    int queryIndex; scanf("%d",&queryIndex); getchar();
                    char res =query(0,length-1,0,queryIndex-1);
                    putchar(res); printf("\n");
                    break;

          }

       }
    }

    return 0;
}


/*
2
1011011101
15
I 2 9
Q 0
Q 1
Q 2
Q 3
Q 4
Q 5
Q 6
Q 7
Q 8
Q 9

2
1011011101
10
Q 0
Q 1
Q 2
Q 3
Q 4
Q 5
Q 6
Q 7
Q 8

2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5

1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
*/
