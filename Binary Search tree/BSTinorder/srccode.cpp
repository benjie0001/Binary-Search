#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////YOUR CLASS IMPLEMENTATION GOES HERE/////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node *root=this;
    Node *root2=this;
    Node(int input)//constructor
    {
        value=input;
        left=NULL;
        right=NULL;
    }
    void insert(int fruit)//method for inserting
    {
        if(fruit <=root->value)
        {
            if(root->left==NULL)
            {
                root->left=new Node(fruit);
            }
            else
            {
                root= root->left;
                this->insert(fruit);//recursive call
            }
            root=this;
        }
        else
        {
            if(root->right==NULL)
            {
                root->right=new Node(fruit);
            }
            else
            {
                root=root->right;
                this->insert(fruit);
            }
            root=this;
        }


    }
    void inOrder()//left subtree->root->right subtree
    {
        if(root2==NULL)//if root is empty
        {
            return;
        }
        root2=this->left;
        if(root2!=NULL)//visit the left subtree
        {
            root2->inOrder();//using a recursive function
        }
        cout<<this->value<<" ";
        root2=this->right;//visit right subtree and apply recursive call
        if(root2 !=NULL)
        {
            root2->inOrder();
        }

    }
};
int main()
{
    // Upon creating a tree it has to have at least one node with a value
    Node *myTree = new Node(4);

    // insert some elements
    myTree->insert(2); myTree->insert(6); myTree->insert(1);myTree->insert(3); myTree->insert(5);myTree->insert(7);

    // carry out the traversal
    myTree->inOrder(); // output should be: 1 2 3 4 5 6 7

}
