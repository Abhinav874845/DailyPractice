public class Check_palindrome
{
    public static void main(String[] args)
    {
    int a=123;
    int rev=0;
    int store=a;
    while(a>0)
    {
        int digit=a%10;
        rev=rev*10+digit;
        a=a/10;
    }
    if(rev==store)
    {
        System.out.println(" number is palidrome ");
    }
    else
        System.out.println("number is not palidrome");
    }
}
