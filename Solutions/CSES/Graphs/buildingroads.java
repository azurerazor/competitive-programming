import java.io.*;
 
public class buildingroads {
	
	static int[] parent = new int[100000];
	static int comp = 0;
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int m = Integer.parseInt(line[1]);
		
		for (int i = 0; i < n; i++) {
			makeSet(i);
		}
		
		for (int i = 0; i < m; i++) {
			line = br.readLine().split(" ");
			int x = Integer.parseInt(line[0]) - 1;
			int y = Integer.parseInt(line[1]) - 1;
			
			union(x, y);
		}
		
		System.out.println(comp - 1);
		
		if (comp > 1) {
			for (int i = 1; i < n; i++) {
				if (parent[i] == i) {
					System.out.println(Integer.toString(1) + " " + Integer.toString(i + 1));
				}
			}
		}
	}
	
	static void makeSet(int v) {
		parent[v] = v;
		comp++;
	}
	
	static int findSet(int v) {
		if (parent[v] == v) {
			return v;
		}
		
		return parent[v] = findSet(parent[v]);
	}
	
	static void union(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		
		if (a != b) {
			parent[b] = a;
			comp--;
		}
	}
 
}
