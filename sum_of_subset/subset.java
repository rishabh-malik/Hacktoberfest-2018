import java.lang.*;
import java.util.Scanner;

class Subset
{
 static Boolean sumsubset(int arr[],int n,int sum)
 {if(sum>0&&n==0)
 return false;
if(sum==0)
  return true;
if(arr[n-1]>sum)
 return sumsubset(arr,n-1,sum);
 return sumsubset(arr,n-1,sum)||
 sumsubset(arr,n-1,(sum-arr[n-1]));
 }

 public static void main(String args[])
 {Scanner sc=new Scanner(System.in);
  System.out.println("Enter the size of array");
  int s=sc.nextInt();
  int ar[]=new int[s];
  System.out.println("Enter the elements of array");
  for(int i=0;i<s;i++)
   ar[i]=sc.nextInt();
   System.out.println("Enter the subset sum");
   int su=sc.nextInt();
   Boolean b=sumsubset(ar,s,su);
   if(b==true)
   System.out.println("Given sum is possible with subset");
   else
   System.out.println("Given sum is not possible with subset");
  
 }
}
