import java.util.Scanner;

public class homework_2{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		System.out.println("please enter a integer");
		
		Scanner input = new Scanner(System.in);
		int input1 = input.nextInt();
		int output = sumDigits(input1);
		System.out.println(output);
		
	}
	public static int sumDigits(int n){
		int sum = 0;
		int add = 0;
		while(n!=0){
			add = n%10;
			sum += add;
			n /= 10;
		}
		return sum;
	}
}
