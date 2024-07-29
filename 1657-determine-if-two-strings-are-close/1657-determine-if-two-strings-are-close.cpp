class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        
        unordered_map<char, int> freq1, freq2;
        unordered_set<char> chars1, chars2;
        
        for (char c : word1) {
            freq1[c]++;
            chars1.insert(c);
        }
        
        for (char c : word2) {
            freq2[c]++;
            chars2.insert(c);
        }
        
        if (chars1 != chars2) {
            return false;
        }
        
        vector<int> freqValues1, freqValues2;
        for (const auto& pair : freq1) {
            freqValues1.push_back(pair.second);
        }
        for (const auto& pair : freq2) {
            freqValues2.push_back(pair.second);
        }
        
        sort(freqValues1.begin(), freqValues1.end());
        sort(freqValues2.begin(), freqValues2.end());
        
        return freqValues1 == freqValues2;
    }
};
