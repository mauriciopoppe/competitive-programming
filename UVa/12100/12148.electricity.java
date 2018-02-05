import java.util.Calendar;
import java.util.Scanner;
import java.util.GregorianCalendar;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);

		int m, d, y, c;
		
		Calendar old = null;
		int oldC = 0;
		while(true) {
			int n = in.nextInt();
			if (n == 0) break;
			int tc = 0, td = 0;
			while (n-- > 0) {
				d = in.nextInt();
				m = in.nextInt();
				y = in.nextInt();
				c = in.nextInt();
				if (old == null) {
					old = new GregorianCalendar(y, m - 1, d);
					oldC = c;
				} else {
					Calendar nw = new GregorianCalendar(y, m - 1, d);
					old.add((GregorianCalendar.DAY_OF_MONTH), 1);

					// System.out.println(old.getTime() + " " + nw.getTime());
					if (old.equals(nw)) {
						td += 1;
						tc += c - oldC;
					}
					old = nw;
					oldC = c;
				}
			}
			System.out.println(td + " " + tc);
		}
	}
}