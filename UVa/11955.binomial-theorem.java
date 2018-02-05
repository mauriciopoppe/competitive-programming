package Combinatorics;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class BinomialTheorem_11955 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger v[][] = new BigInteger[103][10000];
		v[1][0] = BigInteger.ONE;
		for(int i = 2; i <= 102; ++i){
			for(int j = 1; j < i - 1; ++j)
				v[i][j] = v[i - 1][j - 1].add(v[i - 1][j]);
			v[i][i - 1] = v[i][0] = BigInteger.ONE;
		}
			
		int cas = in.nextInt();
		for (int z = 0; z < cas; z++) {
			String s = in.next();
			String semi_parsed = "";
			for(int i = 0; i < s.length(); ++i)
				if(Character.isLetterOrDigit(s.charAt(i)))
					semi_parsed += s.charAt(i);
				else
					semi_parsed += " ";
			String[] parsed = semi_parsed.split("\\s+");
			int row = Integer.parseInt(parsed[3]);
			System.out.printf("Case %d: ", z + 1);
			for(int i = row, j = 0; i >= 0; --i, ++j){
				if(j != 0) System.out.print("+");
					
				ArrayList<String> bc = new ArrayList<String>();
				
				// binomial term
				if(!v[row + 1][j].equals(BigInteger.ONE))
					bc.add(v[row + 1][j].toString());
				
				if(i > 0){
					String to_add = parsed[1];
					if(i > 1)
						to_add += "^" + i;
					bc.add(to_add);
				}
				
				if(j > 0){
					String to_add = parsed[2];
					if(j > 1)
						to_add += "^" + j;
					bc.add(to_add);
				}
				
				String to_print = "";
				for(int k = 0; k < bc.size(); ++k){
					if(k != 0) to_print += "*";
					to_print += bc.get(k);
				}
				System.out.print(to_print);
			}
			System.out.println();
		}
		in.close();
	}

}
