package big_integer;

import java.math.BigDecimal;
import java.util.Scanner;

public class HighPrecisionNumber_11821 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int cas = in.nextInt();
		String n;
		while(cas-- > 0){
			BigDecimal sum = new BigDecimal("0.0");
			while(true){
				n = in.next();
				if(n.equals("0")) break;
				sum = sum.add(new BigDecimal(n));
			}
			n = sum.toString();
			StringBuffer sb = new StringBuffer(n);
			int index = n.length() - 1;
			while(true){
				if(n.charAt(index) != '0')
					break;
				sb.deleteCharAt(index);
				index--;
			}
			if(sb.charAt(index) == '.')
				sb.deleteCharAt(index);
			System.out.println(sb.toString());
		}
	}

}
