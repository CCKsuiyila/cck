public class homework_33{
    public static void main(String [] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        int sum = 1;
        int i = 6;
        for(; i<10000; ++i){
            for(int j = 2; j<Math.pow(i,0.5); ++j){
                if(i%j==0){
                    sum += j;
                    sum += i/j;
                }
            }
            if(sum==i){
                System.out.println(i);
            }
            sum = 1;
        }
    }
}

