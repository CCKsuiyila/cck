import java.util.Scanner;

public class homework_4{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");

        MyPoint first = new MyPoint();
        MyPoint second = new MyPoint(10,30.5);
        System.out.println("the distance of the two point is: "+first.distance(second));
    }
}

class MyPoint{
    private double x;
    private double y;

    double get_x(){
        return x;
    }

    double get_y(){
        return y;
    }
	
    MyPoint(){
        x=0;
        y=0;
    }
    MyPoint(double give_x,double give_y){
        x=give_x;
        y=give_y;
    }
    double distance(MyPoint give){
        double result = Math.sqrt(Math.pow(give.get_x()-x,2)+Math.pow(give.get_y()-y,2));
        return result;
    }
    double distance(int give_x,int give_y){
        double result = Math.sqrt(Math.pow(give_x-x,2)+Math.pow(give_y-y,2));
        return result;
    }
}

