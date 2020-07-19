#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int len;
bool binary_search(int& n, int& k, vector<int>& v) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (v[i] - n <= 0)
            ++count;
        else
            count = 0;
        if (count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    len = stones.size();
    int first = 1;    
    int last = 0;
    for (int i = 0; i < len; ++i)
    {
        if (last < stones[i])
            last = stones[i];
    }

    while (first <= last) {
        int mid = (first + last) / 2;
        if (binary_search(mid, k, stones))
            last = mid - 1;
        else
            first = mid + 1;
    }
    return first;
}
