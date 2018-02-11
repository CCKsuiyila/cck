import java.util.*;
import java.io.*;

public class homework_13{

	
    public static void main(String[] args)throws IOException{
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        File file = new File(args[0]);
        Scanner input = new Scanner(file);

        int count_char = 0;
        int count_String = 0;
        while(input.hasNext()){
            String read = input.next();
            ++count_String;
            count_char += read.length();
        }

        input.close();

        Scanner input1 = new Scanner(file);
        int count_Line = 0;
        while(input1.hasNext()){
            String read = input1.nextLine();
            ++count_Line;
        }

        input1.close();

        System.out.println("the number of char is: " + count_char);
        System.out.println("the number of String is: " + count_String);
        System.out.println("the number of Line is: " + count_Line);
    }
}

    
