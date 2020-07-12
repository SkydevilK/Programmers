class Solution {
	static public int[] solution(String[] gems) {
		int[] answer = new int[2];
		int minCnt = 100001;
		Map<String, Integer> map = new HashMap<>();
		int len = gems.length;
		for (int i = 0; i < len; ++i) {
			map.put(gems[i], 0);
		}
		int s = 0;
		int e = 0;
		int size = map.size();
		int cnt = 0;
		while (true) {
			if (cnt == size) {
				int tmp = e - s;
				if (tmp < minCnt) {
					minCnt = tmp;
					answer[0] = s + 1;
					answer[1] = e;
				}
				map.put(gems[s], map.get(gems[s]) - 1);
				if (map.get(gems[s]) == 0) {
					--cnt;
				}
				++s;
			} else {
				if (map.get(gems[e]) == 0) {
					++cnt;
				}
				map.put(gems[e], map.get(gems[e]) + 1);
				++e;
			}
			if (cnt == size) {
				int tmp = e - s;
				if (tmp < minCnt) {
					minCnt = tmp;
					answer[0] = s + 1;
					answer[1] = e;
				}
			}
			if (e >= len)
				break;
			if (s >= len)
				break;
		}
		return answer;
	}
