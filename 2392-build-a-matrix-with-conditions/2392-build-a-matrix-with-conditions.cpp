class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPosition;
        unordered_map<int, int> colPosition;
        
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        
        for (int num = 1; num <= k; ++num) {
            int row = rowPosition[num];
            int col = colPosition[num];
            matrix[row][col] = num;
        }
        
        return matrix;
    }

    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, unordered_set<int>> graph;
        
        for (const auto& condition : conditions) {
            int u = condition[0];
            int v = condition[1];
            if (graph[u].insert(v).second) {
                ++inDegree[v];
            }
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for (int neighbor : graph[node]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (order.size() == k) {
            return order;
        } else {
            return {};
        }
    }
};
