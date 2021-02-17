class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while (l < r) {
            int keep = min (height[l], height[r]) * (r-l);
            ans = max (ans, keep);
            
            if (height[l] > height[r]) r--;
            else l++;
        }
        
        return ans;
    }
};
