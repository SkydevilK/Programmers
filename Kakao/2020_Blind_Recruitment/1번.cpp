#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	if (s.length() == 1)
		return 1;
	int len = s.length();
	int halfLen = len / 2;
	for (int i = 1; i <= halfLen; ++i) {
		int count = 1;
		string start = s.substr(0, i);
		string cmp;
		string str;
		
		for (int j = i; j < len; j += i) {
			cmp = s.substr(j, i);

			if (start.compare(cmp) == 0)
				count++;
			else {
				if (count != 1) {
					str += to_string(count);
				}
				str += start;
				start = cmp;
				count = 1;
			}
			if (j + i >= len) {
				if (count != 1) {
					str += to_string(count) + start;
				}
				else {
					str += s.substr(j);
					break;
				}
				break;
			}
		}
		answer = (answer > str.length()) ? str.length() : answer;
	}
	return answer;
}
int main() {	
	cout << solution("aabbaccc");
}

/*
"aabbaccc"	7
"ababcdcdababcdcd"	9
"abcabcdede"	8
"abcabcabcabcdededededede"	14
"xababcdcdababcdcd"	17
*/
