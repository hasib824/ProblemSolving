#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)

using namespace std;

void BSearch(int A[],int n,int day,int low,int high,int tc)
{
   int mid=0; int res[day+n];
   int j=0;
   while(low<=high)
   {
       mid=low+(high-low)/2;
     // mid=39;
      //low=39;high=39;
      int cnt=0; int sum=0;
      A[n]=mid;
      j=0;
      for(int i=0;i<=n;i++)
      {
         //printf("%d diff %d i : %d j :%d\n",n-i,day-j,i,j);
         if(sum+A[i]>mid)
         {
             res[j++]=sum;
             sum=0; cnt++;
         }
         if(n-i > day-j)
         {
             //printf("In \n");
            if(sum+A[i]<=mid)
             {
                 sum+=A[i];
             }
         }
         else if(i<n)
         {
             res[j++]=sum+A[i];
             sum=0; cnt++;
           //  printf("    Lefting \n");
         }
         //printf("After %d diff %d i : %d j :%d\n",n-i,day-j,i,j);
      }
      if(high==low && cnt==day) break;
      if(cnt<day) high=mid-1;
      else if(cnt>day) low=mid+1;
      else high=mid;
   }
   printf("Case %d: %d\n",tc,mid);
   for(int i=0;i<day;i++)
   {
      printf("%d\n",res[i]);
   }
}


void solve(int tc)
{
    int camp,night;
    scanf("%d %d",&camp,&night);
    int A[camp+5]; int low=-1; int high=0;
    for(int i=0;i<=camp;i++)
    {
       scanf("%d",&A[i]);
       if(A[i]>low) low=A[i];
       high+=A[i];
    }

    if(camp==night)
    {
        printf("Case %d: %d\n",tc,low);
       for(int i=0;i<=camp;i++)
       {
          printf("%d\n",A[i]);
       }
    }
    else
    {
      BSearch(A,++camp,++night,low,high,tc);
    }


}

int main()
{   //read;
   // write;
    int tc; scanf("%d",&tc);
    int t=0;
    while(t<tc)
    {
        solve(++t);
    }
    return 0;
}




/*
2
12 9
4
39
24
18
20
22
25
6
29
14
11
15
15



*/
