
//package java.lang;
import java.util.*;

abstract class GeometricObject {
    public abstract double findArea();

    public abstract double findPerimeter();

}



class Circle extends GeometricObject {
    private double r;

    public Circle(double r){
        this.r = r;
    }

    public double getR(){
        return r;
    }

    public double findArea(){
        return (Math.PI)*r*r;
    }

    public double findPerimeter(){
        return (Math.PI)*2*r;
    }
    
}

class ComparableCircle extends Circle implements Comparable<ComparableCircle>{

    public ComparableCircle(double r){
        super(r);
    }
    
    public int compareTo(ComparableCircle o){
        return (int)(this.findArea()-o.findArea());
    }
}



class homework_6{

    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        ComparableCircle circle_one = new ComparableCircle(5);
        System.out.println("the circle_one'radius: "+ 5);
        ComparableCircle circle_two = new ComparableCircle(10);
        System.out.println("the circle_two'radius: "+ 10);

        if(circle_one.compareTo(circle_two)<0){
            System.out.println("circle_two is bigger");
        }else if(circle_one.compareTo(circle_two)==0){
            System.out.println("circle_one equals to circle_two");
        }else{
            System.out.println("circle_one is bigger");
        }

    }
    
}
