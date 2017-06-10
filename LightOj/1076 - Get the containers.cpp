#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)

using namespace std;

unsigned int get_result(unsigned int A[],int n,int low,unsigned long long int high,unsigned int container)
{
     unsigned int mid=(low+(high-low)/2);

    while(low<=high)
    {
        mid = (low+(high-low)/2);
        if(low == high) break;
        A[n]=mid;
        unsigned long long int sum=0; int cnt=0;
        for(int i=0;i<=n;i++)
        {
            if( (sum+A[i])<= mid )
            {
                sum+=A[i];
            }
            else { cnt+=1; sum=A[i]; }
        }

       // printf("low %d, High %llu, mid %u , cnt %d\n",low,high,mid,cnt);
        if(cnt>container) { low = mid+1; cnt=0;}
        else { high=mid; cnt=0;}

       // printf("Low %d, high %d\n",low,high);
    }

    return mid;
}

int main()
{
     read; write;
    int cases;
    scanf("%d",&cases);
    int t=0;
    while(t<cases)
    {
        int n; unsigned int containers;
        scanf("%d%u",&n,&containers);
        int low; unsigned int A[n+2]; scanf("%d",&low); A[0]=low;
        unsigned long long int sum=low;
        for(int i=1;i<n;i++)
        {
            scanf("%u",&A[i]); sum+=A[i];
            if(A[i]>low) low = A[i];
        }
       // printf("Low %d, high %d\n",low,sum);
        if(containers==1) printf("Case %d: %llu\n",++t,sum);
        else printf("Case %d: %u\n",++t,get_result(A,n,low,sum,containers));
    }
    return 0;
}
