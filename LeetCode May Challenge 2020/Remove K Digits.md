## Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

### Note:
- The length of num is less than 10002 and will be ≥ k.
- The given num does not contain any leading zero.

Example 1:
```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

Example 2:
```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```
Example 3:
```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

### SOLUTION:

```
class Solution {
public:
    string removeKdigits(string num, int k) {
		num += '0';
		if( k >= num.size()-1 )	return string("0");        
		vector<char> vec; 
		for( int i=0; i<num.size(); i++ ){
			if( vec.empty() || num[i] >= vec.back() )
				vec.push_back( num[i] );
			else{
				while( !vec.empty() && num[i] < vec.back() && k ){
					k--;
					vec.pop_back();
				}
				vec.push_back( num[i] );
			}
		}
		string ans;
		for( int i=0; i<vec.size()-1; i++ ){
			if( !ans.empty() || vec[i]!='0' )
				ans += vec[i];
		}
		return ans.empty() ? "0" : ans;
    }
};

```

### ALGORITHM:

Suppose we have a non-negative integer num that is represented as a string, we have to remove k digits from the number so that the new number is the smallest possible. So if the input is like “1432219” and k = 3, then the result will be “1219”.

To solve this, we will follow these steps −

- Define a stack st, create an empty string ret

- n := size of num

- for i in range 0 to n – 1

- while k is non zero and stack is not empty and top of stack > num[i]

- delete from the stack and decrease k by 1

- insert num[i] into st

- while k is not 0, delete element from the stack

- while the stack is not empty

- ret := ret + top of stack, delete element from stack

- now reverse the ret string

- ans := an empty string, and i := 0

- while i < size of ret and ret[i] is not ‘0’

- increase i by 1

- for i < size of ret

- ans := ans + ret[i]

- ret := ans

- return “0” if size of ret is 0, otherwise, ret

### Example (C++)
#### Let us see the following implementation to get a better understanding −

```
class Solution {
public:
   string removeKdigits(string num, int k) {
      stack st;
      string ret = "";
      int n = num.size();
      for(int i = 0; i < n; i++){
         while(k && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
         }
         st.push(num[i]);
      }
      while(k--)st.pop();
      while(!st.empty()){
         ret += st.top();
         st.pop();
      }
      reverse(ret.begin(), ret.end());
      string ans = "";
      int i = 0;
      while(i <ret.size() && ret[i] == '0')i++;
      for(; i < ret.size(); i++)ans += ret[i];
      ret = ans;
      return ret.size() == 0? "0" : ret;
   }
};
```