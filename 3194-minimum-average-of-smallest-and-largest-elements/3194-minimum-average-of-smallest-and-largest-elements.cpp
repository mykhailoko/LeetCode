class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> averages;
        double average = 0.0;
        int left = 0;
        int right = nums.size()-1;
        sort(nums.begin(), nums.end());
        while (right > left){
            average = (nums[left] + nums[right])/2.0;
            averages.push_back(average);
            nums.erase(nums.begin() + left);
            nums.erase(nums.begin() + right - 1);
            left = 0;
            right = nums.size()-1;
        }
        return *min_element(averages.begin(), averages.end());
    }
};
