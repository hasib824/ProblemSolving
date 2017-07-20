#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

int len_text=0; int len_pattern=0;

int variation(char text[])
{   char alphabet[26]; int cnt=0;
    for(int i=0;i<len_text;i++) alphabet[i]=0;
    for(int i=0;i<len_text;i++)
    {
       int a=text[i]%97; //printf("%d, %c, ",a,text[i]);
       if(alphabet[a]==0) { alphabet[a]=1; cnt++;}
    }

   return cnt;
}

void suffix_array(char pattern[],int A[])
{
   int i=0;int j=1; A[0]=0;
   while(j<len_pattern)
   {
       if(pattern[i]==pattern[j]) A[j++]= ++i;
       else
       {
           if(i>0) i=A[--i];
           else A[j++]=0;
       }
   }

}

int kmp(char pattern[],char text[],int A[])
{
    int i=0;int j=0; int cnt=0;
    while(j<len_text)
    {
       if(pattern[i]==text[j]) { i++,j++; }
       else
       {
           if(i>0) i=A[--i];
           else j++;
       }
       if(i==len_pattern) { i=A[--i]; cnt++;}
    }
    return cnt;
}

int result(int n,int var,int match)
{
    int diff = n-var; printf("Diff %d\n",diff);
    if( diff == 0) { printf("Execute 1\n"); return (n*(n+1)/2)-match; }
    else if( diff == 1) {  printf("Execute 2\n"); return ( (n*(n+1)/2)-1 )-match;}
    else if (diff>1) { printf("Execute 3\n"); return ( (n*(n+1)/2)-(1+(diff*(diff-1)/2) ))-match; }
}

/*void printarray(int A[])
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
             char text[5005];
             char pattern[5005];
             scanf("%s",&text); len_text = strlen(text);
             scanf("%s",&pattern); len_pattern = strlen(pattern);
             int A[len_pattern];
             suffix_array(pattern,A);
             //printarray(A);
             int var = variation(text);
             int match= kmp(pattern,text,A);
             int res=result(len_text,var,match);
             printf("hasib : %d match %d result %d\n",var,match,res);

            // printf("Case %d: %d\n",t,kmp(text,pattern,A));

        }
    }
    return 0;
}

/*
4
acacabacacabacacac
acacabacacabacacac

4
abaa
ba
*/
