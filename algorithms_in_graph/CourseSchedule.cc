class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, set<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, graph, visited)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(int node, unordered_map<int, set<int>>& graph, vector<int>& visited) {
        if (visited[node] == 2) {
            return true;
        }
        if (visited[node] == 1) {
            return false;
        }
        
        visited[node] = 1;
        
        for (int n: graph[node]) {
            if (!dfs(n, graph, visited)) {
                return false;
            }
        }
        
        visited[node] = 2;
        return true;
    }
};
