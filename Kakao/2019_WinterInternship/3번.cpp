#include <string>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;
set<string> s;
int len;
bool check[8];
void DFS(int depth, string str, vector<string>& user_id, vector<string>& banned_id) {
	if (depth == len) {
		sort(str.begin(), str.end());
		s.insert(str);
		return;
	}

	for (int i = 0; i < user_id.size(); ++i) {
		int j;
		if (user_id[i].size() != banned_id[depth].size())
			continue;

		if (check[i] == true)
			continue;

		for (j = 0; j < user_id[i].size(); ++j) {
			if (banned_id[depth][j] == '*')
				continue;
			if (user_id[i][j] != banned_id[depth][j])
				break;
		}

		if (j == user_id[i].size()) {
			check[i] = true;
			DFS(depth + 1, str + to_string(i), user_id, banned_id);
			check[i] = false;
		}
	}

}

int solution(vector<string> user_id, vector<string> banned_id) {
	len = banned_id.size();
	DFS(0, "", user_id, banned_id);
	return s.size();
}
