#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx] == -1 )return NULL;
    Node *curNode = new Node(nodes[idx]);
    curNode->left = buildTree(nodes);
    curNode->right = buildTree(nodes);
    return curNode;
}

void preOrder(Node* root){
    if(root == NULL)return ;
    cout<<root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void kthHealper(Node* root,int k,int currLavel){

    if(root == NULL){
        return;
    }


    if(currLavel == k){
        cout<<root->data<<" ";
        return;
    }

    kthHealper(root->left,k,currLavel+1);
    kthHealper(root->right,k,currLavel+1);
}

void kthLavelElement(Node *root,int lavel){
   kthHealper(root,lavel,1);
}


int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    preOrder(root);
    cout<<"\nKth Lavel Element : "<<endl;
    kthLavelElement(root,3);
    return 0;
}