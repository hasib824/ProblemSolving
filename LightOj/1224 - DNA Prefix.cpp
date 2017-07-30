/*
Basic Trie problem .

key idea : Protita letter travarse er pore count korte hobe je , aikhan theke
           total koyta word create hoyeche. total word er sathe oi letter porjonto
           prefix number multiply korle number result paowa jabe .
           Amon onek golo result er majhe MAx result ta e hobe final answer.


*/

#include<bits/stdc++.h>
#define read freopen("in.txt","r",stdin);
#define write freopen("out.txt","w",stdout);
using namespace std;

struct Node
{
    Node* child[5];
    int border;
    bool presence;
    Node()
    {
        for(int i=0; i<5; i++) child[i] = NULL;
        border = 0;  // border 0 means in this node no word can make
        presence = 0 ; // presence 0 means there is no child in this 27 child array
    }
};

Node* head=NULL;
int getIndex(char ch)  // only 4 characters, So used a switch to minimize the memory size
{
    switch(ch)
    {
    case 'A' :
        return 0;
    case 'C' :
        return 1;
    case 'G' :
        return 2;
    case 'T' :
        return 3;

    }
}

void buildTrie(char *str,int length)
{
    Node* temp = head;
    for(int i=0; i<length; i++)
    {
        int index = getIndex(str[i]);
        if(temp->child[index]==NULL)
        {
            temp->child[index] = new Node;
            temp->presence = 1; // there is at least one child in the parent
        }
        temp = temp->child[index];
    }
    temp->border += 1; // end of the word . But can be many word end here .
}



int prefix=0;
int maxi = -1;
int printTrie(Node* head)
{
    int subset = 0 ;
    Node* temp = head;
    if(temp->presence==1)  //if at least one word available  enter the loop , otherwise ignore the loop .
    {
        for(int i=0; i<4; i++)
        {
            if(temp->child[i]!=NULL)
            {
                prefix++;
                subset+=printTrie(temp->child[i]);
                temp->child[i] = NULL;
            }
        }
    }

    if(temp->border > 0)
        subset+=temp->border ; // If more than One word ends here
    if(maxi<prefix*subset) maxi=prefix*subset;  // calculating max value
    prefix--; // going back to parent node so decrementing number of prefix
    delete temp;
    return subset;
}

int main()
{
    //read; write;
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        head = new Node();
        int nmbrOfString;
        scanf("%d",&nmbrOfString);
        for(int i=0; i<nmbrOfString; i++)
        {
            char str[55];
            scanf("%s",str);
            buildTrie(str,strlen(str));
        }
        printTrie(head);
        printf("Case %d: %d\n",t,maxi);
        head = NULL;
        prefix=0;
        maxi = -1;

    }
    return 0;
}

/*


3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT

3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC

2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC

*/
