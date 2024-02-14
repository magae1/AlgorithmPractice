import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner ac = new Scanner(System.in);
        int a = ac.nextInt();
        for(int i=0;i<a;i++){
            int b = ac.nextInt();
            int c = ac.nextInt();
            System.out.println(b+c);
        }
    }
}
