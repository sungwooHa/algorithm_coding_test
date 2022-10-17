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

    void PositionChange(TreeNode* tree)
    {
        if (!tree) return;
        auto tmp = tree->left;
        tree->left = tree->right;
        tree->right = tmp;

        PositionChange(tree->left);
        PositionChange(tree->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        //��� child�� �¿츦 �ٲٱ�.
        if (!root) return root;
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
    }
};

