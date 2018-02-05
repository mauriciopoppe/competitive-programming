package Combinatorics;

import java.math.BigInteger;
import java.util.Scanner;

public class TriangleCounting_11401 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger dp[] = new BigInteger[1000001];
		dp[3] = new BigInteger("0"); 
		for(int i = 4; i <= 1000000; ++i){
			dp[i] = dp[i - 1];
			if(i % 2 != 0){
				int n = i - 3;
				n /= 2;
				BigInteger N = new BigInteger(n + "");
				BigInteger RES = N.multiply(N.add(BigInteger.ONE));
				dp[i] = dp[i].add(RES);
			}
			else{
				int n = i - 1;
				n /= 2;
				BigInteger N = new BigInteger(n + "");
				BigInteger RES = N.multiply(N.add(BigInteger.ONE));
				RES = RES.subtract(N);
				dp[i] = dp[i].add(RES);
			}
			//System.out.println(i + ". " + dp[i]);
		}
		
		while(true){
			int n = in.nextInt();
			if(n == 0) break;
			System.out.println(dp[n]);
		}
	}
}
