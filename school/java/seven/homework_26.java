public class homework_26{
    public static void main(String[] args){
        char[] temp = new char[15];
        char operation;
        int one_length=0;
        int two_length=0;
        int result =0;

        int count = 0;

        for(;count<args[0].length()&&args[0].charAt(count)>='0'&&args[0].charAt(count)<='9';++one_length,++count){
            temp[one_length]=args[0].charAt(count);
        }
        char[] one = new char[one_length];
        for(int i=0; i<one_length; ++i){
            one[i] = temp[i];
        }
        String s_one = new String(one);
        

        for(;count<args[0].length()&&args[0].charAt(count)==' ';++count){}
        operation = args[0].charAt(count);
        ++count;
        

        for(;count<args[0].length()&&args[0].charAt(count)==' ';++count){}
        for(;count<args[0].length();++two_length,++count){
            temp[two_length]=args[0].charAt(count);
        }
        char[] two = new char[two_length];
        for(int i = 0;i<two_length; ++i){
            two[i] = temp[i];
        }
        String s_two = new String(two);


        
        switch(operation){
            case '+': result = Integer.parseInt(s_one) + Integer.parseInt(s_two); break;
            case '-': result = Integer.parseInt(s_one) - Integer.parseInt(s_two); break;
            case '.': result = Integer.parseInt(s_one) * Integer.parseInt(s_two); break;
            case '/': result = Integer.parseInt(s_one) / Integer.parseInt(s_two); break;
            
        }

        System.out.println(s_one + "+"+  s_two+ "=" + result);

    }
}
