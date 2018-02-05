package Combinatorics;

import java.math.BigInteger;
import java.util.Scanner;

public class AGraphProblem_11069 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger dp[][] = new BigInteger[77][2];
		
		// empty the matrix
		for(int i = 0; i <= 76; ++i){
			dp[i][0] = dp[i][1] = BigInteger.ZERO;
		}

		// init dp
		dp[1][0] = BigInteger.ZERO;
		dp[1][1] = BigInteger.ONE;
		for(int i = 2; i <= 76; ++i){
			// take this number
			if(i - 2 >= 1)
				dp[i][1] = dp[i][1].add(dp[i - 2][1]);
			if(i - 3 >= 1)
				dp[i][1] = dp[i][1].add(dp[i - 3][1]);
			if(dp[i][1].equals(BigInteger.ZERO))
				dp[i][1] = BigInteger.ONE;
			// don't take this number
			dp[i][0] = dp[i - 1][1];
			//System.out.println(i + ". " + dp[i][1] + " " + dp[i][0]);
		}

		while(in.hasNextInt()){
			int n = in.nextInt();
			if(n == 1){ System.out.println("1"); continue;}
			BigInteger res = dp[n][0].add(dp[n][1]);
			System.out.println(res);
		}
		in.close();
	}

}
