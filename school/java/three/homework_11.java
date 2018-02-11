public class homework_11{
    public static void main(String [] args){
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");

        int count = 0;
        int now_number = 100;
        while(now_number<=200){
            if((now_number%5==0&&now_number%6!=0)||(now_number%5!=0&&now_number%6==0)){
                System.out.print(now_number+" ");
                ++count;
                while(count%10==0){
                    System.out.println();
                    break;
                }
            }
            ++now_number;
        }
    }
}

