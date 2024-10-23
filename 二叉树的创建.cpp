#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数，用于在构建树时查找根节点在中序遍历中的位置
int findInorderIndex(const vector<char>& inorder, int start, int end, char rootVal) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == rootVal) return i;
    }
    return -1;
}

// 根据先序和中序序列建立二叉树
TreeNode* buildTree(const vector<char>& preorder, const vector<char>& inorder,
    int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    char rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRootIndex = findInorderIndex(inorder, inStart, inEnd, rootVal);

    int leftTreeSize = inRootIndex - inStart;

    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftTreeSize, inStart, inRootIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + leftTreeSize + 1, preEnd, inRootIndex + 1, inEnd);

    return root;
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}

// 层序遍历二叉树
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// 获取二叉树的深度
int getTreeDepth(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// 获取二叉树的叶子数目
int getLeafCount(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return getLeafCount(root->left) + getLeafCount(root->right);
}

// 判断是否是完全二叉树
bool isCompleteBinaryTree(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool hasNodeWithNoChild = false;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (!node->left && node->right) return false; // 有右孩子但没左孩子
        if (node->left && hasNodeWithNoChild) return false; // 有孩子但前一个节点没孩子
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (!node->left && node->right) hasNodeWithNoChild = true;
    }
    return true;
}

int main() {
    vector<char> preorder = { 'A', 'B', 'D', 'G', 'C', 'E', 'F' };
    vector<char> inorder = { 'D', 'G', 'B', 'A', 'E', 'C', 'F' };

    TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

    cout << "后序遍历为： ";
    postorderTraversal(root);
    cout << endl;

    cout << "层序遍历为：";
    levelOrderTraversal(root);
    cout << endl;

    cout << "二叉树深度为：" << getTreeDepth(root) << endl;

    cout << "二叉树叶子数目：" << getLeafCount(root) << endl;

    cout << "该二叉树是否为完全二叉树：" << (isCompleteBinaryTree(root) ? "是的" : "不是") << endl;
 system("pause");
    return 0;
   
}
