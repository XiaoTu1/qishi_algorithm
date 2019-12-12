class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        
        self.results = []
        path = []
        
        self.dfs(path, n, 1, k)
        
        return self.results
    
    
    def dfs(self, path, n ,pos, k):
        if len(path) == k:
            self.results.append(list(path))
            return
        
        for i in range(pos, n + 1):
            self.dfs(path + [i], n, i + 1, k)
