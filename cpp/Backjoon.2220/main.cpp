#include <iostream>
#include <vector>
 
using namespace std;
 
void SwapArr(vector<int>& vecArr, int n1, int n2) {
  int tmp = vecArr[n1];
  vecArr[n1] = vecArr[n2];
  vecArr[n2] = tmp;
}
 
int main(void) {
  int num;
  cin >> num;
  vector<int> vecArr(num+1, 0);
  for (int i = 1; i < num; i++) {
    for(int j = i; j > 1; j /= 2){
      vecArr[j] = vecArr[j/2];
    }
    vecArr[1] = i+1;
  }
  vecArr[num] = 1;
 
  for (int i = 1; i <= num; i++)
    cout << vecArr[i] << " ";
 
  return 0;
}