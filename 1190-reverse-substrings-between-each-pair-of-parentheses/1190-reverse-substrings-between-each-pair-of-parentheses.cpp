class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> match;
        string ans = "";

        for (int i = 0; i<s.size(); i++){
            if (s[i] == '('){
                match.push(i);
            }
            if (s[i] == ')') {
                int start = match.top()+1;
                int end = i;
                reverse(s.begin()+start, s.begin()+end);
                match.pop();
            }
        }
        
        for (int i = 0; i<s.size(); i++){
            if((s[i]=='(') or (s[i]==')')){
                continue;
            }else{
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};
