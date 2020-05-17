## Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
```
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

Example 2:

```
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

### SOLUTION:

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty()) return {};
        vector<int> result;
        vector<int> hs(26,0);
        vector<int> hp(26,0);
        int N = s.size(), L = p.size();
        
        for(char c:p) 
            ++hp[c-'a'];
        for(int i=0; i<N; i++)
        {
            if(i>=L) 
                --hs[s[i-L]-'a'];
            ++hs[s[i]-'a'];
            if(hs==hp) 
                result.push_back(i-L+1);
        }
        return result;
    }
};
```
***
> Resources:
> - [Medium Article](https://medium.com/@ginaaiusing/leetcode-438-find-all-anagrams-in-a-string-c-bb1c8f16a27e)
> - [GitHub Code](https://github.com/wtsanshou/Coding/blob/master/DataStructure/LinearStructure/String/Anagrams/LC438FindAllAnagramsInString.md)
***