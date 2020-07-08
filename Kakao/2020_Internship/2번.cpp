#include<iostream>
#include <string>
#include <vector>
using namespace std;
char op[] = { '+','-','*' };
bool isCheck[3];
vector<long long> numbers;
vector<char> ops;
long long answer = 0;
long long calc(long long num1, long long num2, char op) {
	long long num = 0;
	switch (op) {
	case '+': {
		return num1 + num2;
	}
	case '-': {
		return num1 - num2;
	}
	case '*': {
		return num1 * num2;
	}
	}
	return num;
}

void dfs(int count, char p[3]) {
	if (count == 3) {
		vector<long long> tempNumbers = numbers;
		vector<char> tempOps = ops;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < tempOps.size(); ++j) {
				if (p[i] == tempOps[j]) {
					long long num1 = tempNumbers[j];
					tempNumbers.erase(tempNumbers.begin() + j);
					long long num2 = tempNumbers[j];
					tempNumbers.erase(tempNumbers.begin() + j);
					long long res = calc(num1, num2, p[i]);
					tempNumbers.insert(tempNumbers.begin() + j, res);
					tempOps.erase(tempOps.begin() + j);
					--j;
				}
			}
		}
		answer = answer > abs(tempNumbers[0]) ? answer : abs(tempNumbers[0]);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (!isCheck[i]) {
			isCheck[i] = true;
			p[count] = op[i];
			dfs(count + 1, p);
			isCheck[i] = false;
		}
	}
}
long long solution(string expression) {
	answer = 0;
	string num = "";
	for (int i = 0; i < expression.length(); ++i) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			num += expression[i];
		}
		else {
			numbers.push_back(stoll(num));
			num = "";
			ops.push_back(expression[i]);
		}
	}
	numbers.push_back(stoll(num));
	dfs(0, new char[3]);
	return answer;
}

int main()
{
	cout << solution("100-200*300-500+20") << endl;
	cout << solution("50*6-3*2") << endl;
}
/*
"100-200*300-500+20"	60420
"50*6-3*2"	300
*/
