import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner ac = new Scanner(System.in);
        int a = ac.nextInt();
        int b = ac.nextInt();
        if (a>b){
            System.out.println(">");
        }else if (a<b){
            System.out.println("<");
        }else{
            System.out.println("==");
        }
	}
}