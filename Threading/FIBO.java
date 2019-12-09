import java.util.Scanner;
import java.lang.Thread;

public class FIBO extends Thread{

    private int[] fibo;
    private int i;

    FIBO(int i,int[] fibo){
        this.i = i;
        this.fibo = fibo;
    }

    public void run(){
        if(this.i == 0){
            this.fibo[this.i] = 0;
        }
        else if(this.i == 1 || this.i == 2){
            this.fibo[this.i] = 1;
        }
        else{
            this.fibo[this.i] = this.fibo[this.i-1] + this.fibo[this.i-2];
        }
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = s.nextInt();
        s.close();

        try{
            int[] fibo = new int[n];
            for(int i=0;i<n;i++){
                FIBO t = new FIBO(i,fibo);
                t.start();
                t.join();
            }

            System.out.println("Fibonacci : ");
            for(int i=0;i<n;i++){
                System.out.print(fibo[i] + " ");
            }

        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}