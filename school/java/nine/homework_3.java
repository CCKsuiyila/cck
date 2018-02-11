import java.util.*;

public class homework_3{

	
    public static void main(String[] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);

        int[] array = new int[100];
        for(int i = 0;i<100; ++i){
            array[i] = (int)(Math.random()*1000);
        }

        try{
            System.out.println("please enter a integer between 0 to 99");
            int index = input.nextInt();

            System.out.println(array[index]);
        }
        catch(ArrayIndexOutOfBoundsException ex){
            System.out.println("Out of Bounds");
        }

        
    }
}

    
