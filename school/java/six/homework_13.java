import java.util.Scanner;

public class homework_13{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");
		
		System.out.print("Enter the rows and columns in the array: ");
		Scanner input = new Scanner(System.in);
		int input_row = input.nextInt();
		int input_column = input.nextInt();
		double[][] array = new double[input_row][input_column];
		System.out.println("Enter the array: ");
		for(int i=0;i<input_row;++i){
			for(int j=0;j<input_column;++j){
				array[i][j] = input.nextDouble();
			}
		}
		
		Location output = locateLargest(array,input_row,input_column);
		System.out.println("The location of the largest element is "+output.maxValue+" at ("+output.row+","+output.column+")" );
		
		
	}
	
	public static Location locateLargest(double[][] a,int input_row,int input_column){
		Location result = new Location();
		result.row = 0;
		result.column = 0;
		result.maxValue = a[0][0];
		for(int i=0;i<input_row;++i){
			for(int j=0;j<input_column;++j){
				if(a[i][j]>result.maxValue){
					result.row = i;
					result.column = j;
					result.maxValue = a[i][j];
				}
			}
		}
		return result;
	}
}

class Location{
	int row;
	int column;
	double maxValue;
}

