class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int num = 0;
        bool res = true;
        for (int i = 0; i<arr.size(); i++){
            if (arr[i]%2!=0 and num!=3){
                num++;
            }
            if(arr[i]%2==0){
                num = 0;
            }
            if (num==3){
                res = true;
                break;
            } else {
                res = false;
            }
        }
        return res;
    }
};
