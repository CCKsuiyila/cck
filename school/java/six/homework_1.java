public class homework_1{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");
		
		rectangle first = new rectangle(4,40);
		System.out.println("the width of the first is: "+first.width);
		System.out.println("the height of the first is: "+first.height);
		System.out.println("the area of the first is: "+first.getArea());
		System.out.println("the perimeter of the first is: "+first.getPerimeter());
		System.out.println("the number is: "+rectangle.count);
		System.out.println();
		
		rectangle second = new rectangle(3.5,35.9);
		System.out.println("the width of the second is: "+second.width);
		System.out.println("the height of the second is: "+second.height);
		System.out.println("the area of the second is: "+second.getArea());
		System.out.println("the perimeter of the second is: "+second.getPerimeter());
		System.out.println("the number is: "+rectangle.count);
	}
}

class rectangle{
	
	double width;
	double height;
	static int count = 0;
	
	rectangle(){
		width = 1;
		height = 1;
		++count;
	}
	
	rectangle(double input_width, double input_height){
		width = input_width;
		height = input_height;
		++count;
	}
	
	double getArea(){
		double area = width*height;
		return area;
	}
	
	double getPerimeter(){
		double perimeter = 2*(width+height);
		return perimeter;
	}
}