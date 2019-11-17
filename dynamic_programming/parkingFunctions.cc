class Solution {
public:
    int nParking(int n) {
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = i * factorial[i - 1];
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1;
        }
        
        //dp[m][n] = \Sigma_{k=0}^{n-m+1} C(n, k) dp[m - 1][n - k];
        
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = 0; k <= j - i + 1; k++) {
                    dp[i][j] += dp[i - 1][j - k] * factorial[j] / (factorial[k] * factorial[j - k]);
                }
            }
        }
        
        return dp[n][n];
    }
    
    vector<vector<int>> parking(int n) {
        set<vector<int>> result;
        result.insert(vector<int>(1, 1));
        
        for (int i = 2; i <= n; i++) {
            set<vector<int>> new_result;
            for (int j = 1; j <= i; j++) {
                for (auto v1: result) {
                    for (int pos = 0; pos < i; pos++) {
                        v1.insert(v1.begin() + pos, j);
                        new_result.insert(v1);
                        v1.erase(v1.begin() + pos);
                    }
                }
            }
            result = new_result;
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
    
};
