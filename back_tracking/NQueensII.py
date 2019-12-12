class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        self.hash_plus = set()
        self.hash_minus = set()
        
        self.count = 0
        path = []
        visited = [0 for x in range(n)]
        
        self.dfs(path, visited)

        return self.count
    
    
    def dfs(self, path, visited):
        if len(path) == len(visited):
            self.count += 1 
            return
        
        for i in range(len(visited)):
            if visited[i] == 1:
                continue
                
            if len(path) + i in self.hash_plus or len(path) - i in self.hash_minus:
                continue
            
            self.hash_plus.add(len(path) + i)
            self.hash_minus.add(len(path) - i)
            
            visited[i] = 1
            self.dfs(path + [i], visited)
            visited[i] = 0
            
            self.hash_plus.remove(len(path) + i)
            self.hash_minus.remove(len(path) - i)

    
