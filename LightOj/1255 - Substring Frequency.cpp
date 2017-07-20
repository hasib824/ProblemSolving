#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

int len_text=0; int len_pattern=0;

int kmp(char text[],char pattern[],int A[])
{
    int cnt=0;
    int i=0; int j=0;
    while(j<len_text)
    {
       if(pattern[i]==text[j]) {i++;j++;} // if matches look for next character
       else  // if not match
       {
           if(i==0) j++;  // if pattern's index is zero then check for next character on "Text"
           else i=A[--i]; // if patterns index not zero then go to last matched position+1  on pattern
       }

       if(i==len_pattern)  // end of pattern means pattern found
        {
             i=A[--i]; // check for another pattern
            cnt++;  // pattern found
        }
    }
    return cnt;
}

void suffix_array(char pattern[],int A[])
{
    int i=0; int j=1;
    A[0]=0;
    while(j<len_pattern)
    {
       if(pattern[i]==pattern[j]) A[j++]= ++i; // if matches look for next character
       else // if not match
       {
           if(i==0) A[j++]=0; // if left index is "0" then go for next right index
           else i=A[--i];    // // if patterns index not zero then go to last matched position+1  on pattern
       }
    }

}

/*
void printarray(int A[])
{
    for(int i=0;i<len_pattern;i++)
           printf("%d , ",A[i]);
}
*/
int main()
{
     //read;
     //write;
    int tc;
    while(scanf("%d",&tc)==1)
    {
        for(int t=1;t<=tc;t++)
        {
             char text[1000005];
             char pattern[1000005];
             scanf("%s",&text); len_text = strlen(text);
             scanf("%s",&pattern); len_pattern = strlen(pattern);
             int A[len_pattern];
             suffix_array(pattern,A);
             // printarray();
             printf("Case %d: %d\n",t,kmp(text,pattern,A));

        }
    }
    return 0;
}

/*
acacabacacabacacac
*/
