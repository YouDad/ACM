// https://nanti.jisuanke.com/t/31719
import java.math.BigInteger;
public class Main{
    public static BigInteger bigSqrt(String s){
        BigInteger remain=BigInteger.ZERO;
        BigInteger odd=BigInteger.ZERO;
        BigInteger ans=BigInteger.ZERO;
        int group=0,k=0;
        if(s.length()%2==1){
            group=s.charAt(0)-'0';
            k--;
        }
        else{
            group=(s.charAt(0)-'0')*10+s.charAt(1)-'0';
        }
        for(int j=0;j<(s.length()+1)/2;j++){
            if(j!=0)
                group=(s.charAt(j*2+k)-'0')*10+s.charAt(j*2+k+1)-'0';
            odd=BigInteger.valueOf(20).multiply(ans).add(BigInteger.ONE);
            remain=BigInteger.valueOf(100).multiply(remain).add(BigInteger.valueOf(group));
            int count=0;
            while(remain.compareTo(odd)>=0){
                count++;
                remain=remain.subtract(odd);
                odd=odd.add(BigInteger.valueOf(2));
            }
            ans=ans.multiply(BigInteger.TEN).add(BigInteger.valueOf(count));
        }
        return ans;
        /*

            remind=0;
            odd=0;
            ans=0;
            group=0;
            k=0;
            if(s.length()%2==1)
                group=s[0]-'0',k--;
            else
                group=s[0]*10+s[1]-'0'*11;
            for(int j=0;j<(s.length()+1)/2;j++){
                if(j)
                    group=s[j*2+k]*10+s[j*2+k+1]-'0'*11;
                odd=20*ans+1;
                remind=100*remind+group;
                int count=0;
                while(remain>=odd){
                    count++;
                    remain-=odd;
                    odd+=2;
                }
                ans=ans*10+count;
            }
            return ans;

        */
    }
    public static void main(String[] args){
        try{
            java.io.FileInputStream fis=new java.io.FileInputStream("E:/ACM/SRC/1.txt");
            System.setIn(fis);
        }catch(Exception e){}
        try{
            java.io.FileInputStream fis=new java.io.FileInputStream("E:/ACM/SRC/1.txt");
            System.setIn(fis);
        }catch(Exception e){}
        java.util.Scanner cin=new java.util.Scanner(System.in);
        int t=cin.nextInt();
        for(int i=0;i<t;i++){
            BigInteger num=cin.nextBigInteger();
            BigInteger ans=num.multiply(num.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2));
            String sans=ans.toString();
            String snum=num.toString();
            BigInteger a1=bigSqrt(snum);
            BigInteger a2=bigSqrt(sans);
            int t1=a1.multiply(a1).compareTo(num)==0?2:0;
            int t2=a2.multiply(a2).compareTo(ans)==0?1:0;
            /*

                cin>>num;
                ans=num*(num-1)/2;
                a1=sqrt(num);
                a2=sqrt(ans);
                t1=(a1*a1==num)*2;
                t2=(a2*a2==num)*1;

            */
            String[] ans_str={"League of Legends","Clash Royale","Hearth Stone","Arena of Valor"};
            System.out.println(ans_str[t1+t2]);
        }
        cin.close();
    }
}