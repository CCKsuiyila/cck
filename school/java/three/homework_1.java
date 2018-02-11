import java.util.Scanner;

public class homework_1{
    public static void main(String [] args){
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");
        System.out.println("enter an integer, the input ends if it is 0;");

        Scanner input = new Scanner(System.in);
        int read_input = input.nextInt();
        int count_positive = 0;
        int count_negative = 0;
        int sum = 0;

        while(read_input!=0){
            sum += read_input;
            if(read_input>0){
                ++count_positive;
            }else{
                ++count_negative;
            }
            read_input = input.nextInt();
        }

        System.out.println("the number of positives is: " + count_positive);
        System.out.println("the number of negatives is: " + count_negative);
        System.out.println("the total is: " + sum);
        System.out.println("the average is: " + sum/1.0/(count_positive+count_negative));
    }
}
