#include<bits/stdc++.h>
using namespace std;

char text[1000005];
char pattern[1000005];
int A[1000005];

int len_text=0; int len_pattern=0;

int kmp()
{
    int cnt=0;
    int i=0; int j=0;
    while(j<len_text)
    {
       if(pattern[i]==text[j]) {i++;j++;}
       else
       {
           if(i==0) j++;
           else i=A[--i];
       }

       if(i==len_pattern) { cnt++; j-=i;}
    }

    return cnt;
}

void suffix_array()
{
    int i=0; int j=1;
    A[0]=0;
    while(j<len_pattern)
    {
       if(pattern[i]==pattern[j]) A[j++]= ++i;
       else
       {
           if(i==0) j++;
           else i=A[--i];
       }
    }

}

/*
void printarray()
{
    for(int i=0;i<len_text;i++)
           printf("%d , ",A[i]);
}
*/
int main()
{   int tc;
    while(scanf("%d",&tc)==1)
    {
        for(int t=1;t<=tc;t++)
        {
             scanf("%s",&text); len_text = strlen(text);
             scanf("%s",&pattern); len_pattern = strlen(pattern);
             suffix_array();
             printf("%d",kmp());

        }
    }
    return 0;
}

/*
acacabacacabacacac

*/

