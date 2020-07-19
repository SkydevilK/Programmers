#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long Find(long long num) {
	if (m[num] == 0)
		return num;
	return m[num] = Find(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	int len = room_number.size();
	for (long long i = 0; i < len; ++i) {
		long long p = Find(room_number[i]);
		answer.push_back(p);
		m[p] = p + 1;
	}
	return answer;
}
