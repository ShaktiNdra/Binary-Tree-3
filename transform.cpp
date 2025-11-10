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

int transform(Node *root){
    if(root == NULL) return 0;

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    return root->data + currOld;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Before transform: ";
    preOrder(root);
    cout << endl;

    cout << "Returned total sum: " << transform(root) << endl;

    cout << "After transform: ";
    preOrder(root);
    cout << endl;
}
