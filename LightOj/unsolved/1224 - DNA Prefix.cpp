#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* child[5];
    bool border;
    bool presence;

    Node()
    {
        for(int i=0; i<5; i++) child[i] = NULL;
        border = 0;
        presence = 0 ; // border 0 means in this node no word can make
        // presence 0 means there is no child in this 27 child array
    }
};

Node* head=NULL;
int getIndex(char ch)
{
    switch(ch)
    {
        case 'A' : return 0;
        case 'C' : return 1;
        case 'G' : return 2;
        case 'T' : return 3;

    }
}

char getCharacter(int index)
{
    switch(index)
    {
        case 0 : return 'A';
        case 1 : return 'C';
        case 2 : return 'G';
        case 3 : return 'T';

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
    temp->border = 1; // end of the word
}


char strings[55];
int l=0; int prefix=0; int maxi = -1;
int printTrie(Node* head)
{   int subset = 0 ;
    Node* temp = head;

    if(temp->presence==1)  // If other words have from this node
    {
        for(int i=0; i<4; i++)
        {
            if(temp->child[i]!=NULL)
            {   prefix++;
                strings[l++] = getCharacter(i);
                strings[l] = '\0';
                subset+=printTrie(temp->child[i]);
                if(maxi<prefix*subset) maxi=prefix*subset;
                //printf("%s subset : %d prefix %d\n",strings,subset,prefix);
            }
        }
    }
    prefix--;
    if(temp->border == 1) { subset++ ; printf("%s subset : %d\n",strings,subset); }
    strings[--l]='\0';
    return subset;
}

int main()
{
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

        printf("Printing the Trie : \n");
        printTrie(head); printf("Result %d\n",maxi);
         prefix=0;  maxi = -1;

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
