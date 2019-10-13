import java.util.Scanner;
class Lcs
{static int lcs(int arr[],int n)
 {int lcs1[]=new int[n];
  int max=0;
  for(int i=0;i<n;i++)
  lcs1[i]=1;
  for(int i=1;i<n;i++)
   {for(int j=0;j<i;j++)
    {if(arr[i]>arr[j])
	 lcs1[i]=Math.max(lcs1[i],(lcs1[j]+1));
	}
   }
  for(int i=0;i<n;i++)
  {if(lcs1[i]>max)
   max=lcs1[i];
  }
  return max;
 }
 public static void main(String args[])
 {Scanner sc=new Scanner(System.in);
  System.out.println("enter the size of array");
  int s=sc.nextInt();
  int arr1[]=new int[s];
  System.out.println("enter the array");
  for(int i=0;i<s;i++)
   arr1[i]=sc.nextInt();
  int lcs2=lcs(arr1,s);
  System.out.println("size of the biggest incresing lcs is: "+lcs2);
  
 }
}
