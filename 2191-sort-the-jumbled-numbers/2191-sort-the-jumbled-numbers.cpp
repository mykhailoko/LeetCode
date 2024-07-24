class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       auto mapNumber = [&mapping](int num) {
            string str = to_string(num);
            for (char& c : str) {
                c = '0' + mapping[c - '0'];
            }
            return stoll(str);
        };

        vector<pair<int, long long>> mappedNums;
        for (int num : nums) {
            mappedNums.emplace_back(num, mapNumber(num));
        }

        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, long long>& a, const pair<int, long long>& b) {
            return a.second < b.second;
        });

        vector<int> sortedNums;
        for (const auto& p : mappedNums) {
            sortedNums.push_back(p.first);
        }

        return sortedNums; 
    }
};
