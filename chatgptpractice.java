import java.util.*;
// question 1
class print_even_No
{
    void even()
    {
        int a=100;
        for(int i=2;i<=a;i++){
            if(i%2==0)
            {
                System.out.print(" "+i);
            }
        }
    }
}

//question 2
class Answer {
    void check(int n) {
        if (n == 0) {
            System.out.println("NUMBER IS ZERO  ");

        } else if (n > 0) {
            System.out.println("Number is positive");
        } else {
            System.out.println("Number is negative");
        }

    }

    // question 4
    //Check number is even or odd
    void check_ev(int a)
    {
        if (a%2==0)
        {
            System.out.println("Number is even ");
        }
        else {
            System.out.println("Number is odd ");
        }
    }

    //question 5

    void sum(int n)
    {
        int add=0;
        for(int i=1;i<=n;i++)
        {
             add=add+i;
        }
        System.out.print(" "+add);
    }
}

    public class chatgptpractice
    {
        public static void main(String[] args)
        {
            Scanner sc = new Scanner(System.in);
            // question 2
//            print_even_No p = new print_even_No();
//            p.even();

            // question 3
            System.out.println("Enter number: ");
            int a= sc.nextInt();
               Answer e=new Answer();
//            e.check(a);
//            e.check_ev(a);

            e.sum(a);
        }
    }
