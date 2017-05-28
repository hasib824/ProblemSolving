#include<stdio.h>

using namespace std;
int main()
{
    int test_case=0;
    while(scanf("%d",&test_case)==1)
    {   int j=0;
        while(j<test_case)
        {
            int nmbr_of_data, nmbr_of_query;
            scanf("%d %d",&nmbr_of_data,&nmbr_of_query);
            int datas[nmbr_of_data+2];
            for(int i=0;i<nmbr_of_data;i++) scanf("%d",&datas[i]);
            printf("Case %d:\n",j+1);
            for(int i=0;i<nmbr_of_query;i++)
            {
                int segment_low,segment_high;
                scanf("%d %d",&segment_low,&segment_high);
                int low=0, high=nmbr_of_data-1, mid=0;
                int p_low=-1,p_high=-1;
                while(low<=high)
                {
                    mid = (low+high)/2;
                    if(datas[mid]<segment_low) low = mid+1;
                    else high = mid-1;
                }
                p_low = low;
                low=0, high=nmbr_of_data-1, mid=0;
                while(low<=high)
                {
                  mid = (low+high)/2;
                  if(datas[mid]<=segment_high){low = mid+1;}
                  else{high = mid - 1;}
                }
                p_high = low ;

                printf("%d\n",p_high-p_low);
                p_high=-1;p_low=-1; low=0; high=nmbr_of_data-1;
            }

            j++;
        }

    }
    return 0;
}


/**

5
5 3
1 4 6 8 10
0 5
6 10
7 100000

1
7 3
0 1 4 6 8 10 12
0 5
6 10
7 100000


1
10 3
2 4 9 12 23 25 38 42 45 55
19 37
26 37
8 40
**/
