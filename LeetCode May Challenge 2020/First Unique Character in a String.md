## First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

### Note: 
You may assume the string contain only lowercase letters.

### SOLUTION: 

```
int *getCharCountArray(char *str) 
{ 
   int *count = (int *)calloc(sizeof(int), 256); 
   int i; 
   for (i = 0; *(str+i);  i++) 
      count[*(str+i)]++; 
   return count; 
}

int firstUniqChar(char * str){
  int *count = getCharCountArray(str); 
  int index = -1, i; 
  
  for (i = 0; *(str+i);  i++) 
  { 
    if (count[*(str+i)] == 1) 
    { 
      index = i; 
      break; 
    }    
  }   
    
  free(count); // To avoid memory leak 
  return index; 
}

```