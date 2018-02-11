import java.util.*;

public class homework_5{
    public static void main(String args[]){
        System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        Course mycourse = new Course("java");
        mycourse.addStudent("cck");
        System.out.println("add cck");
        System.out.println("display the numberOfStudents: "+mycourse.getNumberOfStudents());
        mycourse.addStudent("yl");
        System.out.println("add yl");
        System.out.println("display the numberOfStudents: "+mycourse.getNumberOfStudents());
        mycourse.addStudent("hjq");
        System.out.println("add hjq");
        System.out.println("display the numberOfStudents: "+mycourse.getNumberOfStudents());
        mycourse.addStudent("klj");
        System.out.println("add klj");
        System.out.println("display the numberOfStudents: "+mycourse.getNumberOfStudents());
        
        System.out.println("display the courseName: " + mycourse.getCourseName());
        


    }

    public static class Course{
        private String courseName;
        private ArrayList<String> students = new ArrayList();
        //删去了numberOfStudents，因为ArrayList可以统计出来

        public Course(String courseName){
            this.courseName = courseName;
        }
        
        public void addStudent(String student){
            students.add(student);
        }

        public ArrayList<String> getStudents(){
            return students;
        }

        public int getNumberOfStudents(){
            return students.size();
        }

        public String getCourseName(){
            return courseName;
        }

        public void dropStudent(String student){
            students.remove(student);
        }
    }
        
}
