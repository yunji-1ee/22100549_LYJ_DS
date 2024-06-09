#include <iostream>
#include <queue>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int* nums, int size) {
    if (nums == NULL || size == 0) return NULL;

    TreeNode* root = NULL;
    queue<TreeNode**> q;
    q.push(&root);
    int i = 0;

    while (i < size) {
        TreeNode** node = q.front();
        q.pop();
        if (nums[i] != 0) {
            *node = new TreeNode(nums[i]);
            q.push(&((*node)->left));
            q.push(&((*node)->right));
        }
        i++;
    }
    return root;
}

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    if (root->val != 0) 
        cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    if (root->val != 0)
        cout << root->val << " ";
}

int main() {
    int num;
    cin >> num;
    string traversalMethod;
    cin >> traversalMethod;
    int nums[num];

    for (int i = 0; i < num; i++) {
        cin >> nums[i];
    }

    TreeNode* root = buildTree(nums, num);

    if (traversalMethod == "1") {
        cout << "preorder traversal: ";
        preorderTraversal(root);
    } else if (traversalMethod == "2") {
        cout << "postorder traversal: ";
        postorderTraversal(root);
    }
    cout << endl;

    return 0;
}
