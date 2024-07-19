class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int res = 0;
        int zerosCount = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zerosCount++;
            }

            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
