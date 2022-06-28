#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int depth=0;
        queue<TreeNode*> q{{root}};       // BFS 模板題
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};