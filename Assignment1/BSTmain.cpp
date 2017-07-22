#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Position{
    int index;
    Position* next;
};

struct Node{
    string data;
    int ascii;
    int totalIndex;
    Node* left;
    Node* right;
    Position* pos;

};
int c=1;
Node* root=NULL;

// Complexity O(n)
Position* addIndex(Position* p, int indx)
{
    Position* tem=new Position();
    tem->index = indx;
    tem->next = NULL;
    if(p==NULL)
    {
         p = tem;
        return p;

    }else
    {
        Position* temRoot=p;
        while(temRoot->next!=NULL)
        {
            temRoot=temRoot->next;
        }
        temRoot->next=tem;

        return p;
    }
}

// Complexity O(n)
void DisplayPosition(Position* position)
{
    Position* tPos=position;
    while (tPos != NULL)
    {
        cout<<tPos->index<< " ";
        tPos=tPos->next;
    }
}

// Complexity O(n)
void Insert(string data, int ascii)
{
    Node *ptr;
    Node *ptr_parent;

    if(root == NULL)
    {
        //The BST is Empty...

        Node *newNode = new Node;
        newNode -> data = data;
        newNode->ascii = ascii;
        newNode->totalIndex =1;
        newNode->pos =NULL;
        newNode -> left = NULL;
        newNode -> right = NULL;

        root = newNode;

        root->pos=addIndex(newNode->pos,c);

        ptr = root;


    } else { //traversing the tree to find the insertion point
        ptr = root;
        while(ptr != NULL)
        {
            if((ptr -> ascii) == ascii && ((ptr->data).compare(data)==0)) {
                ptr->totalIndex++;
                ptr->pos=addIndex(ptr->pos,++c);

                return;
            } //to check for duplicates

            if(ascii < (ptr -> ascii))
            {
                ptr_parent = ptr;
                ptr = ptr -> left;
            } else {
                ptr_parent = ptr;
                ptr = ptr -> right;
            }
        }
        Node *newNode = new Node;

        newNode -> data = data;
        newNode->ascii=ascii;
        newNode->totalIndex =1;
        newNode -> left = NULL;
        newNode -> right = NULL;
        newNode->pos =NULL;

        newNode->pos=addIndex(newNode->pos,++c);

        //cout<<"first ptr:" <<ptr_parent->ascii<<endl;

        //checking for parent value to determine if
        //the Node is a left or right child
        if(ascii < (ptr_parent -> ascii))
            ptr_parent -> left = newNode;
        else
            ptr_parent -> right = newNode;
    }
}

bool Search(Node* root,int ascii)
{
    if(root ==NULL){
        return false;
    }else if (ascii == root-> ascii){
        return true;
    }else if(ascii < root->ascii)
    {
        return Search(root->left,ascii);
    }else{
        return Search(root->right,ascii);
    }
}

// Complexity O(n)

void Print (Node * x,int count)
{

    if ( x != NULL )
    {


        cout <<x->data<<" : "<< (double)(x->totalIndex)/count <<" pos: ";
        DisplayPosition(x->pos);
        cout<<endl;
        Print (x->left,count);
        Print (x->right,count);

    }

    return;
}


// Complexity O(n^2)


int main(int argc, char* argv[])
{
    //int argc, char* argv[]
    ifstream file;
    string filename=argv[1];
    file.open(filename,std::fstream::out);

    string s;
    int ascChar=0;
    cout<<endl;
    int sum=0;
    int count=0;
    if(file.is_open()){

        while(file >> s)
        {

            transform(s.begin(), s.end(), s.begin(), ::tolower);

            int sizes=s.size();
            if(s[sizes-1] == ',' || s[sizes-1] == '.')
            {
                string newWord(&s[0], &s[sizes-1]);
                s=newWord;
            }


            for (int i=0;i<s.length();i++)
            {
                ascChar = s[i];
                sum=sum+ascChar;
            }

            Insert(s,sum);
            sum=0;

            count++;


        }

        cout<<"Total number of words: "<<count<<endl<<endl;

        cout<<"Word frequencies and Positions : "<<endl<<endl;

        Print(root,count);

    }

}