class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> output;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while (i<nums1.size() and j<nums2.size()){
            if (nums1[i] < nums2[j]){
                i++;
            }
            else if (nums1[i] > nums2[j]){
                j++;
            } 
            else {
                output.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return output;
    }
};
