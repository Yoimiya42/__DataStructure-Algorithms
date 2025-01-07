# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// ------------------- D  E  F  I  N  E ------------------------

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* createTreeNode(int value)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// 1. Search

TreeNode* search(TreeNode* root, int value)
{   
    if (root == NULL)
    {
        printf("Not found.");
        return NULL;
    }

    if (root->val == value)
    {   
        printf("Succeed in finding.");
        return root;
    }

    if (value < root->val)
    {
        return search(root->left, value);
    }
    else if (value > root->val)
    {
        return search(root->right, value);
    }
}

// 2. Insert

TreeNode* insert(TreeNode* root, int value)
{   
    if (root == NULL)
    {
        return createTreeNode(value);
    }

    if(value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->val)
    {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 3. Delete

TreeNode* delete(TreeNode* root, int value)
{   
    if (root == NULL)  // Empty tree or non-existing value
    {
        printf("Not found.");
        return NULL;
    }

    if(value < root->val)
    {
        root->left = delete(root->left, value);
    }else if (value > root->val)
    {
        root->right = delete(root->right, value);
    }else{   // value == root->val
        if (root->left == NULL || root->right == NULL)
        {
            TreeNode* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        }else{
            TreeNode* temp = root->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = delete(root->right, temp->val);
        }
    }

    return root;
}













int main()
{
    TreeNode* root = NULL;

    return 0;
}