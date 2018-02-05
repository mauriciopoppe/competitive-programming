package FibinaryNumbers;
import java.math.*;
import java.util.*;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger fib[] = new BigInteger[105];
		fib[0] = BigInteger.ONE;
		fib[1] = new BigInteger("2");
		for (int i = 2; i < fib.length - 1; i++) {
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}
		String a, b;
		int cas = 0;
		while(in.hasNext()){
			a = in.next();
			b = in.next();
			if(cas != 0) System.out.println();
			cas = 1;
				
			//find a's in decimal
			BigInteger a_dec = BigInteger.ZERO;			
			for (int i = a.length() - 1, j = 0; i >= 0; i--, ++j) {
				if(a.charAt(i) == '1')
					a_dec = a_dec.add(fib[j]);
			}

			//find b's in decimal
			BigInteger b_dec = BigInteger.ZERO;			
			for (int i = b.length() - 1, j = 0; i >= 0; i--, ++j) {
				if(b.charAt(i) == '1')
					b_dec = b_dec.add(fib[j]);
			}
			
			BigInteger sum = a_dec.add(b_dec);
			int i = 0;
			while(fib[i].compareTo(sum) <= 0) ++i;
			
			String res = "";			
			for(int j = i - 1; j >= 0; --j){
				if(sum.compareTo(fib[j]) >= 0){
					res += "1";
					sum = sum.subtract(fib[j]);
				}
				else
					res += "0";
			}
			if(res == "")
				System.out.println("0");
			else
				System.out.println(res);
		}
	}

}
