import java.util.*;
import java.io.*;

public class homework_1{

	
    public static void main(String[] args) throws IOException{
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);
	
	    try (
            Formatter output = new Formatter(new FileOutputStream("Exercise17_01.txt", true));
        ) {
            for (int i = 0; i < 100; i++){
                output.format("%d", (int)(Math.random() * 100));
            }
        }
    }
}


