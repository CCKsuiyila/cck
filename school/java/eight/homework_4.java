import java.util.*;

public class homework_4{
    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        System.out.println("please enter some Integers end with 0");
        ArrayList<Integer> list = new ArrayList();
        Scanner input = new Scanner(System.in);
        while(list.add(input.nextInt())&&list.get(list.size()-1)!=0){  }

        System.out.println("the max integer of the input is: "+max(list));
    }
    
    public static Integer max(ArrayList<Integer> list){
        if(list.size()==0){
            return null;
        }
        Integer result = new Integer(0);
        for(int i = 0; i<list.size(); ++i){
            if(list.get(i)>result){
                result = list.get(i);
            }
        }
        return result;
    }
}


