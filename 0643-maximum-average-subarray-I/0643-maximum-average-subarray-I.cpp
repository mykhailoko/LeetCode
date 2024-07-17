class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -INFINITY;
        double sum = 0.0;
        
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        res = sum / k;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            double average = sum / k;
            if (average > res){
                res = average;
            }
        }
        return res;
    }
};
