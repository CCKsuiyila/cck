import java.util.Scanner;

public class homework_1{

	public static class SimpleGeometricObject{
        private String color = "white";
        private boolean filled;
        private java.util.Date dateCreated;

        /**Construct a default geometric object */
        public SimpleGeometricObject(){
            dateCreated = new java.util.Date();
        }

        /**Construct a geometric object with the specified color
        *  and filled value */
        public SimpleGeometricObject(String color, boolean filled){
            dateCreated = new java.util.Date();
            this.color = color;
            this.filled = filled;
        }

        /**Return color*/
        public String getColor(){
            return color;
        }

        /**Set a new color */
        public void setColor(String color){
            this.color = color;
        }

        /** Return filled, Since filled is boolean,
        * its getter method is named isFilled */
        public boolean isFilled(){
            return filled;
        }   

        /** Set a new filled */
        public void setFilled(boolean filled){
            this.filled = filled;
        }

        /**Get dateCreated */
        public java.util.Date getDateCreated(){
            return dateCreated;
        }

        /**Return a string representation of this object */
        public String toString(){
            return "created on "+dateCreated + "/ncolor: " +color+" and filled: "+filled;
        }
    }

    public static class Triangle extends SimpleGeometricObject{
        private double side1;
        private double side2;
        private double side3;
    
        public Triangle(){
            side1 = 1.0;
            side2 = 1.0;
            side3 = 1.0;
        }

        public Triangle(double input1,double input2,double input3){
            side1 = input1;
            side2 = input2;
            side3 = input3;
        }

        public double get_side1(){
            return side1;
        }
        public double get_side2(){
            return side2;
        }
        public double get_side3(){
            return side3;
        }
    
        public double getArea(){
            double s = (side1+side2+side3)/2;
            double temp = s*(s-side1)*(s-side2)*(s-side3);
            return Math.sqrt(temp);
        }

        public double get_Perimeter(){
            return side1+side2+side3;
        }

        @Override
        public String toString(){
            return "Triangle: side1 = "+side1+" side2 = "+side2+" side3  = "+side3;
        }
    }

    
    public static void main(String[] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");
        Scanner input = new Scanner(System.in);

        System.out.println("please enter the length of the three sides");
        double sideone = input.nextDouble();
        double sidetwo = input.nextDouble();
        double sidethree = input.nextDouble();
        Triangle mytriangle = new Triangle(sideone,sidetwo,sidethree);

        System.out.println("please enter the color");
        String color = input.next();
        mytriangle.setColor(color);

        System.out.println("is the triangle is filled?");
        boolean filled = input.nextBoolean();
        mytriangle.setFilled(filled);

        System.out.println("the area of the triangle is: "+mytriangle.getArea());
        System.out.println("the Perimeter of the triangle is: "+mytriangle.get_Perimeter());
        System.out.println("the color of the triangle is: "+mytriangle.getColor());
        System.out.println("is  the triangle if filled? "+mytriangle.isFilled());
    }
}

    
