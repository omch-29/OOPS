#include<bits/stdc++.h>
using namespace std;

class SlidingWindowLimiter{
    unordered_map<string, deque<int>>store;
    int limit;
    int windowSize;
public:
    SlidingWindowLimiter(int l, int ws){
        this->limit=l;
        this->windowSize=ws;
    }
    bool allowRequest(string userId){
        int now=time(0);
        auto &dq = store[userId];
        // auto it = store.find(userId);
        // if (it == store.end()){
        //     store[userId] = deque<int>();
        // }
        while(!dq.empty() && now-dq.front()>=windowSize) dq.pop_front();
        if(dq.size()>=limit) return false;
        dq.push_back(now);
        return true;
    }
};

int main() {
    SlidingWindowLimiter limiter(100, 60); // 100 req/min

    string user = "user1";

    for (int i = 1; i <= 105; i++) {
        if (limiter.allowRequest(user)) {
            cout << "Request " << i << " allowed\n";
        } else {
            cout << "Request " << i << " BLOCKED\n";
        }
    }

    return 0;
}
