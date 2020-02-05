class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int low = 0;
        int high = height.size() - 1;
        int mx = -INT_MAX;
        
        while(low<high)
        {
            mx = max((high-low)*min(height[high],height[low]),mx);
            if(height[high]>height[low])
                low++;
            else
                high--;
        }
        
        return mx;
    }
};
