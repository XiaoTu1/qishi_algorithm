class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dp(n , 1);
        vector<int> father(n, -1);
        
        int LDS = 1;
        int final_idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 >= dp[i]) {
                        dp[i] = dp[j] + 1;
                        father[i] = j;
                    }
                }
            }
            
            if (LDS <= dp[i]) {
                final_idx = i;
                LDS = dp[i];
            }
        }
        
        vector<int> result;
        int index = final_idx;
        while (index != -1) {
            result.push_back(nums[index]);
            index = father[index];
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
