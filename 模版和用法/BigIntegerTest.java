import java.math.BigInteger;
import java.util.Scanner;
public class BigIntegerTest {
    static Scanner cin = new Scanner(System.in);
    public static void main(String[] args) {
        int T=cin.nextInt();
        while(T-->0)
        {
            BigInteger a=cin.nextBigInteger();
            BigInteger b=cin.nextBigInteger();
            BigInteger c=cin.nextBigInteger();
            BigInteger d=cin.nextBigInteger();
            System.out.println(a.add(b).add(c).add(d));
        }
    }
    //读入方法：nextBigInteger()
	public void test5() {
		Scanner scan = new Scanner(System.in);				// 读入
		int n = scan.nextInt(); 							// 读入一个int;
		BigInteger m = scan.nextBigInteger();				// 读入一个BigInteger;
		while(scan.hasNext()){	
			System.out.print("scan.hasNext()=" + scan.hasNext());
		}
        scan.close();										// 关闭
	}

    //进制转换
	public void testScale() {
		//在构造将函数时，把radix进制的字符串转化为BigInteger
		String str = "1011100111";
		int radix = 2;
		BigInteger interNum1 = new BigInteger(str,radix);	//743
 
		//我们通常不写，则是默认成10进制转换，如下：
		BigInteger interNum2 = new BigInteger(str);			//1011100111
	}
 
    //基本运算:add(),subtract(),multiply(),divide(),mod(),remainder(),pow(),abs(),negate()
	public void testBasic() {
		BigInteger a = new BigInteger("13");
		BigInteger b = new BigInteger("4");
		int n = 3;
 
		//1.加
		BigInteger bigNum1 = a.add(b);			//17
		//2.减
		BigInteger bigNum2 = a.subtract(b);		//9
		//3.乘
		BigInteger bigNum3 = a.multiply(b);		//52
		//4.除
		BigInteger bigNum4 = a.divide(b);		//3
		//5.取模(需 b > 0，否则出现异常：ArithmeticException("BigInjavateger: modulus not positive"))
		BigInteger bigNum5 = a.mod(b);			//1
		//6.求余
		BigInteger bigNum6 = a.remainder(b);	//1
		//7.平方(需 n >= 0，否则出现异常：ArithmeticException("Negative exponent"))
		BigInteger bigNum7 = a.pow(n);			//2197
		//8.取绝对值
		BigInteger bigNum8 = a.abs();			//13
		//9.取相反数
		BigInteger bigNum9 = a.negate();		//-13
	}
    
    // mod()和remainder()
    public void test02(){
        BigInteger bigNum01 = new BigInteger("-11");
        BigInteger bigNum02 = new BigInteger("3");
 
        BigInteger result01 = bigNum01.remainder(bigNum02);  //-2
        System.out.println(result01);
 
        BigInteger result02 = bigNum01.mod(bigNum02);  //1
        System.out.println(result02);
       
    }

    //比较大小:compareTo(),max(),min()
	public void testCompare() {
		BigInteger bigNum1 = new BigInteger("52");
		BigInteger bigNum2 = new BigInteger("27");
 
		//1.compareTo()：返回一个int型数据（1 大于； 0 等于； -1 小于）
		int num = bigNum1.compareTo(bigNum2);			//1
 
		//2.max()：直接返回大的那个数，类型为BigInteger
		//	原理：return (compareTo(val) > 0 ? this : val);
		BigInteger compareMax = bigNum1.max(bigNum2);	//52
 
		//3.min()：直接返回小的那个数，类型为BigInteger
		//	原理：return (compareTo(val) < 0 ? this : val);
		BigInteger compareMin = bigNum1.min(bigNum2);	//27
	}
    
    //类型转换(返回类型如下)
	public void testToAnother() {
		BigInteger bigNum = new BigInteger("52");
		int radix = 2;
		
		//1.转换为bigNum的二进制补码形式
		byte[] num1 = bigNum.toByteArray();
		//2.转换为bigNum的十进制字符串形式
		String num2 = bigNum.toString();		//52
		//3.转换为bigNum的radix进制字符串形式
		String num3 = bigNum.toString(radix);	//110100
		//4.将bigNum转换为int
		int num4 = bigNum.intValue();
		//5.将bigNum转换为long
		long num5 = bigNum.longValue();
		//6.将bigNum转换为float
		float num6 = bigNum.floatValue();
		//7.将bigNum转换为double
		double num7 = bigNum.doubleValue();
	}

    //二进制运算(返回类型都为BigInteger，不常用，但有备无患)
	public void testBinaryOperation() {
		BigInteger a = new BigInteger("13");
		BigInteger b = new BigInteger("2");
		int n = 1;
 
		//1.与：a&b
		BigInteger bigNum1 = a.and(b);			//0
		//2.或：a|b
		BigInteger bigNum2 = a.or(b);			//15
		//3.异或：a^b
		BigInteger bigNum3 = a.xor(b);			//15
		//4.取反：~a
		BigInteger bigNum4 = a.not();			//-14
		//5.左移n位： (a << n)
		BigInteger bigNum5 = a.shiftLeft(n);	//26
		//6.右移n位： (a >> n)
		BigInteger bigNum6 = a.shiftRight(n);	//6
	}
    
}
