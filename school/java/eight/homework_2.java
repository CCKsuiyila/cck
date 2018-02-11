import java.util.*;

public class homework_2{
    public static void main(String args[]){

	    System.out.println("name:cck,number:20151681310210");
        System.out.println("welcome to java");

        Person myperson = new Person();
        System.out.println("show the infofmation of the person: "+ myperson.toString());
        Employee myemployee = new Employee();
        System.out.println("shoe the infofmation of the employee: "+myemployee.toString());
        Faculty myfaculty = new Faculty();
        System.out.println("show the infofmation of the myfaculty: "+myfaculty.toString());
        Staff mystaff = new Staff();
        System.out.println("show the infofmation of the mystaff: "+mystaff.toString());
        Student mystudent = new Student();
        System.out.println("show the infofmation of the mystudent: "+mystudent.toString());
    }
    
    public static class Person{
        private String name;
        private String address;
        private String tel;
        private String mailbox;

        public Person(){
            name = "cck";
            address = "hainan";
            tel = "15799033076";
            mailbox = "1453787167@qq.com";
        }

        //get
        public String getName(){
            return name;
        }
        public String getAddress(){
            return address;
        }
        public String getTel(){
            return tel;
        }
        public String getMailbox(){
            return mailbox;
        }

        //set
        public void setName(String giveName){
            name = giveName;
        }
        public void setAddress(String giveAddress){
            address = giveAddress;
        }
        public void setTel(String giveTel){
            tel = giveTel;
        }
        public void setMailbox(String giveMailbox){
            mailbox = giveMailbox;
        }

        public String toString(){
            return " name: "+getName()+" address: "+getAddress()+" tel: "+getTel()+" Mailbox: "+getMailbox()+"\n";
        }
    }

    public static class Student extends Person{
        private String form;
        public static final String one_form= "one_form";
        public static final String two_form= "two_form";
        public static final String three_form= "three_form";
        public static final String four_form= "four_form";

        public Student(){
            form = one_form;
        }
        public Student(String give_form){
            form = give_form;
        }

        public String getForm(){
            return form;
        }
        public void setForm(String give_form){
            form = give_form;
        }
        
        public String toString(){
            return super.toString()+" form: "+getForm()+"\n";
        }
    }
    
    public static class Employee extends Person{
        int office;
        int earnings;
        MyDate employeedTime;

        Employee(){
            office = 1;
            earnings = 5000;
            employeedTime = new MyDate();
        }
    
        //get
        public int getOffice(){
            return office;
        }
        public int getEarnings(){
            return earnings;
        }
        public MyDate getEmployeedTime(){
            return employeedTime;
        }
        //set
        public void setOffice(int giveOffice){
            office = giveOffice;
        }
        public void setEarnings(int giveEarnings){
            earnings = giveEarnings;
        }
        public void setEmployeedTime(MyDate giveEmployeedTime){
            employeedTime = giveEmployeedTime;
        }

        public String toString(){
            return super.toString()+" office: "+getOffice()+" earnings: "+getEarnings()+" employeedTime: year,month,day"+getEmployeedTime().getYear()+","+getEmployeedTime().getMonth()+","+getEmployeedTime().getDay()+"\n";
        }
    }

    public static class Faculty extends Employee{
        private String workTime;
        private String degree;

        Faculty(){
            workTime = "workday";
            degree = "one";
        }

        //get
        public String getWorkTime(){
            return workTime;
        }
        public String getDegree(){
            return degree;
        }
        //set
        public void setWorkTime(String giveWorkTime){
            workTime = giveWorkTime;
        }
        public void setDegree(String giveDegree){
            degree = giveDegree;
        }

        public String toString(){
            return super.toString()+" workTime: "+getWorkTime()+" degree: "+getDegree()+"\n";
        }
    }

    public static class Staff extends Employee{
        private String honour;

        Staff(){
            honour = "entry-level";
        }

        //get
        public String getHonour(){
            return honour;
        }
        //set
        public void setHonour(String giveHonour){
            honour = giveHonour;
        }

        public String toString(){
            return super.toString()+" honour: "+getHonour()+"\n";
        }
    }
}

class MyDate{
    private int year;
    private int month;
    private int day;

    public MyDate(){
        GregorianCalendar date = new GregorianCalendar();

        year = date.get(Calendar.YEAR);
        month = date.get(Calendar.MONTH);
        day = date.get(Calendar.DAY_OF_MONTH);
    }
    public MyDate(long elapsedTime){
        GregorianCalendar date = new GregorianCalendar();
        date.setTimeInMillis(elapsedTime);

        year = date.get(Calendar.YEAR);
        month = date.get(Calendar.MONTH);
        day = date.get(Calendar.DAY_OF_MONTH);
    }
    public MyDate(int give_year, int give_month, int give_day){
        this.year = give_year;
        this.month = give_month;
        this.day = give_day;
    }

    public int getYear(){
        return year;
    }
    public int getMonth(){
        return month;
    }
    public int getDay(){
        return day;
    }

    public void setDate(long elapsedTime){
        GregorianCalendar date = new GregorianCalendar();
        date.setTimeInMillis(elapsedTime);

        year = date.get(Calendar.YEAR);
        month = date.get(Calendar.MONTH);
        day = date.get(Calendar.DAY_OF_MONTH);
    }
}


