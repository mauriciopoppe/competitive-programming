package big_integer;

import java.math.*;
import java.util.*;

public class MultipleOf17_11879 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger FIVE = new BigInteger("5");
		BigInteger SEVENTEEN = new BigInteger("17");
		
		String n;
		while(true){
			n = in.next();
			if(n.equals("0"))
				break;
			BigInteger N = new BigInteger(n);
			BigInteger LD = new BigInteger(n.charAt(n.length() - 1) + "");
			N = N.divide(new BigInteger("10"));
			N = N.subtract(LD.multiply(FIVE));
			N = N.abs();
			if(N.mod(SEVENTEEN).equals(BigInteger.ZERO))
				System.out.println("1");
			else
				System.out.println("0");				
		}
	}
}
