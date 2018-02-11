
//package java.lang;
import java.util.*;

abstract class GeometricObject {
    public abstract double findArea();

    public abstract double findPerimeter();

}



class Circle extends GeometricObject implements Comparable<Circle>{
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

    public int compareTo(Circle o){
        return (int)(this.findArea()-o.findArea());
    }

    public boolean equals(Circle give_circle){
        if(give_circle.getR()==this.getR()){
            return true;
        }else{
            return false;
        }
    }
    
}





class homework_9{

    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        Circle circle_one = new Circle(5);
        System.out.println("the circle_one'radius: "+ 5);
        Circle circle_two = new Circle(10);
        System.out.println("the circle_two'radius: "+ 10);

        if(circle_one.equals(circle_two)){
            System.out.println("circle_one equals to circle_two");
        }else{
            System.out.println("circle_one doesn't equal to circle_two");
        }
        
        if(circle_one.compareTo(circle_two)<0){
            System.out.println("circle_two is bigger");
        }else if(circle_one.compareTo(circle_two)==0){
            System.out.println("circle_one equals to circle_two");
        }else{
            System.out.println("circle_one is bigger");
        }

    }
    
}
