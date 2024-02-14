import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		int a,b;
        Scanner ac = new Scanner(System.in);
        a = ac.nextInt();
        b = ac.nextInt();
		int s1 = b%10;
        int s2 = b/10-(b/100)*10;
        int s3 = b/100;
        System.out.println(a*s1+"\n"+a*s2+"\n"+a*s3+"\n"+a*b);
	}
}