import java.util.Scanner;

public class homework_19{
    public static void main(String[] args){
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");
        
        //input
        Scanner input = new Scanner(System.in);
        int row=input.nextInt();
        int column=input.nextInt();
        int[][] save = new int[row][column];
        for(int i=0;i<row;++i){
            for(int j=0;j<column;++j){
                save[row][column]=input.nextInt();
            }
        }






    }

    public static boolean isConsecutiveFour(int[][] values){
       //find in a row
       for(int i=0; i<row; ++j){
           for(int j=0; j<column-3; ++j){
               if(values[i][j]==values[i][j+1]&&values[i][j+1]==values[i][j+2]&&values[i][j+2]==values[i][j+3]){
                   return true;
               }
           }
       }
       //find in a colunm
       for(int j=0; j<column; ++j){
           for(int i=0; i<row-3; ++i){
               if(values[i][j]==values[i+1][j]&&values[i+1][j]==values[i+2][j]&&values[i+2][j]==values[i+3][j]){
                   return true;
               }
           }
       }
       //find in a na
       for(int i=0; i<row-3; ++i){
           for(int j=0; j<column-3; ++j){
                if(values[i][j]==values[i+1][j+1]&&values[i+1][j+1]==values[i+2][j+2]&&values[i+2][j+2]==values[i+3][j+3
           }
       }
    }
}
