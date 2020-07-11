#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
vector<int> solution(vector<string> gems) {
	vector<int> answer = { 0,0 };
	int minCnt = 100001;
	map<string, int> m;
	int len = gems.size();
	for (int i = 0; i < len; ++i)
	{
		m[gems[i]] = 0;
	}
	int s = 0;
	int e = 0;
	int size = m.size();
	int cnt = 0;
	while (true) {
		if (cnt == size) {
			int tmp = e - s;
			if (tmp < minCnt)
			{
				minCnt = tmp;
				answer[0] = s + 1;
				answer[1] = e;
			}		
			m[gems[s]] = m[gems[s]] - 1;
			if (m[gems[s]] == 0)
			{
				--cnt;
			}
			++s;
		}
		else {
			if (m[gems[e]] == 0)
			{
				++cnt;
			}
			m[gems[e]] = m[gems[e]] + 1;
			++e;
		}
		if (cnt == size) {
			int tmp = e - s;
			if (tmp < minCnt)
			{
				minCnt = tmp;
				answer[0] = s + 1;
				answer[1] = e;
			}
		}
		if (e >= len)
			break;
		if (s >= len)
			break;
	}
	return answer;
}

int main() {
	vector<int> v = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	cout << v[0] << " " << v[1]<<endl;
	v = solution({ "AA", "AB", "AC", "AA", "AC" });
	cout << v[0] << " " << v[1] << endl;
	v = solution({ "XYZ", "XYZ", "XYZ" });
	cout << v[0] << " " << v[1] << endl;
	v = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
	cout << v[0] << " " << v[1] << endl;
}
//["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
//["AA", "AB", "AC", "AA", "AC"]	[1, 3]
//["XYZ", "XYZ", "XYZ"]	[1, 1]
//["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	[1, 5]

