class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i]==1){
                curr++;
            } else {
                ans = max(ans, curr+prev);
                prev = curr;
                curr = 0;
            }
        }
        ans = max(ans, curr+prev);
        
        return ans == nums.size() ? ans - 1 : ans;
    }
};
