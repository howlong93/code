class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int, bool> find;
        queue<int> q;

        find[0] = true;
        for (auto k : rooms[0]) q.push(k);
        while (q.size()) {
            int k = q.front();
            q.pop();
            if (!find[k]) {
                find[k] = true;
                for (auto m : rooms[k]) q.push(m);
            }
        }

        bool flag = true;
        for (size_t i = 0; i < rooms.size(); i++)
            if (!find[i]) {
                flag = false;
                break;
            }

        return flag;
    }
};
