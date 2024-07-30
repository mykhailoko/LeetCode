class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, minDeletions = 0;

        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else {
                minDeletions = min(minDeletions + 1, countB);
            }
        }

        return minDeletions;
    }
};
