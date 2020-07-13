#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool check(string str) {
	int len = str.length();
	int num = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '(')
			++num;
		else {
			if (num == 0)
				return false;
			--num;
		}
	}
	return true;
}

string recursion(string str) {
	int len = str.length();
	if (len == 0)
		return "";
	string u, v;
	int L=0, R=0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '(')    
			++L;
		else  
			++R;
		if (L == R) {
			u = str.substr(0, i + 1);
			v = str.substr(i + 1);
			break;
		}
	}
	if (check(u))
		return u + recursion(v);
	else {
		string answer = "(";
		answer += recursion(v) + ")";
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); ++i) {
			if (u[i] == '(') 
				answer += ')';
			else    
				answer += '(';
		}
		return answer;
	}
}

string solution(string p) {
	if (check(p))
		return p;
	return recursion(p);
}

int main()
{
	cout << solution("(()())()");
}
/*
"(()())()"	"(()())()"
")("	"()"
"()))((()"	"()(())()"
*/
