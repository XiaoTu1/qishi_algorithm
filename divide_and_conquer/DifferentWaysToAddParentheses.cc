class Solution {
public:
    vector<int> diffWaysToCompute(string &input) {
        if (input.size() == 0) {
            return vector<int>();
        }
        
        vector<int> nums;
        string operators;
        
        int i = 0;
        while (i < input.size()) {
            if (isdigit(input[i])) {
                int num = atoi(&input[i]);
                nums.push_back(num);
                while (i < input.size() && isdigit(input[i])) {
                    i++;
                }
            } else {
                operators.push_back(input[i]);
                i++;
            }
        }
        
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        
        for (int i = 0; i < n; i++) {
            dp[i][i].push_back(nums[i]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    for (int x: dp[i][k]) {
                        for (int y: dp[k + 1][j]) {
                            int result;
                            if (operators[k] == '+') {
                                result = x + y;
                            } else if (operators[k] == '-') {
                                result = x - y;
                            } else {
                                result = x * y;
                            }
                            
                            dp[i][j].push_back(result);
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
