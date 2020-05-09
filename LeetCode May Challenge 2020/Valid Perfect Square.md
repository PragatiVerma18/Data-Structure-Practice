## Valid Perfect Square

Given a positive integer `num`, write a function which returns True if `num` is a perfect square else False.

### Note: 
Do not use any built-in library function such as sqrt.

Example 1:

```
Input: 16
Output: true
```

Example 2:

```
Input: 14
Output: false
```
### SOLUTION:

```
bool isPerfectSquare(int num){
        if(num == 1)
            return true;
        int low = 2, up = num/2+1;
        while(low < up)
        {
            long mid = low + (up - low) /2;
            if(mid * mid == num)
                return true;
            if (mid * mid > num)
            {
                up = mid;
            }else{
                low = mid+1;
            }
        }
        return false;

}

```