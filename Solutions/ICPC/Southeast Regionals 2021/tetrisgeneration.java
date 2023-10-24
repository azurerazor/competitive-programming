import java.util.*;
import java.lang.Math;

public class tetrisgeneration {

    public static HashMap<Character, Integer> hm = new HashMap<Character, Integer>();

    public static void main(String[] args) {
        hm.put('J', 0);
        hm.put('L', 1);
        hm.put('S', 2);
        hm.put('Z', 3);
        hm.put('I', 4);
        hm.put('O', 5);
        hm.put('T', 6);

        Scanner sc = new Scanner(System.in);

        int c = sc.nextInt();
        sc.nextLine();

        while (c-->0) {
            String s = sc.nextLine();

            System.out.println(solve(s));
        }
    }

    static int solve(String s) {
        boolean[] isValidAt = new boolean[7];

        for (int i = 0; i < s.length() + 6; i++) {
            if (isValidAt[i % 7])
                continue;


            String ssub = s.substring(Math.max(i - 6, 0), Math.min(i + 1, s.length()));

            boolean[] checker = new boolean[7];

            for (int j = 0; j < ssub.length(); j++) {
                if(checker[hm.get(ssub.charAt(j))]) {
                    isValidAt[i % 7] = true;
                    break;
                }

                checker[hm.get(ssub.charAt(j))] = true;
            }
        }

        for (int i = 0; i < 7; i++) {
            if (!isValidAt[i]) {
                return 1;
            }
        }

        return 0;
    }

}
