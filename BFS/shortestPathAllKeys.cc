class Coordinate {
public:
    int x, y;
    int keys;
    Coordinate(int x_, int y_, int keys_): x(x_), y(y_), keys(keys_) {}
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        
        int x0, y0, K = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    K++;
                } else if (grid[i][j] == '@') {
                    x0 = i;
                    y0 = j;
                }
            }
        }
        
        
        int directionX[] = {1, 0, 0, -1};
        int directionY[] = {0, 1, -1, 0};
        
        queue<Coordinate> Q;
        unordered_set<string> hash;
        Q.push(Coordinate(x0, y0, 0));
        hash.insert(to_string(x0) + "_" + to_string(y0) + "_" + to_string(0));
        
        int step = 0;
        while (!Q.empty()) {
            int size = Q.size();
            step++;
            for (int i = 0; i < size; i++) {
                Coordinate head = Q.front();
                Q.pop();
                for (int j = 0; j < 4; j++) {
                    Coordinate adj(head.x + directionX[j], head.y + directionY[j], head.keys);
                    
                    if (!inBound(adj, grid)) {
                        continue;
                    }
                    
                    if (grid[adj.x][adj.y] >= 'a' && grid[adj.x][adj.y] <= 'f') {
                        adj.keys = adj.keys | (1 << (grid[adj.x][adj.y] - 'a'));
                        if (adj.keys == (1 << K) - 1) {
                            return step;
                        }
                    }
                    string code = to_string(adj.x) + "_" + to_string(adj.y) + "_" + to_string(adj.keys);
                    
                    if (hash.find(code) != hash.end()) {
                        continue;
                    }
                    
                    if (grid[adj.x][adj.y] == '#') {
                        continue;
                    } else if (grid[adj.x][adj.y] >= 'A' && grid[adj.x][adj.y] <= 'F') {
                        if ((adj.keys & (1 << (grid[adj.x][adj.y] -'A'))) != 0) {
                            Q.push(adj);
                            hash.insert(code);
                        }
                    } else {
                        Q.push(adj);
                        hash.insert(code);
                    }
                }
            }
        }
        
        return -1;
    }
    
    bool inBound(Coordinate coor, vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        return coor.x >= 0 && coor.x < m && coor.y >= 0 && coor.y < n;
    }
};
