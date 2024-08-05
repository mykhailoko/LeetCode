class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        for (const string& s : arr) {
            freq[s]++;
        }

        vector<string> distinctStrings;
        for (const string& s : arr) {
            if (freq[s] == 1) {
                distinctStrings.push_back(s);
            }
        }

        if (k <= distinctStrings.size()) {
            return distinctStrings[k - 1];
        } else {
            return "";
        }
    }
};
