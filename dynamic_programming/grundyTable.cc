class Solution {
public:
    vector<vector<int>> grundyTable(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        vector<unordered_set<int>> iHash(m + 1);
        vector<unordered_set<int>> jHash(n + 1);
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= i + j; k++) {
                    if (iHash[i].find(k) != iHash[i].end() || jHash[j].find(k) != jHash[j].end()) {
                        continue;
                    }
                    dp[i][j] = k;
                    iHash[i].insert(k);
                    jHash[j].insert(k);
                    break;
                }
            }
        }
        
        return dp;
    }
};
