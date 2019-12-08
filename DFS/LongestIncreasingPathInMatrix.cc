class Solution {
public:
    vector<vector<int>> hash;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        hash.resize(m, vector<int>(n, -1));
      
        int result = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }
        
        return result;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (hash[x][y] != -1) {
            return hash[x][y];
        }
        
        int directionX[] = {1, 0, 0,-1};
        int directionY[] = {0, 1,-1, 0};
        
        int result = 1;
        for (int i = 0; i < 4; i++) {
            int adj_x = x + directionX[i];
            int adj_y = y + directionY[i];
            
            if (adj_x < 0 || adj_x >= m || adj_y < 0 || adj_y >= n) {
                continue;
            }
            if (grid[adj_x][adj_y] >= grid[x][y]) {
                continue;
            }
            
            result = max(result, dfs(grid, adj_x, adj_y) + 1);
        }
        
        hash[x][y] = result;
        return hash[x][y];
    }
};
