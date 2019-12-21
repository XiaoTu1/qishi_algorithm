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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!merge(edges[i][0] - 1, edges[i][1] - 1)) {
                res = i;
            }
        }
        
        return edges[res];
    }
};
