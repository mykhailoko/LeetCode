class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int onesCount = count(nums.begin(), nums.end(), 1);

        if (onesCount == n) {
            return 0;
        }

        vector<int> extendedNums(nums.begin(), nums.end());
        extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

        int currentOnes = 0;
        int minSwaps = INT_MAX;

        for (int i = 0; i < onesCount; ++i) {
            if (extendedNums[i] == 1) {
                ++currentOnes;
            }
        }

        int windowZeros = onesCount - currentOnes;
        minSwaps = windowZeros;

        for (int i = onesCount; i < 2 * n; ++i) {
            if (extendedNums[i] == 1) {
                ++currentOnes;
            }
            if (extendedNums[i - onesCount] == 1) {
                --currentOnes;
            }

            windowZeros = onesCount - currentOnes;
            minSwaps = min(minSwaps, windowZeros);
        }

        return minSwaps;
    }
};
