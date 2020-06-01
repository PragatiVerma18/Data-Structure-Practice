## Course Schedule

There are a total of `numCourses` courses you have to take, labelled from `0 to numCourses-1`.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: `[0,1]`

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

### Example 1:

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
```

### Example 2:

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
```

### Constraints:

- The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
- You may assume that there are no duplicate edges in the input prerequisites.
- `1 <= numCourses <= 10^5`

### SOLUTION:

```cpp
#define MAXN 100005
#define BLACK 0
#define BLUE 1
#define GREY 2
class Solution {
public:
    vector<int> g[MAXN];
    void check(int u,int vis[MAXN],bool &f)
    {
        vis[u] =BLUE;
        for(auto v: g[u])
        {
            if(vis[v]== BLACK)
            {
                check(v,vis,f);
            }
            else if(vis[v]==BLUE)
            {
                f=false;
            }
        }
        vis[u]=GREY;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq)
    {
        bool f=true;
        int vis[MAXN] ={0};

        for(int i=0;i<numCourses;i++)
        {
            g[i].clear();
        }
        for(int i=0;i<prereq.size();i++)
        {
            g[prereq[i][1]].push_back(prereq[i][0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==BLACK)
            {
                check(i,vis,f);
                if(!f) break;
            }
        }

        return f;
    }
};
```

---
