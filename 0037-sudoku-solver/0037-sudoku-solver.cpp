class Solution {
public:
    
    //Using recursion
    //Traversing through every block and try to place 1-9 value if possible then check for next block if not then backtrack
    bool isSafe(int row, int col, vector<vector<char>> &board, char value)
    {
        for (int i = 0; i < 9; i++)
        {
            // checking horizontally
            if (board[row][i] == value)
                return false;

            if (board[i][col] == value)
                return false;

            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board)
    {
        int n=board.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char value = '1'; value <= '9'; value++)
                    {
                        if (isSafe(i, j, board, value))
                        {
                            board[i][j] = value;

                            bool isWrong = solve(board);
                            if (isWrong)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};