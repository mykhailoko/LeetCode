class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int j = 0; j < nums1.size(); j++){
            if(j >= m){
                nums1.erase(nums1.begin() + j);
                j--;
            }
        }
        
        for(int i = 0; i < n; i++){
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin(), nums1.end()); 
    }
};
