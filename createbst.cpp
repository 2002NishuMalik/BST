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

int main()
{
    Node* root = NULL;
    cout <<" enter the data for node: "<<endl;
    takeInput(root);
    return 0;
}