#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int countNodes(TreeNode* root) {
    int count = 0;
    TreeNode* curr = root;
    
    while (curr) {
        if (curr->left == NULL) {
            count++;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}



float findMedian(TreeNode* root) {
    if (!root) return 0.0;

    int n = countNodes(root); 
    int count = 0;
    TreeNode* curr = root;
    TreeNode* prev = NULL;
    TreeNode* first = NULL, *second = NULL;

    while (curr) {
        if (curr->left == NULL) {
            count++;

            if (count == (n / 2) + 1) second = curr;
            if (count == (n + 1) / 2) first = curr;

            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                count++;

                if (count == (n / 2) + 1) second = curr;
                if (count == (n + 1) / 2) first = curr;

                curr = curr->right;
            }
        }
    }

    if (n % 2 == 0) return (first->val + second->val) / 2.0;
    return first->val;
}


int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << "Median of BST: " << findMedian(root) << endl;
    
    return 0;
}
