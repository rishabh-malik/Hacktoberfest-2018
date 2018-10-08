public class Fibonacci {

    public static void main(String[] args) {

        int num = 10, n1 = 0, n2 = 1;
        System.out.print("First " + num + " terms: ");

        for (int i = 1; i <= num; ++i)
        {
            System.out.print(n1 + " + ");

            int sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }
    }
}