## Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

### Note:
You may assume that all inputs are consist of lowercase letters a-z.

### Analysis:
This is a classic problem related to data structure Trie. Trie is an important data structure which is very efficient for searching.

Typically, the Trie is an n-nodes tree structure, where each node has two fields:
(1) int value; //Briefly understanding, this value is to check weather this node is a word end or not.
(2) TrieNode* children[size_of_alphabet]; //This saves the tree structure.

Figure (coming from wikipedia) below shows a Trie, given keys "A", "to", "tea", "ted", "ten", "i", "in", and "inn".:

![Figure](http://upload.wikimedia.org/wikipedia/commons/thumb/b/be/Trie_example.svg/250px-Trie_example.svg.png)

The general idea of building a Trie given a set of keys(strings) is as following:
1.  Get string S.
2.  Set pointer P as the root.
3.  Start from the 1st char C in S,
         if C does not exist in the children of current node P:
                 add a new node C to P
4.  Set P = P.C, goto step 3.
5. Set a value to the last char node (indicate this node is not only a prefix but a word).          


Some basic operations of Trie (only for this problem):
1. Insert String:
      Step 1: set pointer p as the root node
      Step 2: Start from the 1st char in the string, get the char, check if exist in p's children.
      Step 3: if not exist, create a new children for p,
      Step 4: set p = p->children[ current char], continue search until meets the string end.
      Step 5: set p->value to 1; (in this problem set to a constant is enough)  

2. Search String is pretty much similar to the insert operation. Only differences are (1) If no children exists, return false. (2) When meets the end of string, check the value of last node, to see if this is the word end, or just a prefix key.

3. Startwith is very similar to search, but no need to check the value of the node.


### Code(C++) SOLUTION:

```cpp
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        value = 0;
        for (int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
    int value;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        int len = s.size();
        for (int i=0;i<len;i++){
            int idx = s[i] - 'a';
            if (! p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p = p->children[idx];
        }
        count++;
        p->value = count;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        int len = key.size();
        for (int i=0;i<len;i++){
            int idx = key[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
        if (p->value!=0){
            return true;
        }else{
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        int len = prefix.size();
        for (int i=0;i<len;i++){
            int idx = prefix[i] - 'a';
            if (p->children[idx]){
                p = p->children[idx];
            }else{
                return false;
            }
        }
      return true;
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
```


### Code(Python):
```python
class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.value = 0
        self.children = [None] * 26
        

class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        p = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not p.children[idx]:
                p.children[idx] = TrieNode()
            p = p.children[idx]
        p.value = 1;
                

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        p = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not p.children[idx]:
                return False
            p = p.children[idx]
        if p.value != 0:
            return True
        else:
            return False
                

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        p = self.root
        for ch in prefix:
            idx = ord(ch) - ord('a')
            if not p.children[idx]:
                return False
            p = p.children[idx]
        return True
       

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")

```

***