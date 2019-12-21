class Solution {
public:
    vector<int> f;
    
    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        return f[x] = find(f[x]);
    }
    
    bool merge(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        
        if (root_a != root_b) {
            f[root_a] = root_b;
            return true;
        } else {
            return false;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int m = 0, n = 0;
        for (int i = 0; i < stones.size(); i++) {
            m = max(m, stones[i][0] + 1);
            n = max(n, stones[i][1] + 1);
        }
        
        f.resize(m * n);
        vector<int> row_e(m, -1);
        vector<int> col_e(n, -1);
        
        int count = 0;
        for (int i = 0; i < stones.size(); i++) {
            int pos = stones[i][0] * n + stones[i][1];
            f[pos] = pos;
            
            if (row_e[stones[i][0]] != -1) {
                if (merge(pos, row_e[stones[i][0]])) {
                    count++;
                }
            } else {
                row_e[stones[i][0]] = pos;
            }
            
            if (col_e[stones[i][1]] != -1) {
                if (merge(pos, col_e[stones[i][1]])) {
                    count++;
                }
            } else {
                col_e[stones[i][1]] = pos;   
            }
        }
        
        return count;
        
    }
};
