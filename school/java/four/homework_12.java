public class homework_12{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		printChars('1','Z',10);
		
	}
	public static void printChars(char ch1,char ch2, int numberPerline){
		int count = 0;
		char temp = ch1;
		while(temp!=ch2){
			System.out.print(temp+" ");
            
			++temp;
			++count;
			while(count%numberPerline==0){
				System.out.println();
                break;
			}
		}
        System.out.print(temp+" "); 
	}
}
