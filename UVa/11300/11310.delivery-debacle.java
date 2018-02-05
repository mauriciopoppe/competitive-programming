package Combinatorics;

import java.math.BigInteger;
import java.util.Scanner;

public class DeliveryDebacle_11310 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger dp[][] = new BigInteger[41][2];
		// state dp[i][0] = number of combinations that end in OO
		// known answers
		dp[1][0] = BigInteger.ZERO;
		dp[1][1] = BigInteger.ONE;
		
		dp[2][0] = new BigInteger("4");
		dp[2][1] = BigInteger.ONE;
		
		dp[3][0] = new BigInteger("6");
		dp[3][1] = new BigInteger("5");
		
		BigInteger total;
		for(int i = 4; i <= 40; ++i){
			dp[i][0] = dp[i][1] = BigInteger.ZERO;
			
			// grab all the that will end in OO
			// from XX -> XX0
			//		XX -> XX0
			total = dp[i - 1][0];
			dp[i][1] = dp[i][1].add(total);			
			
			// from XX -> XX00
			//		XX -> XX00
			total = dp[i - 2][0].add(dp[i - 2][1]);
			dp[i][1] = dp[i][1].add(total);

			// remove one instance of dp[i - 2][0].add(dp[i - 2][1]) since
			// XX + OO == XXO + O
			// XX + OO == XXO + O
			//dp[i][1] = dp[i][1].subtract(dp[i - 1][1]);
			
			// grab all the that will NOT end in OO
			// from XX -> XXXX
			//		XX -> XXXX
			total = dp[i - 2][0].add(dp[i - 2][1]);
			total = total.multiply(new BigInteger(4 + ""));
			dp[i][0] = dp[i][0].add(total);
			
			// add the missing 2part piece occupying 3 cols
			total = dp[i - 3][0].add(dp[i - 3][1]);
			total = total.multiply(new BigInteger("2"));
			dp[i][0] = dp[i][0].add(total);
						
		}
			
//		for(int i = 1; i <= 40; ++i){
//			System.out.println(i + ". " + dp[i][0] + " " + dp[i][1]);
//		}
		
		int cas = in.nextInt();
		while(cas-- > 0){
			int n = in.nextInt();
			System.out.println(dp[n][0].add(dp[n][1]));
		}
	}
}