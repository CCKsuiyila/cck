import java.util.*;

public class homework_1_try{

	
    public static void main(String[] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);

        if(args.length != 3){
            System.out.println("Usage: java Calculator operand1 operator operand2");
            System.exit(0);
        }
        int sign = 0;
        try{
            for(int i = 0; i<args[0].length(); ++i){
                if(args[0].charAt(i)<'0'||args[0].charAt(i)>'9'){
                    throw new InputMismatchException("Wrong input; "+args[0]);
                }
            }  
        }
        catch(InputMismatchException ex){
            System.out.println("Wrong input: "+args[0]);
            sign = 1;
        }
        try{
            for(int i = 0; i<args[2].length(); ++i){
                if(args[2].charAt(i)<'0'||args[2].charAt(i)>'9'){
                    throw new ArithmeticException("Wrong input; "+args[2]);
                }
            }  
        }
        catch(ArithmeticException ex){
            System.out.println("Wrong input: "+args[2]);
            sign = 1;
        }
        
        if(sign != 0){
            System.exit(0);
        }

        
        
        

        int result = 0; 
        switch (args[1].charAt(0)){
            case '+': result = Integer.parseInt(args[0]) + Integer.parseInt(args[2]); break;
            case '-': result = Integer.parseInt(args[0]) - Integer.parseInt(args[2]); break;
            case '.': result = Integer.parseInt(args[0]) * Integer.parseInt(args[2]); break;
            case '/': result = Integer.parseInt(args[0]) / Integer.parseInt(args[2]); break;
        }

        System.out.println(args[0] + ' ' + args[1] + ' ' + args[2] + " = " + result);

        
    }
}

    