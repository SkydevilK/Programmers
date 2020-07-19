#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct fail {
	int stageNum;
	double failPercent;
};
bool compare(fail f1, fail f2)
{
    if (f1.failPercent == f2.failPercent)
        return f1.stageNum < f2.stageNum;
    return f1.failPercent > f2.failPercent;
}
vector<int> solution(int N, vector<int> stages) {
    vector<fail> v; 
    vector<int> answer;
    sort(stages.begin(), stages.end(), greater<int>());
    int num = 0;
    while ((num++ + 1) <= N) {
        int total = 0;
        int stay = 0;
        for (int i = 0; i < stages.size(); ++i) {
            if (stages[i] < num) 
                break;
            if (stages[i] >= num)
                ++total;
            if (stages[i] == num)
                ++stay;
        }
        double failPercent;
        if (stay == 0) {
            failPercent = 0;
        }
        else {
            failPercent = (double)stay / total;
        }
        v.push_back({num,failPercent });
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; ++i) {
        answer.push_back(v[i].stageNum);
    }
    return answer;
}
