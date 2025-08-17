#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, int finish, vector<int> cost) {
    int s = start-1; // 0-indexed
    int f = finish-1;

    if(f< s) swap(s,f);
    long long ans1 = 0, ans2 = 0;
    // from s to f;
    for(int i=s; i<f; i++) {
        ans1 += cost[i];
    }
    // from f to s;
    for(int i=f; i<s+N; i++) {
        ans2 += cost[i%N];
    }

    return min(ans1, ans2);
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    {
    	cin >> Ticket_cost[i_Ticket_cost];
    }

    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}
