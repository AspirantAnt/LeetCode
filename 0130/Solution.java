import java.util.*;

class Solution {
    boolean[][] searched;
    boolean[][] visited;
    int rows;
    int cols;

    public void bfs(char[][] board, int row, int col) {
        Queue<Integer> queueRow = new LinkedList<>();
        Queue<Integer> queueCol = new LinkedList<>();
        queueRow.offer(row);
        queueCol.offer(col);

        while (!queueRow.isEmpty()) {
            int size = queueRow.size();
            for (int i = 0; i < size; i++) {
                int curRow = queueRow.poll();
                int curCol = queueCol.poll();
                // up
                if (curRow - 1 >= 0 && !visited[curRow - 1][curCol] && board[curRow - 1][curCol] == 'O') {
                    visited[curRow - 1][curCol] = true;
                    searched[curRow - 1][curCol] = true;
                    queueRow.offer(curRow - 1);
                    queueCol.offer(curCol);
                }
                // down
                if (curRow + 1 < rows && !visited[curRow + 1][curCol] && board[curRow + 1][curCol] == 'O') {
                    visited[curRow + 1][curCol] = true;
                    searched[curRow + 1][curCol] = true;
                    queueRow.offer(curRow + 1);
                    queueCol.offer(curCol);
                }
                // left
                if (curCol - 1 >= 0 && !visited[curRow][curCol - 1] && board[curRow][curCol - 1] == 'O') {
                    visited[curRow][curCol - 1] = true;
                    searched[curRow][curCol - 1] = true;
                    queueRow.offer(curRow);
                    queueCol.offer(curCol - 1);
                }
                // right
                if (curCol + 1 < cols && !visited[curRow][curCol + 1] && board[curRow][curCol + 1] == 'O') {
                    visited[curRow][curCol + 1] = true;
                    searched[curRow][curCol + 1] = true;
                    queueRow.offer(curRow);
                    queueCol.offer(curCol + 1);
                }
            }

        }

    }

    public void solve(char[][] board) {
        rows = board.length;
        cols = board[0].length;
        visited = new boolean[rows][cols];
        searched = new boolean[rows][cols];
        Set<int[]> set = new HashSet<>();
        // 对边缘进行广搜
        // 第一行和最后一行
        for (int curCol = 0; curCol < cols; curCol++) {
            if (!visited[0][curCol] && board[0][curCol] == 'O') {
                visited[0][curCol] = true;
                searched[0][curCol] = true;
                bfs(board, 0, curCol);
            }
            if (!visited[rows - 1][curCol] && board[rows - 1][curCol] == 'O') {
                visited[rows - 1][curCol] = true;
                searched[rows - 1][curCol] = true;
                bfs(board, rows - 1, curCol);
            }
        }
        // 第一列和最后一列
        for (int curRow = 1; curRow < rows; curRow++) {
            if (!visited[curRow][0] && board[curRow][0] == 'O') {
                visited[curRow][0] = true;
                searched[curRow][0] = true;
                bfs(board, curRow, 0);
            }
            if (!visited[curRow][cols - 1] && board[curRow][cols - 1] == 'O') {
                visited[curRow][cols - 1] = true;
                searched[curRow][cols - 1] = true;
                bfs(board, curRow, cols - 1);
            }
        }

        // 刷新
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!searched[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
}