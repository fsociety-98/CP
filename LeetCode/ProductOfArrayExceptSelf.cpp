//O(n) time
//O(1) extra space apart from ans

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        long long left = 1;
        int i;
        
        for(i=0;i<nums.size();i++)
        {
            ans[i] = left;
            left = left * nums[i];
        }
        
        //Left now represents right
        left = 1;
        for(i=nums.size()-1;i>=0;i--)
        {
            ans[i] = ans[i] * left;
            left = left* nums[i];
        }
        
        
        return ans;
    }
};