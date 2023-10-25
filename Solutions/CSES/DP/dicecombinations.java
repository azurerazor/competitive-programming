import java.util.Scanner;

public class dicecombinations {
 
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		
		long[] dice = new long[n + 1];
		dice[0] = 1;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 6; j++) {
				if (i - j >= 0) dice[i] += dice[i - j];
			}
			dice[i] %= 1000000007;
		}
		
		System.out.println(dice[n]);
	}
 
}
