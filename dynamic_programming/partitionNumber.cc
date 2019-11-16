class Solution {
public:
    int nPartition(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > j) {
                    dp[i][j] = dp[j][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - i];
                }
            }
        }
        
        return dp[n][n];
    }
    
    vector<vector<int>> partition(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>());
        
        dp[0] = vector<vector<int>>(1);
        
        for (int i = 1; i <= n; i++) {
            for (int j = i; j >= 1; j--) {
                for (auto v1: dp[i - j]) {
                    vector<int> result1;
                    result1.push_back(j);
                    if (v1.size() > 0 && v1[0] > j) {
                        continue;
                    }
                    result1.insert(result1.begin() + 1, v1.begin(), v1.end());
                    dp[i].push_back(result1);
                }
            }
        }
        
        return dp[n];
    }
};
