class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        
        map<int, set<int>> graph;
        for (auto& edge: edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        queue<int> Q;
        unordered_set<int> hash;
        Q.push(0);
        hash.insert(0);
        
        int count = 0;
        while (!Q.empty()) {
            int head = Q.front();
            Q.pop();
            count++;
            for (const int& n: graph[head]) {
                if (hash.find(n) == hash.end()) {
                    Q.push(n);
                    hash.insert(n);
                }
            }
        }
        
        return count == n;
        
    }
};
