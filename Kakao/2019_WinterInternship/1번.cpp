#include<iostream>

#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int N = board.size();
	int len = moves.size();
	stack<int> s;
	int top = -1;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[j][moves[i] - 1] != 0) {
				if (top == board[j][moves[i] - 1])
				{
					s.pop();
					answer += 2;
					if (s.empty()) {
						top = -1;
					}
					else
					{
						top = s.top();
					}
				}
				else {
					s.push(board[j][moves[i] - 1]);
					top = s.top();
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });
}

/*
[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	[1,5,3,5,1,2,1,4]
*/
