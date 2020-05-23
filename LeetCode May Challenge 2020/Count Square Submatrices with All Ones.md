## Count Square Submatrices with All Ones

Given a m \* n matrix of ones and zeros, return how many square submatrices have all ones.

### Example 1:

```
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

### Example 2:

```
Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.
```

### Constraints:

- 1 <= arr.length <= 300
- 1 <= arr[0].length <= 300
- 0 <= arr[i][j] <= 1

### SOLUTION:

```python
class Solution {
public:
    int solve(vector<vector<int>>& matrix){
        //copy first col and row of matrix,because we need them.
        //start from i=j=1,
        //if(S[i][j] == 1) S[i][j] = min(S[i][j-1],S[i-1][j],S[i-1][j-1])+1;
        //else S[i][j] = 0
        //vector<int> a(n,0);
        //vector<vector<int>> S(m,a);
        int m = matrix.size();
        int n = matrix[0].size();
        int S[m][n];//array is better if size is fixed and large
        //vector<vector<int>> S;
        //S.resize(m,vector<int>(n));
        int count = 0;
        for(int i=0; i<n; i++){
            S[0][i] = matrix[0][i];
            if(matrix[0][i] == 1)
                count++;
        }
        for(int i=1; i<m; i++){//be careful start from second row
            S[i][0] = matrix[i][0];
            if(matrix[i][0] == 1)
                count++;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 1) {
                    S[i][j] = min(S[i][j-1],min(S[i-1][j],S[i-1][j-1]))+1;
                    if(S[i][j] == 1)
                        count++;
                    else
                        count+=S[i][j];//because another square matix ends at this
                }
                else
                    S[i][j] = 0;
            }
        }
        return count;
    }
    int countSquares(vector<vector<int>>& matrix) {
        //similar to max squre submatrix with 1's
        //requires another size matrix [][]
        return solve(matrix);
    }
};
/*
vector <vector<int>> v;
cin>>n>>m; //n is rows and m is columns
v.resize(n,vector<int>(m));
for(i=0;i<n;i++)      // inserts elements into the vector v
    for(j=0;j<m;j++)
        cin>>v[i][j];
*/
```

---
