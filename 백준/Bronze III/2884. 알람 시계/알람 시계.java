import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner ac = new Scanner(System.in);
        int a = ac.nextInt();
        int b = ac.nextInt();
        int c = a*60 + b;
        if (c<45){
            c = c + 1395;
        }else{
            c = c-45;
        }
        int hr = c/60;
        int mr = c%60;
        System.out.println(hr);
        System.out.println(mr);
    }
}