## Permutation in String

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string’s permutations is the substring of the second string.

### Example 1:

```
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
```

### Example 2:

```
Input:s1= "ab" s2 = "eidboaoo"
Output: False
```

### Note:

- The input strings only contain lower case letters.
- The length of both given strings is in range [1, 10,000].

### SOLUTION:

```python
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2):
            return False

        s1_rep = [0 for _ in range(26)]
        for char in s1:
            s1_rep[ord(char)-97] += 1

        first = 0
        last = len(s1)
        s2_rep = [0 for _ in range(26)]
        for char in s2[first:last]:
            s2_rep[ord(char)-97] += 1

        if s1_rep == s2_rep:
            return True

        while last < len(s2):
            s2_rep[ord(s2[first])-97] -= 1
            s2_rep[ord(s2[last])-97] += 1

            if s1_rep == s2_rep:
                return True
            first += 1
            last += 1

        return False
```

---

> ## Resources:
>
> - [Tutorial Cup](https://www.tutorialcup.com/interview/string/check-whether-two-strings-anagram-each-other.htm)
> - [Programmer Help](https://programmer.help/blogs/week-11-leetcode-567-permutation-in-string-c-python.html)

---
