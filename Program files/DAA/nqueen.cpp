#include <iostream>
#include <vector>

class NQBacktracking
{
private:
    std::vector<int> ld; // Left Diagonal
    std::vector<int> rd; // Right Diagonal
    std::vector<int> cl; // Columns
    int x, y;            // Initial queen position
    int N;               // Size of the chessboard

public:
    NQBacktracking(int x_, int y_, int N_) : x(x_), y(y_), N(N_)
    {
        ld.resize(30, 0);
        rd.resize(30, 0);
        cl.resize(30, 0);

        // Initial position of the 1st queen
        ld[x - y + N - 1] = rd[x + y] = cl[x] = 1;
    }

    void printSolution(std::vector<std::vector<int>> &board)
    {
        std::cout << "N Queen Backtracking Solution:\nGiven initial position of 1st queen at row: " << x << " column: " << y << "\n\n";
        for (const auto &line : board)
        {
            for (int cell : line)
            {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }

    bool solveNQUtil(std::vector<std::vector<int>> &board, int col)
    {
        if (col == N)
            return true;

        if (col == y)
            return solveNQUtil(board, col + 1);

        for (int i = 0; i < N; ++i)
        {
            if (i == x)
                continue;

            if (ld[i - col + N - 1] == 0 && rd[i + col] == 0 && cl[i] == 0)
            {
                board[i][col] = 1;
                ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

                if (solveNQUtil(board, col + 1))
                    return true;

                board[i][col] = 0; // BACKTRACK
                ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
            }
        }

        return false;
    }

    bool solveNQ(std::vector<std::vector<int>> &board)
    {
        if (!solveNQUtil(board, 0))
        {
            std::cout << "Solution does not exist" << std::endl;
            return false;
        }
        printSolution(board);
        return true;
    }
};

int main()
{
    int N = 8;
    int x = 3, y = 2;

    NQBacktracking NQBt(x, y, N);
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    board[x][y] = 1;

    NQBt.solveNQ(board);

    return 0;
}
