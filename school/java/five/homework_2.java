import java.util.Scanner;

public class homework_2{
    public static void main(String[] args){
        
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");
        System.out.println("Enter a 4-by-4 matrix row by row: ");

        Scanner input = new Scanner(System.in);
        double[][] save = new double[4][4];
        for(int i=0; i<4; ++i){
            for(int j = 0; j<4; ++j){
                save[i][j] = input.nextDouble();
            }
        }
        System.out.println("Sum of the elements in the major diagonal: "+ sumMajorDiagonal(save));
    }

    public static double sumMajorDiagonal(double[][] m){
        double sum = 0;
        for(int i=0; i<4; ++i){
            sum += m[i][i];
        }
        return sum;
    }
}
