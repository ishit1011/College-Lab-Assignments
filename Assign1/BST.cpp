/*          Name     :  Ihsit Singh
            Class    :  3NC1
            Roll No. :  102115023
*/
#include <bits/stdc++.h>
using namespace std;

// Class - "Node" to determine a node and its components
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insertion function (Recursive)
Node* insertBST(Node* &root, int key)
{
    Node* node = new Node(key);
    // Base Case
    if(root == NULL){
        root = node;
        return root;
    }
    
    // Value to be inserted > current root value
    if(key > root->val){
        root->right = insertBST(root->right,key);
    }
    // Value to be inserted < current root value
    else{
        root->left = insertBST(root->left,key);
    }
    return root;
}

// Function to find minimum value by traversing left recursively
Node* minVal(Node* &root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// Deletion Function
Node* deleteNode(Node* &root, int nodeVal){
    // Base Case
    if(root == NULL){
        return NULL;
    }
    if(root->val == nodeVal){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
            //  a. [Right Child Present]
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
            //  b.  [Left Child Present]
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 2 child

        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->val;
            root->val = mini;
            root->right =  deleteNode(root->right,mini);
            return root;
        }
    }
    else if(root->val > nodeVal){
        // Go Left(smaller values)
        root->left = deleteNode(root->left,nodeVal);
        return root;
    }
    else{
        // Go Right(larger values)
        root->right = deleteNode(root->right,nodeVal);
        return root;
    }
}

// Inorder Traversal - Left,Root,Right
void inorderTraversal(Node* &root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

// Preorder Traversal - Root,Left,Right
void preorderTraversal(Node* &root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal - Left,Right,Root
void postorderTraversal(Node* &root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}

// Find Minimum depth out of left and right subtree
int minDepth(Node* &root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    
    return min(l,r)+1;
}

// Find Maximum depth out of left and right subtree
int maxDepth(Node* &root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    return max(l,r)+1;
}

int main()
{
    Node* root = NULL;
    root = insertBST(root,45);
    insertBST(root,11);
    insertBST(root,42);
    insertBST(root,36);
    insertBST(root,84);
    insertBST(root,55);
    insertBST(root,96);

    cout<<"Inorder Traversal : ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Preorder Traversal : ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    postorderTraversal(root);
    cout<<endl;

    cout<<"\n Max Depth of BST = "<<maxDepth(root);
    cout<<"\n Min Depth of BST = "<<minDepth(root);

    /*
    cout<<"\n--------- Deleting Node with 0 child------------\n";
    root = deleteNode(root,36);
    cout<<"Updated Inorder Traversal : ";
    inorderTraversal(root);
    */
   /*
    cout<<"\n--------- Deleting Node with 1 child------------\n";
    root = deleteNode(root,42);
    cout<<"Updated Inorder Traversal : ";
    inorderTraversal(root);
    */
    cout<<"\n\n--------- Deleting Node with 2 children------------\n";
    root = deleteNode(root,84);
    cout<<"Updated Inorder Traversal : ";
    inorderTraversal(root);

    return 0;
}