#include <iostream>

using namespace std;
////////////////////////////////////////////////////////////////////
/////////////////////////YOUR CODE GOES HERE////////////////////////
////////////////////////////////////////////////////////////////////


class Node
{
public:
    // Initalize static variable (which should belong to the Node class)

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
    int counter=0;

    Node *root5=this;//used with search method
    int search(int fruit)
    {
        if(fruit==this->value)
        {

            counter=0;
            return counter;
        }
        else if(fruit< this->value)
        {
            root5->counter++;
            root5=this->left;
            if(root5!=NULL)
            {
                root5->search(fruit);
            }
            else//fruit does not exist
            {
                counter=0;
                return -1;
            }
        }
        else if(fruit>this->value)
        {
            root5->counter++;
            root5=this->right;
            if(root5!=NULL)
            {
                root5->search(fruit);
            }
            else
            {
                return -1;
            }
        }
    }
};
int main()
{
    Node *myTree = new Node(4); // NB: we begin with myTree having one element

    // insert some elements
    myTree->insert(2); myTree->insert(6);myTree->insert(1);
    myTree->insert(3);myTree->insert(5);myTree->insert(7);myTree->insert(8);

    /*
        DRAW THE TREE THAT RESULTS FROM THE INSERTIONS ABOVE IN ORDER TO VISUALIZE THE EXAMPLES GIVEN BELOW.
        REMEMBER IT IS A BST, SO FOLLOW THE BST RULES WHILE INSERTING.
        NB: A TREE DIFFERENT FROM THIS ONE WILL BE USED TO TEST YOUR CODE.
    */

    int numHops;
    numHops = myTree->search(4);
    cout << "Number of hops: " << numHops << endl; // numHops should be 0 since 4 is the root node

    numHops = myTree->search(2);
    cout << "Number of hops: " << numHops << endl; // numHops should be 1 since it takes just 1 hop to get to 2

    numHops = myTree->search(7);
    cout << "Number of hops: " << numHops << endl; // numHops should be 2 since it takes 2 hops to get to 7

    numHops = myTree->search(8);
    cout << "Number of hops: " << numHops << endl; // numHops should be 3 since it takes 3 hop to get to 8

    numHops = myTree->search(10);
    cout << "Number of hops: " << numHops << endl; // numHops should be -1 since 10 is not in the tree

}
