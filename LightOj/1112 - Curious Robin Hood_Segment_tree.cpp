// problem link :
// http://www.lightoj.com/volume_showproblem.php?problem=1112

#include<stdio.h>
#include <string.h>
#define size 100005
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
using namespace std;

int tree[size];
int n;

void update(int pos,int num)
{

}

int b_query(int i)
{


}


int main()
{
  //write;
  int cases; scanf("%d",&cases);
  int t=0;
  while(t<cases)
  {  t++;
     int query; scanf("%d %d", &n,&query);
     int A[n+1];
     for(int i=0;i<=n+5;i++) tree[i]=0; // Initialize with 0
     for(int i=0;i<n;i++)  // Scanning and Building the Tree at a time
     {
        scanf("%d",&A[i]); update(i+1,A[i]);
     }
     printf("Case %d:\n",t);
     for(int q=0;q<query;q++)
        {
         int sign=0; scanf("%d",&sign);
             switch(sign)
             {
               case 1 :
                   int i ; scanf("%d",&i);
                   printf("%d\n",A[i]);
                   update(i+1,0-A[i]); A[i]=0;  break;
               case 2 :
                   int a,b; scanf("%d %d",&a,&b); A[a]+=b; a++;
                   update(a,b);  break;
               case 3 :
                   int k,l; scanf("%d %d",&k,&l);
                   int res = b_query(l+1)-b_query(k) ;
                   printf("%d\n", res ); break;
             }
        }

  }
  return 0;
}


/*
1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1


*/
