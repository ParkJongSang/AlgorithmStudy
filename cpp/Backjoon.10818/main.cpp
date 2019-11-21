#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    int num;
    int val_min;
    int val_max;
    vector<int> v;

    cin >> N;

    for(int i = 0; i < N; i++){
        num = 0;
        cin >> num;
        v.push_back(num);
    }

    val_min = *min_element(v.begin(), v.end());
    val_max = *max_element(v.begin(), v.end());

    cout << val_min << " " << val_max << "\n";

    return 0;
}