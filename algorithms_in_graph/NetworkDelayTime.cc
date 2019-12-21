class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<long>> G(N + 1, vector<long>(N + 1, INT_MAX));
        for (int i = 0; i <= N; i++) {
            G[i][i] = 0;
        }
        for (int i = 0; i < times.size(); i++) {
            G[times[i][0]][times[i][1]] = times[i][2];
        }
        
        vector<long> distance(N + 1, INT_MAX);
        distance[K] = 0;
        vector<int> visited(N + 1, 0);
        
        for (int i = 1; i < N; i++) {
            int min_dis = INT_MAX;
            int min;
            for (int j = 1; j <= N; j++) {
                if (!visited[j] && distance[j] <= min_dis) {
                    min_dis = distance[j];
                    min = j;
                }
            }
            visited[min] = 1;
            
            for (int j = 1; j <= N; j++) {
                if (!visited[j] && distance[min] + G[min][j] < distance[j]) {
                    distance[j] = distance[min] + G[min][j];
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= N; i++) {
            res = max<int>(res, distance[i]);
        }
        
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};
