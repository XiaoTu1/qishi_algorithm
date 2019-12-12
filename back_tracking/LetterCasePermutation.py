class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        
        if not S:
            return []
        
        if len(S) == 0:
            return [""]
        
        self.results = []
        path = ""
        
        self.dfs(path, 0, S)
        
        return self.results
    
    
    def dfs(self, path, pos, S):
        if (pos == len(S)):
            self.results.append(path)
            return
        
        if ord("a") <= ord(S[pos]) <= ord("z"):
            path = path + S[pos]            ########
            self.dfs(path, pos + 1, S)
            path = path[:-1] + chr(ord(S[pos]) - ord("a") + ord("A"))     ########
            self.dfs(path, pos + 1, S)
            path = path[:-1]
        elif ord("A") <= ord(S[pos]) <= ord("Z"):
            path = path + S[pos]
            self.dfs(path, pos + 1, S)
            path = path[:-1] + chr(ord(S[pos]) - ord("A") + ord("a"))
            self.dfs(path, pos + 1, S)
            path = path[:-1]
        else:
            path = path + S[pos]
            self.dfs(path, pos + 1, S)
            path = path[:-1]
            
