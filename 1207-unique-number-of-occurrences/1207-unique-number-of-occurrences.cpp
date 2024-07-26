class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        for (int num : arr) {
            frequency[num]++;
        }

        unordered_set<int> occurrences;
        for (const auto& pair : frequency) {
            if (!occurrences.insert(pair.second).second) {
                return false;
            }
        }
        
        return true;
    }
};
