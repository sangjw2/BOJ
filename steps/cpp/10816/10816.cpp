#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL); // 없으면 시간초과
    ios::sync_with_stdio(false);


    int n,m,card,cnt{0};
    map<int, int> cards;


    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> card;
        if(cards.count(card)){
            cnt = cards[card]+1;
            cards.erase(card);
        }
        else cnt++;
        cards.insert(make_pair(card,cnt));
        cnt=0;
    }

    cin >> m;

    for(int i=0;i<m;i++) {
        cin >> card;
        if(cards.find(card)->second) cout << cards.find(card)->second << ' ';
        else cout << 0 << ' ';
    }
}   