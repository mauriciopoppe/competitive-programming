package Combinatorics;

import java.util.*;
import java.math.*;

public class PascalTriangleOfDeath_485 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger v[][] = new BigInteger[2][10000];
		BigInteger LIMIT = new BigInteger("10").pow(60);
		v[0][0] = v[1][0] = BigInteger.ONE;
		boolean finished = false;
		int size = 1;
		int row = 0;
		
		// first row
		System.out.println("1");		
		while(!finished){
			System.out.print("1");
			int inv = 1 - row;
			for(int i = 1; i < size; ++i){
				v[row][i] = v[inv][i - 1].add(v[inv][i]);
				if(v[row][i].compareTo(LIMIT) >= 0)
					finished = true;
				System.out.print(" " + v[row][i]);
			}
			v[row][size] = BigInteger.ONE;
			System.out.println(" 1");			
			row = 1 - row;
			++size;
		}
	}

}
