import java.util.*;
public class print_palindrome_no
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
    int count=0;
        System.out.println("Enter how many number you want to check: ");
        int a=sc.nextInt();

        for(int i=100;i<=a;i++)
        {
            int n=i;
            int rev=0;
            int original=n;
            while(n>0)
            {
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
            if(rev==original)
            {
                System.out.print(" "+rev);
                count++;
            }
        }
        System.out.println();
        System.out.println(count);
    }
}
