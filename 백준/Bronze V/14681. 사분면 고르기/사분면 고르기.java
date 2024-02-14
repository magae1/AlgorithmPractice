import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner qa = new Scanner(System.in);
        int a = qa.nextInt();
        int b = qa.nextInt();
        if(a>0){
            if(b>0){
                System.out.println("1");
            }else if(b<0){
                System.out.println("4");
            }
        }else if(a<0){
            if(b>0){
                System.out.println("2");
            }else if(b<0){
                System.out.println("3");
            }
        }
    }
}