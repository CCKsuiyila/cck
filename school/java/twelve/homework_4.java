
import java.io.*;
import java.util.*;

public class homework_4{

	
    public static void main(String[] args) throws IOException{
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);
        
        try (
                BufferedReader input_one = new BufferedReader(new FileReader(args[0]));
                DataOutputStream output = new DataOutputStream(new FileOutputStream(args[1]));
        ) {
                String line;
                while ((line = input_one.readLine()) != null)
                    output.writeUTF(line);
        }

        try (
            InputStream input1 = new FileInputStream(args[0]);
            InputStream input2 = new FileInputStream(args[1]);
        ) {
            System.out.println(args[0] + "'s size is " + input1.available() + " bytes");
            System.out.println(args[1] + "'s size is " + input2.available() + " bytes");
        }
    }
}

