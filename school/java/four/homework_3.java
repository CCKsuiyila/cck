import java.util.Scanner;

public class homework_3{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		System.out.println("please enter a integer");
		
		Scanner input = new Scanner(System.in);
		int input1 = input.nextInt();
		boolean output = isPalindrome(input1);
		System.out.println(output);
		
	}
	public static int reverse(int number){
		int[] array = new int[50];
		int count = 0;
		
		while(number!=0){
			array[count++] = number%10;
			number /= 10;
		}
		--count;
		int sum = 0;
		for(int i=0; count>=0; ++i,--count){
			sum += Math.pow(10,count)*array[i];
		}
		return sum;
	}
	public static boolean isPalindrome(int number){
		int temp = reverse(number);
		if(temp==number){
			return true;
		}else{
			return false;
		}
	}
}