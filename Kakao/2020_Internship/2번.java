import java.util.*;

public class Solution {
	char[] ops;
	long answer;
	String expression;

	public Long solution(String expression) {
		this.expression = expression;
		List<Character> op = new ArrayList<>();
		if (expression.contains("+")) {
			op.add('+');
		}
		if (expression.contains("-")) {
			op.add('-');
		}
		if (expression.contains("*")) {
			op.add('*');
		}
		ops = new char[op.size()];
		for (int i = 0; i < ops.length; ++i) {
			ops[i] = op.get(i);
		}
		answer = -1;
		DFS(0);
		return answer;
	}

	void DFS(int depth) {
		if (depth == ops.length) {
			long result = calc();
			answer = Math.max(result, answer);
			return;
		}
		for (int i = depth; i < ops.length; ++i) {
			swap(i, depth);
			DFS(depth + 1);
			swap(i, depth);
		}
	}

	void swap(int i, int j) {
		char c = ops[i];
		ops[i] = ops[j];
		ops[j] = c;
	}

	long calc() {
		HashMap<String, Integer> hm = new HashMap<>();
		for (int i = 0; i < ops.length; i++) {
			hm.put(String.valueOf(ops[i]), i);
		}
		StringBuilder sb = new StringBuilder();
		List<String> list = new ArrayList<>();
		Stack<String> arg = new Stack<>();
		int len = this.expression.length();
		for (int i = 0; i < len; i++) {
			char c = this.expression.charAt(i);
			if (c == '+' || c == '-' || c == '*') {
				list.add(sb.toString());
				sb.delete(0, sb.length());
				while (!arg.isEmpty() && hm.get(String.valueOf(c)) <= hm.get(arg.peek())) {
					list.add(arg.pop());
				}
				arg.push(String.valueOf(c));
			} else {
				sb.append(c);
			}
		}
		list.add(sb.toString());
		while (!arg.isEmpty()) {
			list.add(arg.pop());
		}

		Stack<Long> value = new Stack<>();
		for (String s : list) {
			if (hm.containsKey(s)) {
				long b = value.pop();
				long a = value.pop();
				if (s.equals("+")) {
					value.push(a + b);
				}
				if (s.equals("-")) {
					value.push(a - b);
				}
				if (s.equals("*")) {
					value.push(a * b);
				}
			} else {
				value.push(Long.parseLong(s));
			}
		}
		return Math.abs(value.pop());
	}
}
