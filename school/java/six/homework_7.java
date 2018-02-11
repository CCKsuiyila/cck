public class homework_7{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");
		
		Account one = new Account(1122,20000);
		one.set_annualInterestRate(4.5);
		one.withDraw(2500);
		one.deposit(3000);
		System.out.println("the balance is: "+one.get_balance());
		System.out.println("the monthlyInterest is: "+one.getMonthlyInterest()+"$");
		System.out.println("the open_account_date is: "+one.get_dateCreated());
	}
}

class Account{
	private int id;
	private double balance;
	private double annualInterestRate;
	private java.util.Date dateCreated;
	
	Account(){
		id = 0;
		balance = 0;
		annualInterestRate = 0;
		dateCreated = new java.util.Date();
	}
	
	Account(int input_id, double input_balance){
		id = input_id;
		balance = input_balance;
		annualInterestRate = 0;
		dateCreated = new java.util.Date();
	}
	
	int get_id(){
		return id;
	}
	void set_id(int change_id){
		id = change_id;
	}
	double get_balance(){
		return balance;
	}
	void set_balance(double change_balance){
		balance = change_balance;
	}
	double get_annualInterestRate(){
		return annualInterestRate;
	}
	void set_annualInterestRate(double change_annualInterestRate){
		annualInterestRate = change_annualInterestRate;
	}
	java.util.Date get_dateCreated(){
		return dateCreated;
	}
	
	double getMonthlyInterestRate(){
		return annualInterestRate/12;
	}
	double getMonthlyInterest(){
		return balance*1*getMonthlyInterestRate()/100;
	}
	
	void withDraw(double get_money){
		balance -= get_money;
	}
	
	void deposit(double save_money){
		balance += save_money;
	}
}	
	