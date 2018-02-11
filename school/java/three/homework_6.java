public class homework_6{
    public static void main(String [] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        int mile = 1;
        int kilometer = 20;
        System.out.println("mile    kilometer    kilometer    mile");
        while(mile<=10){
            System.out.printf("%4d    %9.3f    %9d    %4.3f",mile,mile*1.609,kilometer,kilometer/1.609);
            System.out.println();
            ++mile;
            kilometer += 5;
        }
    }
}
