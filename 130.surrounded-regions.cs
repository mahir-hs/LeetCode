/*
 * @lc app=leetcode id=130 lang=csharp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
public class Solution
{
    public void Solve(char[][] board)
    {
        bool[,] visited = new bool[board.Length, board[0].Length];
        Queue<(int, int)> queue = new Queue<(int, int)>();
        for (int i = 0; i < board[0].Length; i++)
        {
            if (board[0][i] == 'O')
            {
                queue.Enqueue((0, i));
                visited[0, i] = true;
            }
            if (board[board.Length - 1][i] == 'O')
            {
                queue.Enqueue((board.Length - 1, i));
                visited[board.Length - 1, i] = true;
            }
        }

        for (int i = 0; i < board.Length; i++)
        {
            if (board[i][0] == 'O')
            {
                queue.Enqueue((i, 0));
                visited[i, 0] = true;
            }
            if (board[i][board[0].Length - 1] == 'O')
            {
                queue.Enqueue((i, board[0].Length - 1));
                visited[i, board[0].Length - 1] = true;
            }
        }

        while (queue.Count > 0)
        {
            (int x, int y) = queue.Dequeue();
            if (x - 1 >= 0 && board[x - 1][y] == 'O' && !visited[x - 1, y])
            {
                queue.Enqueue((x - 1, y));
                visited[x - 1, y] = true;
            }
            if (x + 1 < board.Length && board[x + 1][y] == 'O' && !visited[x + 1, y])
            {
                queue.Enqueue((x + 1, y));
                visited[x + 1, y] = true;
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'O' && !visited[x, y - 1])
            {
                queue.Enqueue((x, y - 1));
                visited[x, y - 1] = true;
            }
            if (y + 1 < board[0].Length && board[x][y + 1] == 'O' && !visited[x, y + 1])
            {
                queue.Enqueue((x, y + 1));
                visited[x, y + 1] = true;
            }
        }

        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                if (!visited[i, j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

    }
}
// @lc code=end

