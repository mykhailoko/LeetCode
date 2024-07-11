class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = 0;
        
        while(i<s.size()){
            while(i<s.size() and s[i] == ' ')  i++;
            if (i >= s.size()) break;
            int j = i + 1;
            while(j < s.size() and s[j] != ' ') j++;
            string sub = s.substr(i, j-i);
            if(result.size() == 0) result = sub;
            else result = sub + " " + result;
            i = j + 1;
        }
        
        return result;
    }
};
