class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        
        self.hash_plus = set()
        self.hash_minus = set()
        
        self.results = []
        path = []
        visited = [0 for x in range(n)]
        
        self.dfs(path, visited)
        
        return self.draw()
        
        
    def dfs(self, path, visited):
        if len(path) == len(visited):
            self.results.append(list(path))
            return
        
        for i in range(len(visited)):
            if visited[i] == 1:
                continue
            
            if len(path) + i in self.hash_plus or len(path) - i in self.hash_minus:
                continue
            
            self.hash_plus.add(len(path) + i)
            self.hash_minus.add(len(path) - i)
            visited[i] = 1
            path.append(i)
            self.dfs(path, visited)
            path.pop()
            visited[i] = 0
            self.hash_plus.remove(len(path) + i)
            self.hash_minus.remove(len(path) - i)
            
            
    def draw(self):
        res = []
        for result in self.results:
            res1 = []
            for i in result:
                str = '.' * len(result)
                str = str[:i] + 'Q' + str[i + 1:]
                res1.append(str)
                
            res.append(list(res1))    
        
        return res
        
