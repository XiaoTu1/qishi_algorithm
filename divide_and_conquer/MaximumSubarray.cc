class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // write your code here
        vector<int> prefixSum;
        prefixSum.push_back(0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
        
        int min_ele = 0;
        int result = INT_MIN;
        for (int i = 1; i <= nums.size(); i++) {
            result = max(result, prefixSum[i] - min_ele);
            min_ele = min(min_ele, prefixSum[i]);
        }
        
        return result;
    }
};
