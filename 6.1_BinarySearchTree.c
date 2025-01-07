
# include <stdio.h>
# include <stdlib.h>
# include <string.h>


/*
Binary Search Tree(BST): 
Left child node(tree) < Parent node < Right child node(tree)
*/

// ------------------- D  E  F  I  N  E ------------------------

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct BST
{
    TreeNode* root;

}BST;


// -------------- I M  P  L  E  M  E  N  T  A  T  I  O  N  S ---------------
TreeNode* createTreeNode(int value)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BST* initBST()
{
    BST* bst = malloc(sizeof(BST));
    bst->root = NULL;

    return bst;
}


// 1. Insert a node
void insert(BST* bst, int value)
{   
    TreeNode* node = createTreeNode(value);

    if(bst->root == NULL)  // If the tree is empty
    {
        bst->root = node;
        return
    }

    TreeNode* current = bst->root;
    while(current)
    {
        if(value < current->val)
        {
            if(current->left == NULL)
            {
                current->left = node;
                return;
            }

            current = current->left;
        }
        else if (value > current->val)
        {
            if(current->right == NULL)
            {
                current->right = node;
                return;
            }

            current = current->right;
        }
    }
}

// 2. Search 
TreeNode* search(BST* bst, int value)
{
    TreeNode* current = bst->root;
    while(current)
    {
        if(value == current->val)
        {
            return current;
        }

        if(value < current->val)
        {
            current = current->left;
        }
        else if (value > current->val)
        {
            current = current->right;
        }
    }

    return NULL;
}

// 3. Delete
/*
Tree cases:
1. leaf node : delete directly
2. node with one child: delete the node and link the child to the parent
3. node with two children: find the greatest node in the left subtree(
*/

TreeNode* leftMax(TreeNode* root)
{   // Find the most significant node in the left subtree
    TreeNode* temp = root->left;
    while(temp->right)
    {
        temp = temp->right;
    }

    return temp;
}

void delete(BST* bst, int value)
{
    if(bst->root == NULL)     // Empty tree
    {
        printf("Empty Tree.");
        return;
    }

    TreeNode* cur = bst->root;
    TreeNode* prev = NULL;
    
    // Find the node to delete
    while(cur)
    {
        // dive into the left
        if (value < cur->val)                 
        {   
            prev = cur;
            cur = cur->left;
        }

        // dive into the right
        else if (value > cur->val)            
        {   
            prev = cur;
            cur = cur->right;
        } 
        else{  // value == cur->value      cease to deal with case by case
            if (cur->left == NULL || cur->right == NULL) // Case 1 and 2
            {
                TreeNode* temp = (cur->left == NULL ? cur->right : cur->left);
                if(prev == NULL)   
                {   // root node is to be deleted (including the case of only root node in the tree)
                    bst->root = temp;
                }
                else if(prev->left == cur)
                {
                    prev->left = temp;
                }else{  // prev->right == cur
                    prev->right = temp;
                }
                free(cur);
                return;
            }else{        // Case 3
                TreeNode* leftmax = leftMax(cur);
                int leftMaxVal = leftmax->val;
                delete(bst, leftMaxVal);
                cur->val = leftMaxVal;
            }
        }

    }
}

// 4. Traverse the tree
/*
**Breadth First Search(BFS):
level- order traversal: 

**Depth First Search(DFS):
pre-order:  root->left->right     
in-order:   left->root->right     
post-order: left->right->root

*/


// ------------------- T  E  S  T -------------------


int main()
{
    BST* bst = initBST();
    
    return 0;
}
