class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& edge) {
        vector<int> course[numCourses], ind(numCourses);
        queue<int> q;

        for (size_t i = 0; i < edge.size(); i++) {
            course[edge[i][1]].emplace_back(edge[i][0]);
            ind[edge[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push(i);
        }

        while (q.size()) {
            int keep = q.front();
            q.pop();
            for (auto k : course[keep]) {
                ind[k]--;
                if (ind[k] == 0) q.push(k);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (ind[i] > 0) return false;
        }

        return true;
    }
};
