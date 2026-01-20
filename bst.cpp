#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class BinarySearchTree{
    public:
    Node* insert(Node* root,int val)
    {
        if(root==NULL) return new Node(val);
        if(root->val > val) root->left = insert(root->left,val);
        else root->right = insert(root->right,val);
        return root;
    }
    Node* deleteNode(Node* root, int key)
    {
        if(root == NULL) return root;
        if(key < root->val)
        root->left = deleteNode(root->left, key);
        else if(key > root->val)
        root->right = deleteNode(root->right, key);
        else
        {
            if(root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
        Node* temp = root->right;
        while(temp->left) temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
        return root;
    }
    void inorder(Node* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    void preorder(Node* root)
    {
        if(root==NULL) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root)
    {
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
    void levelorder(Node* root) 
    {
        if(root==NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr = q.front();
            cout << curr->val << " ";
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    int height(Node* root)
    {
        if(root==NULL) return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return 1+max(leftheight,rightheight);
    }
};
int main()
{
    BinarySearchTree bst;
    Node* root = NULL;
    while(1)
    {
        int val;
        cout << "Enter the value:";
        cin >> val;
        root = bst.insert(root,val);
        int choice;
        cout << "Enter your choice:";
        cin >> choice;
        if(choice) continue;
        else break;
    }
    bst.inorder(root);
    cout << endl;
    bst.preorder(root);
    cout << endl;
    bst.postorder(root);
    cout << endl;
    bst.levelorder(root);
    cout << bst.height(root);
}