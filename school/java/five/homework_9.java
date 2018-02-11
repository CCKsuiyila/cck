import java.util.Scanner;

public class homework_9{
    public static void main(String[] args){
        
        System.out.println("name:cck, number:20151681310210");
        System.out.println("welcome to java");

        Scanner input = new Scanner(System.in);
        int lineindex;
        int columnindex;

        char[][] save = {{'a','b','c',' '},{'d','e','f',' '},{'g','h','i',' ',}};
        char people = 'x';
        int count = 0;
        while(count<9){
            display(save);
            System.out.println("Enter a row(0,1,or 2) for player "+people+": ");
            lineindex = input.nextInt();
            System.out.println("Enter a colunm (0, 1, or 2) for player "+people+": ");
            columnindex = input.nextInt();
            save[lineindex][columnindex] = people;
            if(judge(save)){
                display(save);
                System.out.println(people+" player won");
                return;
            }
            if(people=='x'){
                people='o';
            }else{
                people='x';
            }
            ++count;
        }
        System.out.println("game is drew");
    }

    public static void display(char[][] save){
        for(int j = 0; j<3; ++j){
            System.out.println("--------------------");
            for(int i = 0; i<4; ++i){
                if(save[j][i]=='x'||save[j][i]=='o'){
                    System.out.print("|"+save[j][i]);
                }else{
                    System.out.print("|"+' ');
                }
                
            }
            System.out.println();
        }
        System.out.println("------------------");
        
    }

    public static boolean judge(char[][] save){
       if(save[0][0]==save[0][1]&&save[0][1]==save[0][2]){
           return true;
       }else if(save[1][0]==save[1][1]&&save[1][1]==save[1][2]){
           return true;
       }else if(save[2][0]==save[2][1]&&save[2][1]==save[2][2]){
           return true;
       }else if(save[0][0]==save[1][0]&&save[1][0]==save[2][0]){
           return true;
       }else if(save[0][1]==save[1][1]&&save[1][1]==save[2][1]){
           return true;
       }else if(save[0][2]==save[1][2]&&save[1][2]==save[2][2]){
           return true;
       }else if(save[0][0]==save[1][1]&&save[1][1]==save[2][2]){
           return true;
       }else if(save[2][0]==save[1][1]&&save[1][1]==save[0][2]){
           return true;
       }
       return false;
    }
}
