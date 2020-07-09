import java.util.LinkedList;
import java.util.Queue;

class State {
	public State(int x, int y, int cost, int dir) {
		this.x = x;
		this.y = y;
		this.cost = cost;
		this.dir = dir;
	}

	int dir;
	int cost;
	int x, y;
}

class Solution {
	static final int dx[] = { 0, 1, -1, 0, 0 };
	static final int dy[] = { 0, 0, 0, 1, -1 };

	static public int solution(int[][] board) {
		int N = board.length;
		Queue<State> q = new LinkedList<>();
		State s = new State(0, 0, 0, 0);
		q.add(s);
		board[0][0] = 0;
		while (!q.isEmpty()) {
			System.out.println("===================");
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					System.out.print(board[i][j] + "\t");
				}
				System.out.println();
			}
			System.out.println("===================");
			State cur = q.poll();
			for (int i = 1; i <= 4; ++i) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx >= N || ny >= N || nx < 0 || ny < 0)
					continue;
				if (board[nx][ny] == 1)
					continue;
				int nextCost = 0;
				if (cur.dir == 0 || cur.dir == i) {
					nextCost = cur.cost + 100;
				} else if (cur.dir != i) {
					nextCost = cur.cost + 600;
				}
				if (board[nx][ny] == 0 || board[nx][ny] >= nextCost) {
					board[nx][ny] = nextCost;
					q.add(new State(nx, ny, nextCost, i));
				}
			}
		}

		return board[N - 1][N - 1];
	}

	public static void main(String[] args) {
		int[][] board = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		System.out.println(solution(board));
	}
}
//[[0,0,0],[0,0,0],[0,0,0]]	900
//[[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]	3800
//[[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]	2100
//[[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]]	3200
