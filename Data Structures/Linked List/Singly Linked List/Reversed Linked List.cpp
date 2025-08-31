#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second

template<typename T>
void inputVec(vector<T> &v, int n) {
    v.resize(n);
    for (auto &x : v) cin >> x;
}
#define initv(v, n, T) vector<T> v; inputVec(v, n);

using pii = pair<int,int>;
using pli = pair<ll,int>;
const int MOD = 1e9 + 7;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;

struct Node {
    int val;
    Node* next;
    Node(int v=0): val(v), next(nullptr) {}
};

Node* reverseEven(Node* head, Node* nextOdd) {
    Node* prev = nextOdd;
    Node* curr = head;
    while(curr != nextOdd) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev; 
}

Node* restoreOriginal(Node* head) {
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    Node* curr = head;

    while(curr) {
        if(curr->val % 2 == 0) {
            Node* subHead = curr;

            while(curr && curr->val % 2 == 0) curr = curr->next;
            Node* nextOdd = curr;

            Node* newHead = reverseEven(subHead, nextOdd);
            prev->next = newHead;
            prev = subHead; 
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}

void solve() {
    int n;
    cin>>n;

    Node *head = nullptr, *temp = nullptr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        Node* node = new Node(x);
        if(!head) head = temp = node;
        else {
            temp->next = node;
            temp = node;
        }
    }

    Node* restored = restoreOriginal(head);

    Node* t = restored;
    while(t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
