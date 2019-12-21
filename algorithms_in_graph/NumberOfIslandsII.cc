class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
     
    vector<int> f;
    int area = 0;
    
    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        
        return f[x] = find(f[x]); 
    }
    
    void merge(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        
        if (root_a != root_b) {
            f[root_a] = root_b;
            area--;
        }
    }
    
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        int size = operators.size();
        if (n == 0 || m == 0) {
            return vector<int>(size);
        }
        
        f.resize(n * m, -1);
        
        int directionX[] = {1, 0, 0, -1};
        int directionY[] = {0, 1, -1, 0};
        
        vector<int> res;
        for (int i = 0; i < size; i++) {
            int pos = operators[i].x * m + operators[i].y;
            if (f[pos] != -1) {
                res.push_back(res.back());
                continue;
            }
            
            f[pos] = pos;
            area++;
            
            for (int j = 0; j < 4; j++) {
                int adj_x = operators[i].x + directionX[j];
                int adj_y = operators[i].y + directionY[j];
                
                if (adj_x < 0 || adj_x >= n || adj_y < 0 || adj_y >= m) {
                    continue;
                }
                
                int adj_pos = adj_x * m + adj_y;
                if (f[adj_pos] == -1) {
                    continue;
                }
                merge(pos, adj_pos);
            }
            
            res.push_back(area);
        }
        
        return res;
    }
};
