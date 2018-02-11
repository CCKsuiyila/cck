import java.util.*;
import java.io.*;

public class homework_11{

	
    public static void main(String[] args)throws IOException{
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        File file = new File(args[1]);
        File temp_file = new File("temp.txt");
        Scanner input = new Scanner(file);
        PrintWriter output = new PrintWriter(temp_file);

        while(input.hasNext()){
            String read = input.nextLine();
            String temp = read.replaceAll(args[0],"");
            output.println(temp);
        }

        input.close();
        output.close();
        
        Scanner input1 = new Scanner(temp_file);
        PrintWriter output1 = new PrintWriter(file);
        while(input1.hasNext()){
            String write = input1.nextLine();
            output1.println(write);
        }
        
        input1.close();
        output1.close();
    }
}

    
