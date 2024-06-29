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

void lot(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        if(temp == NULL)
        {
            cout<< endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if(root->left)
            {
                q.push(root->left);
            }
            if(root->right)
            {
                q.push(root->right);
            }
        }
    }
}

bool findNodeInBST(Node* root, int target)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data == target)
    {
        return true;
    }
    if(root->data < target)
    {
        return findNodeInBST(root->right, target);
    }
    else{
        return findNodeInBST(root->left, target);
    }
}

int main()
{
    Node* root = NULL;
    cout <<" enter the data for node: "<<endl;
    takeInput(root);
    cout << "printing the tree:" <<endl;
    lot(root);
    bool ans = findNodeInBST(root, 14);
    cout<< "present or not" <<ans << endl; 
    return 0;
}