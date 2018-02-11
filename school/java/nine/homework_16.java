import java.util.*;
import java.io.*;

public class homework_16{

	
    public static void main(String[] args)throws IOException{
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        File sourceFile = new File(args[0]);
        File temp = new File("temp.txt");
        
        Scanner input = new Scanner(sourceFile);
        PrintWriter output = new PrintWriter(temp);

        while(input.hasNext()){
            String s1 = input.nextLine();
            String s2 = s1.replaceAll(args[1],args[2]);
            output.println(s2);
        }

        input.close();
        output.close();

        File sourceFile1 = new File("temp.txt");
        File targetFile1 = new File(args[0]);

        Scanner input1 = new Scanner(sourceFile1);
        PrintWriter output1 = new PrintWriter(targetFile1);

        while(input1.hasNext()){
            String s1 = input1.nextLine();
            output1.println(s1);
        }

        input1.close();
        output1.close();
    }
}

    
