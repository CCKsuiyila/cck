import java.util.*;

public class homework_12{
    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        System.out.println("Enter five doubles:");
        ArrayList<Double> list = new ArrayList();
        Scanner input = new Scanner(System.in);
        while(list.add(input.nextDouble())&&list.size()<5){  }

        System.out.println("the sum of the five doubles is: "+sum(list));
    }
    
    public static double sum(ArrayList<Double> list){
        double sum = 0;
        for(int i=0; i<list.size(); ++i){
            sum += list.get(i);
        }
        return sum;
    }
}


