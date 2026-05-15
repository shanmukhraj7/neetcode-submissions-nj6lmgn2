class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), box(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                int boxIdx = (i / 3) * 3 + (j / 3);
                if(row[i].count(ch) || col[j].count(ch) || box[boxIdx].count(ch)) return false;
                row[i].insert(ch);
                col[j].insert(ch);
                box[boxIdx].insert(ch);
            }
        }
        return true;
    }
};
