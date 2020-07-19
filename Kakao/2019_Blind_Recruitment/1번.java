import java.util.*;

class Solution {
	public String[] solution(String[] record) {
		String[] answer = {};
		int len = record.length;
		Map<String, String> map = new HashMap<String, String>();
		List<String> list = new ArrayList<String>();
		int cnt = 0;
		for (int i = 0; i < len; ++i) {
			String[] str = record[i].split(" ");

			if (str[0].equals("Enter")) {
				map.put(str[1], str[2]);
				list.add(str[1] + " " + "E");
			} else if (str[0].equals("Leave")) {
				list.add(str[1] + " " + "L");
			} else {
				map.put(str[1], str[2]);
			}
		}
		len = list.size();
		answer = new String[len];
		for (int i = 0; i < len; ++i) {
			String[] str = list.get(i).split(" ");
			if (str[1].equals("E"))
				answer[i] = map.get(str[0]) + "님이 들어왔습니다.";
			else
				answer[i] = map.get(str[0]) + "님이 나갔습니다.";
		}
		return answer;
	}
}
