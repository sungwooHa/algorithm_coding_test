#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/invert-binary-tree/
/// </summary>
/// <returns></returns>
/// 
/// 
class LeetCode_226 : public ISolution {
public:

    TreeNode* invertTree(TreeNode* root) {
        //모든 child의 좌우를 바꾸기.
        if (!root) return root;
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

