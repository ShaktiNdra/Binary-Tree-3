#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1)return NULL;
    Node* curNode = new Node(nodes[idx]);
    curNode->left = buildTree(nodes);
    curNode->right = buildTree(nodes);
    return curNode;
}

void preOrder(Node* root){
    if(root == NULL)return;
    cout<<root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* LCA(Node* root,int n1,int n2){

    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node *leftLCA = LCA(root->left,n1,n2);
    Node *rightLCA = LCA(root->right,n1,n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}


int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    preOrder(root);

    cout<<"\nLCA : "<<LCA(root,4,5)->data;
   
}