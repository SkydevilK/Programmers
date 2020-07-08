#include<iostream>
#include <string>
#include <vector>
using namespace std;
struct POS {
	int x;
	int y;
};
const POS NUMBER[] = { {3,1},{0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}, {3,0}, {3,1}, {3,2} };
int dist(POS p1, POS p2)
{
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
string solution(vector<int> numbers, string hand) {
	string answer = "";
	POS lPos = NUMBER[10];
	POS rPos = NUMBER[12];
	for (int i = 0; i < numbers.size(); ++i)
	{
		switch (numbers[i])
		{
		case 1:
		case 4:
		case 7:
			answer.push_back('L');
			lPos = NUMBER[numbers[i]];
			break;
		case 3:
		case 6:
		case 9:
			answer.push_back('R');
			rPos = NUMBER[numbers[i]];
			break;
		case 2:
		case 5:
		case 8:
		case 0:
			int lDist = dist(lPos, NUMBER[numbers[i]]);
			int rDist = dist(rPos, NUMBER[numbers[i]]);
			if (lDist < rDist)
			{
				answer.push_back('L');
				lPos = NUMBER[numbers[i]];
			}
			else if (lDist > rDist) {
				answer.push_back('R');
				rPos = NUMBER[numbers[i]];
			}
			else {
				if (hand.compare("left")==0)
				{
					answer.push_back('L');
					lPos = NUMBER[numbers[i]];
				}
				else {
					answer.push_back('R');
					rPos = NUMBER[numbers[i]];
				}
			}
			break;
		}
	}
	return answer;
}

int main()
{
	cout << solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
	cout << solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left");
	cout << solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right");
}

/*
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]	"right"	"LRLLLRLLRRL"
[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	"left"	"LRLLRRLLLRR"
[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]	"right"	"LLRLLRLLRL"
*/
/*
1 2 3
4 5 6
7 8 9
* 0 #
*/
