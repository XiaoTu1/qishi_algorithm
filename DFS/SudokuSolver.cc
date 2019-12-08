class Solution {
public:
    vector<unordered_set<char>> rowHash = vector<unordered_set<char>>(9);
    vector<unordered_set<char>> columnHash = vector<unordered_set<char>>(9);
    vector<unordered_set<char>> boxHash = vector<unordered_set<char>>(9);
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int pos = 0; pos < 81; pos++) {
            int i = pos / 9;
            int j = pos % 9;
            int box_index = i / 3 * 3 + j / 3;
            
            if (board[i][j] == '.') {
                continue;
            }
            
            rowHash[i].insert(board[i][j]);
            columnHash[j].insert(board[i][j]);
            boxHash[box_index].insert(board[i][j]);
        }
        
        dfs(board, 0);
        
    }
    
    bool dfs(vector<vector<char>>& board, int pos) {
        if (pos == 81) {
            return true;
        }
        
        int i = pos / 9;
        int j = pos % 9;
        int box_index = i / 3 * 3 + j / 3;
        
        if (board[i][j] != '.') {
            return dfs(board, pos + 1);
        }
        
        for (int d = 1; d <= 9; d++) {
            if (rowHash[i].find(d + '0') != rowHash[i].end()) {
                continue;
            }
            if (columnHash[j].find(d + '0') != columnHash[j].end()) {
                continue;
            }
            if (boxHash[box_index].find(d + '0') != boxHash[box_index].end()) {
                continue;
            }
            
            board[i][j] = d + '0';
            rowHash[i].insert(d + '0');
            columnHash[j].insert(d + '0');
            boxHash[box_index].insert(d + '0');
            bool flag = dfs(board, pos + 1);
            if (flag) {
                return flag;
            }
            rowHash[i].erase(d + '0');
            columnHash[j].erase(d + '0');
            boxHash[box_index].erase(d + '0');
            board[i][j] = '.';
        }
        
        return false;
    }
};
