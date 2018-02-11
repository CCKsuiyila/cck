import java.util.*;

public class homework_2{

	
    public static void main(String[] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);

        boolean continueInput = true;
        do{
            try{
                System.out.println("Enter two integer: ");
                int number1 = input.nextInt();
                int number2 = input.nextInt();

                System.out.println(number1 + "+" +number2 + "=" + (number1+number2));
                continueInput = false;
            }
            catch(InputMismatchException ex){
                System.out.println("Try again. (Incorrect input: two integer is required)");
                input.nextLine();
            }

        }while(continueInput);
        
        

        
    }
}

    
