import java.util.Scanner;

public class homework_20{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		System.out.println("please enter a String");
		
		Scanner input = new Scanner(System.in);
		String input1 = input.nextLine();
		int result = countLetters(input1);
        System.out.println(result);
	}
	public static int countLetters(String s){
		return s.length();
	}
}
