import java.util.Scanner;

abstract class GeometricObject{
    public abstract double findArea();

    public abstract double findPerimeter();
}

class Rectangle extends GeometricObject{
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
}

class Circle extends GeometricObject{
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

class Cylinder extends Circle{
    private double h;
    //extends from Circle
    //private double r;

    public Cylinder(double r,double h){
        super(r);
        this.h = h;
    }

    //重写覆盖
    public double findArea(){
        double temp_r = super.getR();
        return (Math.PI)*temp_r*temp_r*2+(Math.PI)*temp_r*2*h;
    }
    public double findPerimeter(){
        double temp_r = super.getR();
        return (Math.PI)*temp_r*2*2;
    }
}

class GeoAreaSum{

    public static void main(String Args[]){

	System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        GeometricObject circle = new Circle(5);
        GeometricObject cylinder = new Cylinder(10,5);
        GeometricObject rectangle = new Rectangle(6,8);
        GeometricObject[] a = {circle,cylinder,rectangle};
        System.out.println(sumArea(a));
    }
    public static double sumArea(GeometricObject[] a){
        double sum = 0;
        for(int i=0; i<3; ++i){
            sum += a[i].findArea();
        }
        
        return sum;
    }
}
