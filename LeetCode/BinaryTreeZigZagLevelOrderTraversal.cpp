/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        if(root == NULL)
            return vector<vector<int> >();
        
        // 1 - left to right
        // -1 - right to left
        int direction = -1;
        vector<vector<int> > ans;
        
        stack<TreeNode *> st,tmp;
        st.push(root);
        while(true)
        {
            vector<int> temp_ans;
            //Pop from st and append to ans
            while(!st.empty())
            {
                TreeNode * temp = st.top();
                temp_ans.push_back(temp->val);
                
                if(direction == 1)
                {
                    if(temp->right!=NULL)
                        tmp.push(temp->right);
                    if(temp->left!=NULL)
                        tmp.push(temp->left);
                }
                else
                {
                    if(temp->left!=NULL)
                        tmp.push(temp->left);
                    if(temp->right!=NULL)
                        tmp.push(temp->right);
                }
                st.pop();
            }
            ans.push_back(temp_ans);
            
            swap(st,tmp);
            
            direction = (direction == 1)?-1:1;
            
            if(st.size() == 0)
                break;
        }
        
        return ans;
    }
};