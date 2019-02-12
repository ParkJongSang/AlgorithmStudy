#include <iostream>
#include <algorithm>

using namespace std;

int *arr = new int[3];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr+3);

    cout << arr[1] << "\n";

    return 0;
}