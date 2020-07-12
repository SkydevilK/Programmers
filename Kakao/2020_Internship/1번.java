class POS {
	int x;
	int y;

	public POS(int x, int y) {
		this.x = x;
		this.y = y;
	}
};

class Solution {
	static final POS NUMBER[] = { new POS(3, 1), new POS(0, 0), new POS(0, 1), new POS(0, 2), new POS(1, 0),
			new POS(1, 1), new POS(1, 2), new POS(2, 0), new POS(2, 1), new POS(2, 2), new POS(3, 0), new POS(3, 1),
			new POS(3, 2) };

	int dist(POS p1, POS p2) {
		return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
	}

	public String solution(int[] numbers, String hand) {
		String answer = "";
		StringBuilder sb = new StringBuilder();
		POS lPos = NUMBER[10];
		POS rPos = NUMBER[12];
		for (int i = 0; i < numbers.length; ++i) {
			switch (numbers[i]) {
			case 1:
			case 4:
			case 7:
				sb.append('L');
				lPos = NUMBER[numbers[i]];
				break;
			case 3:
			case 6:
			case 9:
				sb.append('R');
				rPos = NUMBER[numbers[i]];
				break;
			case 2:
			case 5:
			case 8:
			case 0:
				int lDist = dist(lPos, NUMBER[numbers[i]]);
				int rDist = dist(rPos, NUMBER[numbers[i]]);
				if (lDist < rDist) {
					sb.append('L');
					lPos = NUMBER[numbers[i]];
				} else if (lDist > rDist) {
					sb.append('R');
					rPos = NUMBER[numbers[i]];
				} else {
					if (hand.equals("left")) {
						sb.append('L');
						lPos = NUMBER[numbers[i]];
					} else {
						sb.append('R');
						rPos = NUMBER[numbers[i]];
					}
				}
				break;
			}
		}
		answer = sb.toString();
		return answer;
	}
}
