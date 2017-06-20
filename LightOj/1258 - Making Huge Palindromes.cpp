#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

char first[1000009];
char r[1000009];
int arr[1000009];
int l;
void rever()
{
   l= strlen(first)-1;
   for(int i=l;i>=0;i--) r[l-i] = first[i];
   l++;
}

void suffix_array()
{
    int i=0;int j=1; arr[0]=0;
    while(j<l)
    {
       if(r[i]==r[j]) arr[j++] = ++i;
       else {
           if(i>0) i=arr[--i];
           else j++;
       }
    }

}

int kmp()
{
   int i=0;int j=0;
   while(i<l)
   {
       if(r[j]==first[i]) { i++; j++; }
       else
       {
           if(j>0) j=arr[--j];
           else i++;
       }

   }

   return l+(l-j);
}

void print()
{
   for(int i=0;i<l;i++) printf("%d, ",arr[i]);
}

int main()
{   //write;
    int ts;
    scanf("%d",&ts);
    for(int i=1;i<=ts;i++)
    {
       scanf("%s",&first); rever();
       //printf("%s",r);
       suffix_array(); // print();
       printf("Case %d: %d\n",i,kmp());

    }
    return 0;
}


/*
7
aaaaaaaaaaaaaz
abbbbaaaa
abababccbaba
xxxyxyyxyxxxxxxxyyxxxxxxxyxxxxxxyxxxyxxxxxxxyxxxxx
vpltefcfetlpvv
fjbibjeralarejbibjff
ecbgcefecgddbdbbbdbddgcefecgbcee

*/
