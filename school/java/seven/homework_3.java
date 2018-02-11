import java.util.Scanner;

public class homework_3{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");
		
        Scanner input = new Scanner(System.in);
        System.out.println("please enter a integer");
        MyInteger test = new MyInteger(input.nextInt());
        System.out.println("the test's value is "+test.get());

        System.out.println("the test's value is Even? "+test.isEven());
        System.out.println("the test's value is Odd? "+test.isOdd());
        System.out.println("the test's value is Prime? "+test.isPrime());
        
        int test1 = 5;
        System.out.println("5 is Even? "+test.isEven(test1));
        System.out.println("5 is Odd? "+test.isOdd(test1));
        System.out.println("5 is Prime? "+test.isPrime(test1));

        MyInteger test2 = new MyInteger(5);
        System.out.println("5 is Even? "+test.isEven(test2));
        System.out.println("5 is Odd? "+test.isOdd(test2));
        System.out.println("5 is Prime? "+test.isPrime(test2));

        System.out.println("is 5 equal with the test'value? "+test.equals(test1));
        System.out.println("is 5 equal with the test'value? "+test.equals(test2));
        
        char[] test3 = {'2','1','0','a'};
        System.out.println("the test3 is "+test.parseInt(test3));
        String test4 = 210+"";
        System.out.println("the test4 is "+test.parseInt(test4)); 
	}
}

class MyInteger{
	private int value;
	
	MyInteger(int save){
		value = save;
	}
	int get(){
		return value;
	}
	
	boolean isEven(){
		if(value%2==0){
			return true;
		}else{
			return false;
		}
	}
	boolean isOdd(){
		if(value%2!=0){
			return true;
		}else{
			return false;
		}
	}
	boolean isPrime(){
		for(int i = 2;i<value;++i){
			if(value%i==0){
				return false;
			}
		}
		return true;
	}
	
	boolean isEven(int give){
		if(give%2==0){
			return true;
		}else{
			return false;
		}
	}
	boolean isOdd(int give){
		if(give%2!=0){
			return true;
		}else{
			return false;
		}
	}
	boolean isPrime(int give){
		for(int i = 2;i<give;++i){
			if(give%i==0){
				return false;
			}
		}
		return true;
	}
	
	boolean isEven(MyInteger give){
		if(give.value%2==0){
			return true;
		}else{
			return false;
		}
	}
	boolean isOdd(MyInteger give){
		if(give.value%2!=0){
			return true;
		}else{
			return false;
		}
	}
	boolean isPrime(MyInteger give){
		for(int i = 2;i<give.value;++i){
			if(give.value%i==0){
				return false;
			}
		}
		return true;
	}
	
	boolean equals(int give){
		if(give==value){
			return true;
		}else{
            return false;
        }
	}
    boolean equals(MyInteger give){
        if(give.value==value){
            return true;
        }else{
            return false;
        }
    }
    
    static  int parseInt(char[] give){
        int count = 0;
        for(; give [count]<='9'&&give[count]>='0';++count){
        }

        int result = 0;
        for(int i=count,j=0;i>0;--i,++j){
            int number = give[j]-'0';
            result += number*Math.pow(10,i-1);
        }
        return result;
    }

    static int parseInt(String give){
        int result = Integer.parseInt(give);
        return result;
    }
}

