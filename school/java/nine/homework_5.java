import java.util.Scanner;

public class homework_5{

	
    public static void main(String[] args){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        try{
            System.out.println("please enter three integer as three sides of the triangle: ");
            Scanner input = new Scanner(System.in);
            double side1 = input.nextDouble();
            double side2 = input.nextDouble();
            double side3 = input.nextDouble();

            Triangle mytriangle = new Triangle(side1,side2,side3);
            System.out.println(mytriangle.toString());
        }
        catch(IllegalTriangleException ex){
            System.out.println("three sides is illegal");
        }

        
    }


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

        public Triangle(double input1,double input2,double input3)throws IllegalTriangleException{

            if((input1+input2)<=input3||(input1+input3)<=input2||(input2+input3)<=input1){
                throw new IllegalTriangleException(side1,side2,side3);
            }
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
}

class IllegalTriangleException extends Exception{
    private double side1,side2,side3;

    public IllegalTriangleException(double side1,double side2,double side3){
        super("invaild three sides: " + side1 + "  "  + side2 + "  " + side3 +"/n");
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public String getSides(){
        return side1+" "+side2+" " +side3;
    }
}

    

