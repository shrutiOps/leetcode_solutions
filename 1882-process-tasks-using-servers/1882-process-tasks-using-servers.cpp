class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> res(m);
        using pii = pair<int, int>;
        using piii = pair<long long, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> avail;
        priority_queue<piii, vector<piii>, greater<piii>> used;

        for(int i = 0; i < n; i++) {
            avail.push({servers[i], i});
        }
        long long time = 0;
        for(int i = 0; i < m; i++) {
            time = max(time, (long long)i);
            while(!used.empty() && used.top().first <= time) {
                auto curr = used.top();
                used.pop();

                int wt = curr.second.first;
                int serverId = curr.second.second;

                avail.push({wt, serverId});
            }
            if(avail.empty()) {
                auto curr = used.top();
                used.pop();
                time = max(time, curr.first);

                int wt = curr.second.first;
                int serverId = curr.second.second;

                avail.push({wt, serverId});
            }
            auto [wt, serverId] = avail.top();
            avail.pop();
            res[i] = serverId;
            used.push({time + tasks[i], {wt, serverId}});
        }

        return res;
    }
};