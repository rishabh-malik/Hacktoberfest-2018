import java.util.Scanner;
 
class Factorial
{
   public static void main(String args[])
   {
      int num, i=1, fact = 1;
     
      System.out.println("Enter an integer to calculate it's factorial");
      Scanner in = new Scanner(System.in);
     
      num = in.nextInt();
     
      if (n < 0)
      {
         System.out.println("Number should be non-negative.");
      }
      else
      {
         while(i<=num)
         {
            fact=fact*i;
            i++;
         }
     
         System.out.println("Factorial of "+num+" is = "+fact);
      }
   }
}