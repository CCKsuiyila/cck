import java.util.Scanner;

public class homework_46{
    public static void main(String [] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        System.out.println("Enter a String:");
        Scanner input = new Scanner(System.in);
        String read_input = input.next();
        char[] chars = new char[read_input.length()];
        for(int i = read_input.length()-1; i>=0; --i){
            chars[i] = read_input.charAt(i);
            System.out.print(chars[i]);
        }
    }
}
