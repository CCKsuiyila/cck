import java.util.Scanner;

public class homework_5{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");

        System.out.println("please enter a integer");
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        int count = 0;
        int[] save = new int[100];

        while(number!=1){
            int i=2;
            for(;i<=number;++i){
                if(number%i==0){
                    save[count]=i;
                    ++count;
                    number /= i;
                    break;
                }
            }
        }

        for(int i=count-1;i>=0;--i){
            System.out.println(save[i]);
        }
    }
}


