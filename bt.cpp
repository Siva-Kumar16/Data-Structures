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
class BinaryTree{
    public:
    Node* createbinarytree()
    {
        int val;
        cout << "Enter the value: ";
        cin >> val;
        Node* root = new Node(val);

        int choice;
        cout << "Enter your choice for left child:";
        cin >> choice;
        if(choice) root->left = createbinarytree();

        cout << "Enter your choice for right child:";
        cin >> choice;
        if(choice) root->right = createbinarytree();
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
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) 
        {
            Node* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
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
    BinaryTree bt;
    Node* root = bt.createbinarytree();

    bt.inorder(root);
    cout << endl;
    bt.preorder(root);
    cout << endl;
    bt.postorder(root);
    cout << endl;
    bt.levelorder(root);
}