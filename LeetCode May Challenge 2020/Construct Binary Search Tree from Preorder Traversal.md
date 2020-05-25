## Construct Binary Search Tree from Preorder Traversal

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val. Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

### Example 1:

```
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

![example](https://assets.leetcode.com/uploads/2019/03/06/1266.png)

### Constraints:

- `1 <= preorder.length <= 100`
- `1 <= preorder[i] <= 10^8`
- The values of preorder are distinct.

### SOLUTION:

```cpp
class Solution {
public:
    TreeNode* help(TreeNode* root,int key)
    {
        if(root==NULL) return new TreeNode(key);
        else if(root->val>key) root->left=help(root->left,key);
        else root->right=help(root->right,key);

        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* root=NULL;

        for(int i=0;i<preorder.size();i++)
        {
            root=help(root,preorder[i]);
        }
        return root;
    }
};
```

---
