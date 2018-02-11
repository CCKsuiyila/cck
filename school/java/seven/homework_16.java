import java.util.Scanner;

public class homework_16{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");

        int count = 0;
        for(int i=0;count<10;++i){
            if(i%2==0||i%3==0){
                System.out.print(i+" ");
                ++count;
            }
        }
        System.out.println();
    }
}


