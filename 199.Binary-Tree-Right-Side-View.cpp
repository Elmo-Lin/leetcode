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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> q{{root}};       // BFS 模板題
        while(!q.empty()){
            int size=q.size();
            res.push_back(q.front()->val);
            for(int i=0; i<size; i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
        }
        return res;
    }
};