/* *******************
This is a program to 
reverse a passed integer.
copy and paste this function in your code.
You need to provide, the boiler plate code which
calls this function.
e.g. : 233 is returned as 332; -890  as -98.
Returns 0 for Overflow.
This  question is from leetcode.
******************** */

int reverse(int x) {

 int res=0;

 while (x!=0) {
     
     int mod = x%10;
     printf("%d\n",res);
     printf("%d\n",x);
     /* this part is to include the overflow case
     if (res>0){
       if ((INT_MAX/res) < 10)
         {
          res =0;
          break;
         }     
      }else if (res < 0){
          if ((INT_MIN/res) < 10)
         {
          res =0;
          break;
         } 
      }
    res=res*10 + mod ;
    x=x/10;
 }

 return res;
 
}
 return res;

}
 
