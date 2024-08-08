class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int totalCells = rows * cols;
        int steps = 1;
        int dir = 0;
        int r = rStart, c = cStart;
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        result.push_back({r, c});
        while (result.size() < totalCells) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    r += directions[dir][0];
                    c += directions[dir][1];
                    
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                dir = (dir + 1) % 4;
            }
            ++steps;
        }
        
        return result;
    }
};
