class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        
        int leftProduct = 1;
        for (int i = 0; i<nums.size(); i++){
            result.push_back(leftProduct);
            leftProduct = leftProduct * nums[i];                        
        }
        
        int rightProduct = 1;
        for (int j = nums.size()-1; j>=0; j--){
            result[j] = rightProduct * result[j];
            rightProduct = rightProduct * nums[j];                        
        }
        
        return result;
    }
};
