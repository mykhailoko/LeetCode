class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        for (int i = 0; i < matrix.size(); i++) {
            int minInRow = matrix[i][0];
            int minIndex = 0;
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] < minInRow) {
                    minInRow = matrix[i][j];
                    minIndex = j;
                }
            }
            bool isMaxInCol = true;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][minIndex] > minInRow) {
                    isMaxInCol = false;
                    break;
                }
            }
            if (isMaxInCol) {
                luckyNumbers.push_back(minInRow);
            }
        }
        return luckyNumbers;
    }
};
