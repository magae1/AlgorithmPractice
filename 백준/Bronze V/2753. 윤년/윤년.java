import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
        Scanner ac = new Scanner(System.in);
		int a = ac.nextInt();
        if (a%4 == 0){
            if (a%400 == 0 || a%100 != 0){
                System.out.println("1");
            }else{
                System.out.println("0");
            }
        }else{
            System.out.println("0");
        }
	}
}