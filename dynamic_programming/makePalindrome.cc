class Solution {
public:
    int makePalindrome(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
