#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
struct Road {
	int x, y, dir, cost;
};
const int dx[] = { 0,1,-1,0,0 };
const int dy[] = { 0,0,0,1,-1 };
int solution(vector<vector<int>> board) {
	int N = board.size();
	queue<Road> q;
	q.push({ 0,0,0,0 });
	board[0][0] = 1;
	while (!q.empty()) {
		Road cur = q.front();
		q.pop();
		for (int i = 1; i <= 4; ++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= N || ny >= N || nx < 0 || ny < 0)
				continue;
			if (board[nx][ny] == 1)
				continue;
			int nCost = 0;
			if (cur.dir == 0 || cur.dir == i)
				nCost = cur.cost + 100;
			else if (cur.dir != i)
				nCost = cur.cost + 600;
			if (board[nx][ny] == 0 || board[nx][ny] >= nCost) {
				board[nx][ny] = nCost;
				q.push({ nx,ny,i,nCost });
			}
		}
	}
	return board[N - 1][N - 1];
}
