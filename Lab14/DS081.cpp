#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(int *nums, int size)
{
    if (nums == NULL || size == 0)
        return NULL;

    TreeNode *root = NULL;
    queue<TreeNode **> q;
    q.push(&root);
    int i = 0;

    while (i < size)
    {
        TreeNode **node = q.front();
        q.pop();
        if (nums[i] != 0)
        {
            *node = new TreeNode(nums[i]);
            q.push(&((*node)->left));
            q.push(&((*node)->right));
        }
        i++;
    }
    return root;
}

void printInOrderTree(TreeNode *root)
{
    if (!root)
        return;
    printInOrderTree(root->left);
    if (root -> val != 0)
    cout << root->val << " ";
    printInOrderTree(root->right);
}

int main()
{
    int num;
    cin >> num;
    int nums[num];

    for (int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }

    TreeNode *root = buildTree(nums, num);
    printInOrderTree(root);
    cout << endl;

    return 0;
}
