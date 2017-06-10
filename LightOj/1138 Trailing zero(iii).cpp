#include<stdio.h>
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)

using namespace std;




unsigned long long int getZero(unsigned long long int n)
{

}

unsigned long long int solve(unsigned int n)
{   unsigned long long int high= 100000000000;// printf("N %d\n",n);
    int low =0;
    unsigned long long int mid=-1;
    while(low<=high)
    {
       mid = low + (high-low)/2;
       unsigned long long int t=5;
       unsigned long long int ans = 0;
        while(t<=mid)
        {
             ans += mid/t;
             t*=5;
            // printf("Kemne ki\n");
        }
       if( (low==high) && ans==n )
        {
          //printf("n : %d  ans :%d ",n, ans);
          return mid;
        }
       else if(ans==n) high = mid;
       else if(ans>n) high=mid-1;
       else if(ans<n) low = mid+1;
       //printf("Koi ghore ? \n");
    }
   return -1;
}

int main()
{   //write;
    int tc;
   // printf("%llu",hi);
    scanf("%d",&tc);
    int i=0;
    while(i<tc)
    {   unsigned int n; unsigned long long int res;
        scanf("%u",&n); res = solve(n);
        printf("Case %d: ",++i);
        if(res==-1) printf("impossible\n");
        else printf("%llu\n",res);
    }
    return 0;
}
