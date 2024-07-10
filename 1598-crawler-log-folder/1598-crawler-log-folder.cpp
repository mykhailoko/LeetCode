class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (int i = 0; i<logs.size(); i++){
            if(logs[i]=="./"){
                continue;
            }else if(logs[i]=="../"){
                if(res>0){
                    res -= 1;
                }else{
                    continue;
                }
            }else{
                res += 1;
            }
        }
        return res;
    }
};
