
//package java.lang;
import java.util.*;

abstract class GeometricObject {
    public abstract double findArea();

    public abstract double findPerimeter();

}



class Rectangle extends GeometricObject implements Comparable<Rectangle>{
    private double w;
    private double h;

    public Rectangle(double w, double h){
        this.w = w;
        this.h = h;
    }

    public double findArea(){
        return w*h;
    }

    public double findPerimeter(){
        return 2*(w+h);
    }

    public int compareTo(Rectangle o){
        return (int)(this.findArea()-o.findArea());
    }

    public boolean equals(Rectangle give_rectangle){
        if(give_rectangle.findArea()==this.findArea()){
            return true;
        }else{
            return false;
        }
    }
}


class homework_10{

    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        Rectangle rectangle_one = new Rectangle(2,5);
        System.out.println("the rectangle_one'sides: "+ 2 + " " + 5);
        Rectangle rectangle_two = new Rectangle(1,10);
        System.out.println("the rectangle_two'sides: "+ 1 + " " + 10);

        if(rectangle_one.equals(rectangle_two)){
            System.out.println("rectangle_one equals to rectangle_two");
        }else{
            System.out.println("rectangle_one doesn't equal to rectangle_two");
        }
        
        if(rectangle_one.compareTo(rectangle_two)<0){
            System.out.println("rectangle_two is bigger");
        }else if(rectangle_one.compareTo(rectangle_two)==0){
            System.out.println("rectangle_one equals to rectangle_two");
        }else{
            System.out.println("rectangle_one is bigger");
        }

    }
    
}
