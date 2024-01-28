/*
#include <iostream>
using namespace std;

int low{0};
int high;
int key;

int cmpfunc(const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

void binary_search(int size,int num,int arr[]) {
    high = size;
    key = num;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (arr[mid] == key) break; //return mid; 
        else if (arr[mid] > key)  high = mid - 1;      
        else  low = mid + 1;
  }
}

int main() {
    int n,card,m,cnt{0};
    int* cards;
    cin >> n;
    cards = new int[n];

    for(int i=0;i<n;i++) {
        cin >> card;
        cards[i] = card;
    }

    qsort(cards,n,sizeof(int),cmpfunc);

    for(int i=0;i<n;i++) {
        cout << cards[i] << " ";
    }
    cin >> m;
    for(int j=0;j<m;j++) {
        cin >> card;
        binary_search(n,card,cards);
        cout << "low: " << low << endl;
    }
    //     for(int i=low;i<n;i++){
    //         if(cards[i]==card) cnt++; 
    //     }
    //     cout << cnt << " ";
    //     cnt=0;
    // }
    
    // for(int i=0;i<m;i++) {
    //     cin >> card;
    //     cout << binary_search(n,card,cards);
    // }

    delete[] cards;
    return 0;
}

*/