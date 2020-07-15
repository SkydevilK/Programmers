#include <vector>

using namespace std;

bool Pillar[102][102] = {};
bool Dam[102][102] = {};

bool CheckPillar(int x, int y) {
	if (y == 1)
		return 1;
	if (Pillar[x][y - 1])
		return 1;
	if (Dam[x - 1][y])
		return 1;
	if (Dam[x][y])
		return 1;
	return 0;
}

bool CheckDam(int x, int y) {
	if (Pillar[x][y - 1])
		return 1;
	if (Pillar[x + 1][y - 1])
		return 1;
	if (Dam[x + 1][y] && Dam[x - 1][y])
		return 1;
	return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	int len = build_frame.size();
	for (int i = 0; i < len; ++i) {
		int x, y, a, b;
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];
		++x;
		++y;

		if (a == 0 && b == 1) {
			if (CheckPillar(x, y)) {
				Pillar[x][y] = true;
			}
		}
		else if (a == 1 && b == 1) {
			if (CheckDam(x, y)) {
				Dam[x][y] = true;
			}
		}
		else if (a == 0 && b == 0) {
			bool isCheck = true;
			Pillar[x][y] = false;
			if (Pillar[x][y + 1] && !CheckPillar(x, y + 1))
				isCheck = false;
			else if (Dam[x][y + 1] && !CheckDam(x, y + 1))
				isCheck = false;
			else if (Dam[x - 1][y + 1] && y < n && !CheckDam(x - 1, y + 1))
				isCheck = false;

			if (!isCheck)
				Pillar[x][y] = true;
		}
		else if (a == 1 && b == 0) {
			bool isCheck = true;
			Dam[x][y] = false;

			if (Pillar[x][y] && !CheckPillar(x, y))
				isCheck = false;
			else if (Pillar[x + 1][y] && !CheckPillar(x + 1, y))
				isCheck = false;
			else if (Dam[x - 1][y] && !CheckDam(x - 1, y))
				isCheck = false;
			else if (Dam[x + 1][y] && !CheckDam(x + 1, y))
				isCheck = false;

			if (!isCheck)
				Dam[x][y] = true;
		}
	}
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			if (Pillar[i][j]) {
				answer.push_back({ i - 1, j - 1, 0 });
			}
			if (Dam[i][j]) {
				answer.push_back({ i - 1, j - 1, 1 });
			}
		}
	}
	return answer;
}
