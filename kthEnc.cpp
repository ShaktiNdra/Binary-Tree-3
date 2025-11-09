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

int kthEnc(Node* root,int n1,int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == n1){
        return 0;
    }

    int l = kthEnc(root->left,n1,k);
    int r = kthEnc(root->right,n1,k);

    if(l==-1 && r==-1){
        return -1;
    }

    int validval = l==-1 ? r:l;

    if(validval +1 ==k){
        cout<<"kth ancesiter "<<root->data;
    }

    return validval+1;
}

int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    preOrder(root);

    cout<<"\nLCA : "<<kthEnc(root,4,2);
   
}