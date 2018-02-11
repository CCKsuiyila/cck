import java.util.Scanner;

public class homework_1{
    public static void main(String[] args){
        
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");
        System.out.println("Enter a 3-by-4 matrix row by row: ");

        Scanner input = new Scanner(System.in);
        double[][] save = new double[3][4];
        for(int i=0; i<3; ++i){
            for(int j = 0; j<4; ++j){
                save[i][j] = input.nextDouble();
            }
        }
        System.out.println("Sum of the elements at column 0 is: "+ sumColumn(save,0));
        System.out.println("Sum of the elements at column 1 is: "+ sumColumn(save,1));
        System.out.println("Sum of the elements at column 2 is: "+ sumColumn(save,2));
        System.out.println("Sum of the elements at column 3 is: "+ sumColumn(save,3));
    }

    public static double sumColumn(double[][] m, int columnIndex){
        double sum = 0;
        for(int i=0; i<3; ++i){
            sum += m[i][columnIndex];
        }
        return sum;
    }
}
