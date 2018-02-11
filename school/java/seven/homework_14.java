import java.util.*;

public class homework_14{
	public static void main(String[] args){
		
		System.out.println("name:cck, number:20151681310210");
		System.out.println("welcome to java");

        MyDate one = new MyDate();
        MyDate two = new MyDate(561555550000L);

        System.out.println("the one date's year is: " +one.getYear());
        System.out.println("the one date's month is: " +one.getMonth());
        System.out.println("the one date's day is: " +one.getDay());

        long totalMilliseconds = System.currentTimeMillis();
        long totalSeconds = totalMilliseconds/1000;
        long currentSecond = totalSeconds%60;
        long totalMinutes = totalSeconds/60;
        long currentMinute = totalMinutes%60;
        long totalHours = totalMilliseconds/60;
        long currentHour = totalHours%24;
        System.out.println("current time is "+currentHour + ":"+currentMinute +":" + currentSecond + "GMT");

        System.out.println("the two date's year is: " +two.getYear());
        System.out.println("the two date's month is: " +two.getMonth());
        System.out.println("the two date's day is: " +two.getDay());
        long totalMillisecondstwo = 561555550000L;
        long totalSecondstwo = totalMillisecondstwo/1000;
        long currentSecondtwo = totalSecondstwo%60;
        long totalMinutestwo = totalSecondstwo/60;
        long currentMinutetwo = totalMinutestwo%60;
        long totalHourstwo = totalMillisecondstwo/60;
        long currentHourtwo = totalHourstwo%24;
        System.out.println("current time is "+currentHourtwo + ":"+currentMinutetwo +":" + currentSecondtwo + "GMT");

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


