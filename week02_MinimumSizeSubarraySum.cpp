#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int minsubsum(vector<int> arr,int size,int s) {
	int length = size + 1,right = 0,left = 0,sum = 0;
	if (int(arr.size()) == 0)
		return 0;
	else {
		while (right < size) {
			while (sum < s && right < size) {
				sum += arr[right++];
			}
			if (sum >= s) {
				length = min(length, right - left);
				sum -= arr[left++];
			}
		}
		if (length == size +1)
			return 0;
		return length;
	}
}

int main() {
	int size,s,num;
	vector<int> arr;
	
	cin >> size >> s;
	for (int i = 0; i < size; i++) {
		cin >> num;
		arr.push_back(num);
	}

	cout << minsubsum(arr,size,s) << "+-*/" <<endl;

	system("pause");
	return 0;
}