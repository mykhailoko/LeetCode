class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        
        for (int num : nums) {
            freqMap[num]++;
        }
        
        auto compare = [&freqMap](int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a > b;
            }
            return freqMap[a] < freqMap[b];
        };

        sort(nums.begin(), nums.end(), compare);
        
        return nums;
    }
};
