public class homework_8{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");
		
		Fan one = new Fan();
		one.set_speed(one.FAST);
		one.set_radius(10);
		one.set_color("yellow");
		one.set_on(true);
		System.out.println(one.fantoString());
		System.out.println();
		
		Fan two = new Fan();
		two.set_speed(two.MEDIUM);
		two.set_radius(5);
		two.set_color("blue");
		two.set_on(false);
		System.out.println(two.fantoString());
		
	}
}

class Fan{
	
	final static int SLOW = 1;
	final static int MEDIUM = 2;
	final static int FAST = 3;
	
	private  int speed;
	private boolean on;
	private double radius;
	String color;
	
	Fan(){
		speed = SLOW;
		on = false;
		radius = 5;
		color = "blue";
	}
	
	int get_speed(){
		return speed;
	}
	void set_speed(int change_speed){
		speed = change_speed;
	}
	boolean get_on(){
		return on;
	}
	void set_on(boolean change_on){
		on = change_on;
	}
	double get_radius(){
		return radius;
	}
	void set_radius(double change_radius){
		radius = change_radius;
	}
	String get_color(){
		return color;
	}
	void set_color(String change_color){
		color = change_color;
	}
	
	String fantoString(){
		if(on==false){
			String result = "fan is off "+speed+" "+color+" "+radius+" ";
			return result;
		}else{
			String result = " "+speed+" "+color+" "+radius+" ";
			return result;
		}
	}
	
}