import java.util.Scanner;

public class homework_50{
    public static void main(String [] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        System.out.println("Enter a String:");
        Scanner input = new Scanner(System.in);
        String read_input = input.next();
        int count = 0;
        for(int i = 0; i<read_input.length(); ++i){
            if(read_input.charAt(i)>='A'&&read_input.charAt(i)<='Z'){
                ++count;
            }
        }
        System.out.println(count);
    }
}
