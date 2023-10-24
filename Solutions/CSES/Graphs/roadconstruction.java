import java.io.*;
import java.util.*;
import java.lang.Math;
 
class DSU {
    int[] s;
    int groups;
    int maxSize;
    public DSU(int n) {
        s = new int[n];
        Arrays.fill(s, -1);
        groups = n;
        maxSize = 1;
    }
    int find(int v) {return (s[v] < 0) ? v : (s[v] = find(s[v]));};
    int size(int v) {return -s[find(v)];}
 
    boolean union(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) {
            int temp = b;
            b = a;
            a = temp;
        }
        s[a] += s[b];
        s[b] = a;
        groups--;
        maxSize = Math.max(maxSize, -s[a]);
        return true;
    }
}
 
public class roadconstruction {
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
 
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
 
        DSU d = new DSU(n);
 
        for (int i = 0; i < m; i++) {
            String[] line2 = br.readLine().split(" ");
            int a = Integer.parseInt(line2[0]) - 1;
            int b = Integer.parseInt(line2[1]) - 1;
 
            d.union(a, b);
            pw.print(d.groups + " " + d.maxSize + "\n");
        }
 
        pw.flush();
    }
 
}
