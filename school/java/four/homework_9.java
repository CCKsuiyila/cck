
public class homework_9{
	public static void main(String [] args){
		System.out.println("name:cck,number:20151681310210");
		System.out.println("welcome to java");
		
		double foot = 1.0;
		double meter = 20.0;
		System.out.println("foot    meter   foot    meter");
		while(foot<11.0){
			System.out.printf("%4.1f    %5.3f   %4.1f    %7.3f",foot,footToMeter(foot),meter,meterToFoot(meter));
			System.out.println();
			foot += 1.0;
			meter += 5.0;
		}
	}
	public static double footToMeter(double foot){
		return foot*0.305;
	}
	public static double meterToFoot(double meter){
		return meter*3.279;
	}
}