public class homework_10{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		
		int count =1;
		for(int i = 3;i<10000;++i){
			if(isPrime(i)==true){
				++count;
			}
		}
		System.out.println(count);
	}
	public static boolean isPrime(int number){
		for(int i = 2; i<number; ++i){
			if(number%i==0){
				return false;
			}
		}
		return true;
	}
}