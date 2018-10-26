/**
 * Class to calculate the Greatest Common Divisor and the Least Common Divisor
 * between two numbers
 * @author Mateus Tranquilino
 */
public class GCD_LCM {
	
	/**
	 * This method calculate the Greatest Common Divisor between a and b
	 * using the Euclid's Algorithm.
	 * 
	 * @param a The number a.
	 * @param b The number b.
	 * @return The GCD between a and b.
	 */
	public static int GCD(int a, int b) {
		if (b == 0) {
		return a;
		}
		return GCD(b,a%b);
	}
	
	/**
	 * This method calcul the Least Common Multiple between a and b.
	 * @param a The number a.
	 * @param b The number b.
	 * @return The LCM between a and b.
	 */
	public static int LCM(int a, int b) {
		int gcd = GCD(a,b);		
		return a * b / gcd;
	}
}
