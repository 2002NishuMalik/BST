#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInToBST(Node* & root, int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(root->data > data)
    {
        root->left = insertInToBST(root->left, data);
    }
    else
    {
        root->right = insertInToBST(root->right, data);
    }
    return root;
}


void takeInput(Node* &root)
{
    int data;
    cin >> data;
    while(data!=-1)
    {
        root = insertInToBST(root, data);
        cin >> data;
    }
}
void levelordertraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data;
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void convertInToSortedLL(Node* root, Node*& head)
{
    if(root == NULL)
    {
        return ;
    }

    convertInToSortedLL(root->right, head);

    root->right = head;

    if(head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertInToSortedLL(root->left, head);
}

void printLL(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp = temp->right;
    }
    cout << endl; 
}

int main()
{
    Node* root = NULL;
    cout <<" enter the data for node: "<<endl;
    takeInput(root);
    cout << "printing the tree:" <<endl;
    levelordertraversal(root);
    cout << "printing inorder traverse:"<<endl;
    inorder(root);

    Node* head = NULL;
    convertInToSortedLL(root, head);
    printLL(head);
    return 0;
}