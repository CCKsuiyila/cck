
//package java.lang;
import java.util.*;

abstract class GeometricObject implements Comparable<GeometricObject>{
    public abstract double findArea();

    public abstract double findPerimeter();

    public int compareTo(GeometricObject o){
        return 0;
    }

    public static String max(GeometricObject one,GeometricObject two){
        if(one.findArea()>two.findArea()){
            return "one is bigger";
        }else if(one.findArea()==two.findArea()){
            return "one equals to two";
        }else{
            return "two is bigger";
        }
    }
}

class Rectangle extends GeometricObject /*implements Comparable<Rectangle>*/{
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
        return (int)(findArea()-o.findArea());
    }
}

class Circle extends GeometricObject /*implements Comparable<Circle>*/{
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
        return (int)(findArea()-o.findArea());
    }
}

class Cylinder extends GeometricObject /*implements Comparable<Cylinder>*/{
    private double h;
    private double r;

    public Cylinder(double r,double h){
        this.h = h;
        this.r = r;
    }

    public double findArea(){
        return (Math.PI)*r*r*2+(Math.PI)*r*2*h;
    }

    public double findPerimeter(){
        return (Math.PI)*r*2*2;
    }
    
    public int compareTo(Cylinder o){
        return (int)(findArea()-o.findArea());
    }
}

class homework_5{

    public static void main(String args[]){

	System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        GeometricObject circle_one = new Circle(5);
        System.out.println("the circle_one'radius: "+ 5);
        GeometricObject circle_two = new Circle(10);
        System.out.println("the circle_two'radius: "+ 10);
        System.out.println("the circle: "+GeometricObject.max(circle_one,circle_two));

        GeometricObject rectangle_one = new Rectangle(2,2);
        System.out.println("the rectangle_one'sides: "+ 2 +" "+2);
        GeometricObject rectangle_two = new Rectangle(3,3);
        System.out.println("the rectangle_two'sides: "+ 3 +" "+3);
        System.out.println("the rectangle: "+GeometricObject.max(rectangle_one,rectangle_two));
    }
    
}
