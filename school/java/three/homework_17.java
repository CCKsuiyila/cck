import java.util.Scanner;

public class homework_17{
    public static void main(String [] args){
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");

        System.out.println("enter the number of lines:");
        Scanner input = new Scanner(System.in);
        int get_input = input.nextInt();

        for(int i = 1; i<=get_input; ++i){
            for(int j = i; j<get_input; ++j){
                System.out.print("  ");
            }
            for(int j = i; j>=2; --j){
                System.out.print(j+" ");
            }
            for(int j = 1; j<=i; ++j){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}
