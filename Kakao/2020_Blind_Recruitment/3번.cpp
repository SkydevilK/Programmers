#include <string>
#include <vector>
using namespace std;

int N, M, SIZE;
void Right(vector<vector<int>>& key) {
	vector<vector<int>> tmp(N, vector<int>(N));
	for (int j = N - 1; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			tmp[i][j] = key[N - j - 1][i];
		}
	}
	key = tmp;
}
bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
	for (int i = x; i < x + N; ++i) {
		for (int j = y; j < y + N; ++j) {
			board[i][j] += key[i - x][j - y];
		}
	}
	for (int i = N - 1; i <= SIZE - N; i++) {
		for (int j = N - 1; j <= SIZE - N; j++) {
			if (board[i][j] == 1) continue;
			return false;
		}
	}
	return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	N = key.size();
	M = lock.size();
	SIZE = M + (N - 1) * 2;
	vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
	for (int i = N - 1; i <= SIZE - N; ++i) {
		for (int j = N - 1; j <= SIZE - N; ++j) {
			board[i][j] = lock[i - N + 1][j - N + 1];
		}
	}
	for (int rotate = 0; rotate < 4; ++rotate) {

		for (int i = 0; i <= SIZE - N; ++i) {
			for (int j = 0; j <= SIZE - N; ++j) {
				if (check(i, j, key,board)) {
					answer = true;
					return answer;
				}

			}
		}
		Right(key);
	}
	return answer;
}
