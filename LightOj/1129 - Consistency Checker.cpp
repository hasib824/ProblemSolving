#include<bits/stdc++.h>
#define read freopen ("in.txt","r",stdin);
#define write freopen ("out.txt","w",stdout);
using namespace std;

struct Node
{
    Node *children[10];
    bool flag;
    bool presence;
    Node()
    {
        for(int i=0; i<10; i++) children[i] = NULL ;
    }
};
Node *root=NULL;
bool flag=1;

void insert(char *ch,int length)
{
    Node *temp = root;
    for(int i=0; i<length; i++)
    {
        int index = ch[i]-'0';
        if(temp->children[index]==NULL)
        {
            temp->presence = 1;
            temp->children[index]= new Node;
            temp->children[index]->flag=0; // Word is not completed yet
            temp->children[index]->presence = 0; // No other word from along this path
        }
        temp = temp->children[index];
        if(temp->flag==1 ) // If the Same word Exists Before
        {
            flag = 0; break;
        }
    }
    temp->flag = 1;
    if(temp->presence==1) flag=0;
}

void delete_memory(Node * root)
{
    for(int i=0; i<10; i++)
         if(root->children[i]!=NULL)
            delete_memory(root->children[i]);
    delete root; root = NULL ;
}

int main()
{
    //read; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d",&n);
        flag = 1;
        root = new Node;
        char ch[n+1][11];
        for(int i=0; i<n; i++)
        {
            scanf("%s",ch[i]);
            insert(ch[i],strlen(ch[i]));
        }
        if(flag) printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
        delete_memory(root);

    }

    return 0;
}
