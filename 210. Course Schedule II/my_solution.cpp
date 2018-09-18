/**
 * 这个就是拓扑排序，每次选出入度为0的点添加到队列里，然后依次把队列里的点pop出来
 * 每次pop出来的点，把与它相关联的边的入度-1，然后判断入度是否为0，如果是就加到队列里
 */


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree (numCourses, 0);
        vector<vector<int>> edge(numCourses);
        for (pair<int, int> p : prerequisites) {
            edge[p.second].push_back(p.first);
            ++inDegree[p.first];
        }

        queue<int> course;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                course.push(i);
            }
        }

        while (!course.empty()) {
            int c = course.front();
            course.pop();
            res.push_back(c);

            for (int co : edge[c]) {
                --inDegree[co];
                if (inDegree[co] == 0) {
                    course.push(co);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        }
        return vector<int> ();
    }
};
