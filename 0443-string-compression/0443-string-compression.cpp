class Solution {
public:
    int compress(vector<char>& chars) {
        int r = 0;
        int i = 0;
        
        while(i<chars.size()){
            int curChar = chars[i];
            int curOcc = 0;
            while((i<chars.size()) and (chars[i] == curChar)){
                curOcc += 1;
                i += 1;
            }
            chars[r] = curChar;
            r += 1;
            if(curOcc > 1){
                string curOccStr = to_string(curOcc);
                for (int j = 0; j<curOccStr.size(); j++){
                    chars[r] = curOccStr[j];
                    r += 1;
                }
            }
        }
        return r;
    }
};
