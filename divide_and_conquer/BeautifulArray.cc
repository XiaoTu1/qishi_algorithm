class Solution {
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) {
            return vector<int>(1, 1);
        }
        
        vector<int> result;
        vector<int> half_result;
        
        if (N % 2 == 0) {
            half_result = beautifulArray(N / 2);     
        } else {
            half_result = beautifulArray(N / 2 + 1);
        }
        
        for (int i = 0; i < half_result.size(); i++) {
            if (2 * half_result[i] > N) {
                continue;
            }
            result.push_back(half_result[i] * 2);
        }
        
        for (int i = 0; i < half_result.size(); i++) {
            result.push_back(half_result[i] * 2 - 1);
        }
        
        return result;
    }
};
