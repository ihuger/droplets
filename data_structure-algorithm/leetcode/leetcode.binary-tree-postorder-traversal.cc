//https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
#include<vector>
#include<iostream>
using namespace std;
/**
 * Definition for binary tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        return vec;
        
    }
    vector<int> recursiveTraversal(TreeNode *root){
        vector<int> vec;
        if(root == NULL)
            return vec;
        
        vector<int> lvec = recursiveTraversal(root->left);
        vector<int> rvec = recursiveTraversal(root->right);
        vec = lvec;
        for(vector<int>::iterator it=rvec.begin();
            it != rvec.end(); ++it){
            vec.push_back(*it);
        }
        vec.push_back(root->val);
        return vec;
    }
};

int main(){
    TreeNode *root = new TreeNode(10);
    root-> left = new TreeNode(100);
    root-> right= new TreeNode(200);
    Solution so;
    vector<int> v= so.recursiveTraversal(root);
    for(vector<int>::iterator it=v.begin();
            it != v.end(); ++it){
        cout<<*it<<endl;
    }


    return 0;
}
