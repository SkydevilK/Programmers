#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> reverseStr = words;
    int size = reverseStr.size();
    for (int i = 0; i < size; ++i)
    {
        reverse(reverseStr[i].begin(), reverseStr[i].end());
    }
    sort(words.begin(), words.end(),cmp);
    sort(reverseStr.begin(), reverseStr.end(), cmp);

    int len, lo, hi;
    int idx;
    for (string query : queries) {
        len = query.length();

        if (query[0] == '?') 
        {
            reverse(query.begin(), query.end());
            idx = query.find_first_of('?');

            for (int i = idx; i < len; ++i) 
                query[i] = 'a';
            lo = lower_bound(reverseStr.begin(), reverseStr.end(), query, cmp) - reverseStr.begin();

            for (int i = idx; i < len; ++i)
                query[i] = 'z';
            hi = upper_bound(reverseStr.begin(), reverseStr.end(), query, cmp) - reverseStr.begin();
        }
        else 
        {
            idx = query.find_first_of('?');

            for (int i = idx; i < len; ++i)
                query[i] = 'a';
            lo = lower_bound(words.begin(), words.end(), query, cmp) - words.begin();

            for (int i = idx; i < len; ++i)
                query[i] = 'z';
            hi = upper_bound(words.begin(), words.end(), query, cmp) - words.begin();
        }

        answer.push_back(hi - lo);
    }
    return answer;
}
