/*
    Just a State Forward Segment tree operation .
    Best tutorial :https://www.youtube.com/results?search_query=tushar+roy+lazy+propagation

    used Big size array because
    every update value can be at max = 1000
    update range can be 0 to 100000
    total Number of Update operation can be = 50000
    So :  1000*100000*50000 = 500000000000

*/

#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)

using namespace std;

const int n= 500000;

unsigned long long int tree[n];
unsigned long long int lazy[n];
unsigned updateLow=0, updateHigh=0, value=0;
unsigned queryLow=0, queryHigh=0;
void init()
{
   for(int i=0;i<n;i++)
   {
       tree[i] = 0;
       lazy[i] = 0;
   }
}

void lazyHelper(unsigned int low,unsigned int high,unsigned int pos)
{
    tree[pos] += (high-low+1)*lazy[pos];
    if(low!=high)
    {
        lazy[pos*2+1] += lazy[pos];
        lazy[pos*2+2] += lazy[pos];
    }
    lazy[pos] = 0 ;
}

void update(unsigned int low,unsigned int high,unsigned int pos)
{
    if(lazy[pos] >0) lazyHelper(low,high,pos);
    if(low>updateHigh || high<updateLow) return ;
    if(updateLow<=low && high<=updateHigh)
    {
        tree[pos]+=(high-low+1)*value;
        //printf("Pos %d, high  %d, low %d, value %d\n",pos,high,low,tree[pos]);
        if(low!=high)
        {
            lazy[pos*2+1] += value;
            lazy[pos*2+2] += value;
        }
        return;
    }
    unsigned mid = (high-low)/2+low;
    update(low,mid,pos*2+1);
    update(mid+1,high,pos*2+2);

    tree[pos] = tree[pos*2+1]+tree[pos*2+2];
}

unsigned long long int query(unsigned int low,unsigned int high,unsigned int pos)
{
    if(lazy[pos] > 0) lazyHelper(low,high,pos);
    if(low>queryHigh || high<queryLow) return 0;
    if(queryLow<=low && high<=queryHigh)
      {   // printf("on Query Pos %d, high  %d, low %d, value %d\n",pos,high,low,tree[pos]);
          return tree[pos];
      }

    unsigned int  mid = (high-low)/2+low;
    unsigned long long  int r1 = query(low,mid,pos*2+1);
    unsigned long long  int r2 = query(mid+1,high,pos*2+2);

    return r1+r2;

}


int main()
{
    //read; write;
    int tc;
    scanf("%d",&tc);
    int t=0;
    for(t=1;t<=tc;t++)
    {   init();
        unsigned int nmbrOfData,nmbrOfQuery;
        scanf("%u%u",&nmbrOfData,&nmbrOfQuery);
        printf("Case %d:\n",t);
        for(int i=0;i<nmbrOfQuery;i++)
        {
            int op; scanf("%d",&op);
            switch(op)
            {
                case 0 :
                    scanf("%u%u%u",&updateLow,&updateHigh,&value);
                    update(0,nmbrOfData-1,0); //printf("Ajib\n");
                    break;
                case 1 :
                    scanf("%u%u",&queryLow,&queryHigh);
                    printf("%llu\n",query(0,nmbrOfData-1,0));
                    break;

            }
            updateLow=0; updateHigh=0; value=0;
            queryLow=0; queryHigh=0;

        }

    }
    return 0;
}

/*

2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19



2
10 5
0 0 9 10
1 0 9
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19




*/
