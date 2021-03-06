// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> que;
        que.push(root);

        int dep = 0;
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();
                if ((top->left == nullptr) && (top->right == nullptr)) {
                    printf("return from here\n");
                    return dep + 1;
                }
                if (top->left) que.push(top->left);
                if (top->right) que.push(top->right);
            }
            dep++;
        }
        return dep;
    }
};
