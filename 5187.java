////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-19 16:16:23
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 5187
////Problem Title: 
////Run result: Accept
////Run time:499MS
////Run memory:9640KB
//////////////////System Comment End//////////////////
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		BigInteger n,p,ans;
		BigInteger two = new BigInteger("2");
		while(in.hasNext()){
			n = in.nextBigInteger();
			p = in.nextBigInteger();
			ans = Q_pow(two,n,p).add(p).subtract(two).mod(p);
			System.out.println(ans);
		}
		in.close();
	}
	static BigInteger Q_pow(BigInteger x,BigInteger y,BigInteger p){
		BigInteger two = new BigInteger("2");
		BigInteger res = new BigInteger("1");
		BigInteger zero = BigInteger.ZERO;
		while(y.compareTo(zero) > 0){
			if(y.mod(two).compareTo(zero) != 0){
				res = res.multiply(x).mod(p);
			}
			x = x.multiply(x).mod(p);
			y = y.divide(two);
		}
		return res;
	}
}
