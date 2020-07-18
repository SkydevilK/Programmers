#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool isCheck[100001];
bool comp(vector<int> v1, vector<int> v2)
{
	return v1.size() < v2.size();
}
vector<int> solution(string s) {
	vector<int> answer;

	vector<int> tmp;
	vector<vector<int>> vv;

	int size = s.size();
	string temp;
	for (int i = 1; i < size - 1; i++) {
		if (s[i] == '{')
		{
			temp.clear();
			tmp.clear();
		}
		else if (s[i] == '}') {
			tmp.push_back(stoi(temp));
			vv.push_back(tmp);
		}
		else if (s[i] == ',') {
			if (s[i - 1] == '}') 
				continue;
			tmp.push_back(stoi(temp));
			temp.clear();
		}
		else {
			temp += s[i];
		}
	}
	sort(vv.begin(), vv.end(), comp);
	for (int i = 0; i < vv.size(); ++i)
	{
		for (int j = 0; j < vv[i].size(); ++j)
		{
			if (isCheck[vv[i][j]])
				continue;
			isCheck[vv[i][j]] = true;
			answer.push_back(vv[i][j]);
		}
	}
	return answer;
}
