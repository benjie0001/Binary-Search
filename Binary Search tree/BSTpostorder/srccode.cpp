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
    Node *root=this;//used for insert method
    Node *root2=this;//used for inorder method
    Node *root3=this;//used for preOrder method
    Node *root4=this;//used for postorder method
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
    void preOrder()
    {
        if(root3==NULL)//if root is empty
        {
            return;
        }
        cout<<this->value<<" ";
        root3=this->left;//assigned address to the left subtree/leaf
        if(root3!=NULL)
        {
            root3->preOrder();//recursive call to preorder function
        }
        root3=this->right;//assigned address to the right subtree of root
        if(root3!=NULL)
        {
            root3->preOrder();//recursive call to preOrder function
        }
    }
    void postOrder()//right->root->left
    {
        if(root4==NULL)
        {
            return;
        }

        root4=this->left;//assigned address of subtree to the left
        if(root4!=NULL)
        {
            root4->postOrder();
        }
        root4=this->right;
        if(root4!=NULL)
        {
            root4->postOrder();
        }
        cout<<this->value<<" ";//print statement comes after."post" order


    }
};
int main()
{
    // Upon creating a tree it has to have at least one node with a value
    Node *myTree = new Node(4);

    // insert some elements
    myTree->insert(2); myTree->insert(6); myTree->insert(1);myTree->insert(3); myTree->insert(5);myTree->insert(7);

    // carry out the traversal
    myTree->postOrder(); // output should be: 1 3 2 5 7 6 4

}

