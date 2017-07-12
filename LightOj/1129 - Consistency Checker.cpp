#include<bits/stdc++.h>
#define read freopen ("in.txt","r",stdin);
#define write freopen ("out.txt","w",stdout);
using namespace std;

struct Node
{
    Node *children[10];
    bool flag;
    Node()
    {
        for(int i=0;i<10;i++) children[i] = NULL ;
    }
};

Node *root;
bool flag;

void insert(char *ch,int length)
{
    Node *temp = root;
    for(int i=0; i<length; i++)
    {
        int index = ch[i]-'0';
        if(temp->children[index]==NULL) temp->children[index]= new Node();
        temp->flag=0; temp = temp->children[index];
        if(temp->flag==1 )
        {
            flag = 0;    // If the Same word Exists Before
            break;
        }
    }
    temp->flag = 1;
}

void search(char *ch,int length)
{
    Node* temp= root;
    for(int i=0; i<length; i++)
    {
        temp = temp->children[ch[i]-'0'];
        if(temp->flag==1 && i<length-1)
        {
            flag=0; break;
        }
    }

}
int main()
{

    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d",&n);
        flag = 1;
        root = new Node();
        char ch[10000][11];
        for(int i=0; i<n; i++)
        {
            scanf("%s",ch[i]);
            insert(ch[i],strlen(ch[i]));
        }
        if(!flag) printf("Case %d: NO\n",t);
        else
        {
            for(int i=0; i<n; i++)
            {
                search( ch[i],strlen(ch[i]));
                if(!flag)
                {
                    printf("Case %d: NO\n",t); break;
                }
            }
            if(flag) printf("Case %d: YES\n",t);
        }
        free(root);
    }
    return 0;
}
