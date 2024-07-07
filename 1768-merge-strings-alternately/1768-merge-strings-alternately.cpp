class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for (int i = 0; i<word1.size() or i<word2.size(); i++){
            if(i<word1.size()){
                result.append(1, word1[i]);
            }
            if(i<word2.size()){
                result.append(1, word2[i]);
            }
        };
        return result;
    }
};
