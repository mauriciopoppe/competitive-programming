package Combinatorics;

import java.math.BigInteger;
import java.util.Scanner;

public class FindTheWays_10219 {

	/**
	 * @param args
	 */
	public static BigInteger nCk(BigInteger n, BigInteger k){
		if(k.equals("0") || k.equals(n))
			return BigInteger.ZERO;
		// symmetry
		BigInteger dif = n.subtract(k);
		if(k.compareTo(dif) > 0)
			k = dif;
		BigInteger res = BigInteger.ONE;
		BigInteger i = BigInteger.ONE;
		while(i.compareTo(k) <= 0){
			res = res.multiply(n);
			res = res.divide(i);
			n = n.subtract(BigInteger.ONE);
			i = i.add(BigInteger.ONE);
		}
		return res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			BigInteger n = new BigInteger(in.next());
			BigInteger k = new BigInteger(in.next());
			System.out.println(nCk(n, k).toString().length());
		}
		in.close();
	}

}
