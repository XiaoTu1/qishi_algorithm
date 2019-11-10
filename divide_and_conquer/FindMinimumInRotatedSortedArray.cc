class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];    
        }
        
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (nums[start] < nums[end]) {
            return nums[start];
        } else {
            return nums[end];
        }
        
    }
};
