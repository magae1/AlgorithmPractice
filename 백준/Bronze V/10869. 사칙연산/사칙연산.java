import java.util.*;

public class Main{
	public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
	    int c = a+b;
	    int d = a-b;
        int f = a*b;
        int g = a/b;
        int t = a%b;
        System.out.printf(c+"\n"+d+"\n"+f+"\n"+g+"\n"+t);
    }
}