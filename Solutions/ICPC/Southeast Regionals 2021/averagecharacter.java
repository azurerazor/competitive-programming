import java.util.*;

public class averagecharacter {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        int val = 0;

        for (int i = 0; i < s.length(); i++) {
            val += (int) s.charAt(i);
        }

        val /= s.length();

        System.out.println((char) val);
    }

}
