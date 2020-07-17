#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    sort(dist.begin(), dist.end());
    for (int i = 0; i < weak.size(); ++i) {
        int temp = weak[0] + n;
        for (int j = 1; j < weak.size(); ++j) 
        {
            weak[j - 1] = weak[j];
        }
        weak[weak.size() - 1] = temp;
        do {
            int w = 0;
            int cnt = 0;
            for (cnt = 0; cnt < dist.size();++cnt) {
                int curDist = weak[w] + dist[cnt];
                while (curDist >= weak[w]) {
                    ++w;
                    if (w == weak.size()) {
                        break;
                    }
                }
                if (w == weak.size()) {
                    break;
                }
            }
            if (w == weak.size()) {
                if (cnt + 1 < answer) {
                    answer = cnt + 1;
                }
            }
        } while (next_permutation(dist.begin(), dist.end()));
    }
    if (answer == 987654321)
        return -1;
    return answer;
}
