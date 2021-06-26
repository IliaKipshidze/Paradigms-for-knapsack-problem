
//                              სრული გადარჩევა (exhaustive seacrh, brute-force)

/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N; 
	cout << "n = ";
	cin >> N;
	int capacity;
	cout << "capacity: ";
	cin >> capacity;
	pair<int, int>* data = new pair<int, int>[N]; 
	for (int i = 0; i < N; i++) {
		cout << "W(" << i+1 << ") = ";
		cin >> data[i].first;
		cout << "V(" << i+1 << ") = ";
		cin >> data[i].second;
	}
	int M = int(pow(2, N));
	int** table = new int* [M];
	for (int i = 0; i < M; i++) {
		table[i] = new int[N];
	}
	for (int j = 0; j < N; j++) {
		int i = 0;
		while (i < M) {
			for (int k = 0; k < pow(2, j); k++) {
				table[i][j] = 0;
				i++;
			}
			for (int k = 0; k < pow(2, j); k++) {
				table[i][j] = 1;
				i++;
			}
		}
	}
	int maxValue = 0; 
	int weight=0; 
	int value=0; 
	int optimal=-1; 
	int maxWeight; 
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == 1) {
				weight += data[j].first;
				value += data[j].second;
			}
		}
		if ((value > maxValue) && (weight <= capacity)) {
			maxValue = value; optimal = i; maxWeight = weight;
		}
		weight = 0;
		value = 0;
	}
	if (optimal != -1) {
		cout << "items: ";
		for (int j = 0; j < N; j++) {
			if (table[optimal][j] == 1)cout << j + 1 << "  ";
		}    
		cout << endl;
		cout << "total weight = " << maxWeight << "\ntotal value = " << maxValue << endl;
	}
	else cout << "optimal subset does not exist" << endl;
}*/

                            //       აღმავალი დინამიკური პროგრამირება (bottom-up)

//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//int max(int a, int b) {
//	if (b > a)return b;
//	return a;
//}
//
//int main() {
//	int N; 
//	cout << "n = ";
//	cin >> N;
//	int capacity; 
//	cout << "capacity: ";
//	cin >> capacity;
//	pair<int, int>* data = new pair<int, int>[N]; 
//	for (int i = 0; i < N; i++) {
//		cout << "W(" << i + 1 << ") = ";
//		cin >> data[i].first;
//		cout << "V(" << i + 1 << ") = ";
//		cin >> data[i].second;
//	}
//	int** table = new int* [N + 1];
//	for (int i = 0; i < N + 1; i++) {
//		table[i] = new int[capacity + 1];
//	}
//	for (int i = 0; i < N + 1; i++) {
//		table[i][0] = 0;
//	}
//	for (int i = 0; i < capacity + 1; i++) {
//		table[0][i] = 0;
//	}
//	for (int i = 1; i < N + 1; i++) {
//		for (int j = 1; j < capacity + 1; j++) {
//			if (j - data[i - 1].first < 0)table[i][j] = table[i - 1][j];
//			else table[i][j] = max(table[i - 1][j], data[i - 1].second + table[i - 1][j - data[i - 1].first]);
//		}
//	}
//	int totalValue = table[N][capacity];
//	if (totalValue > 0) {
//		cout << "items: ";
//		int j = capacity;
//		int weight = 0;
//		for (int i = N; i > 0; i--) {
//			if (table[i][j] != table[i - 1][j]) {
//				cout << i << "  ";
//				weight += data[i - 1].first;
//				j -= data[i - 1].first;
//			}
//		}
//		cout << endl << "total weight = " << weight << "\ntotal value = " << totalValue;
//	}
//	else cout << "there is not any item" << endl;
//	cout << endl << "         table:" << endl;
//	for (int i = 0; i <= N; i++) {
//		for (int k = 0; k <= capacity; k++) {
//			cout << setw(10)<<table[i][k];
//		}
//		cout << endl;
//	}
//}

                 //  ხარბი ალგორითმი, უწყვეტი ამოცანისთვის (greedy algorithm for fractional knapsack problem)

/*#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N; 
	cout << "n = ";
	cin >> N;
	double capacity; 
	cout << "capacity: ";
	cin >> capacity;
	pair<double, double>* data = new pair<double, double>[N]; 
	for (int i = 0; i < N; i++) {
		cout << "W(" << i + 1 << ") = ";
		cin >> data[i].first;
		cout << "V(" << i + 1 << ") = ";
		cin >> data[i].second;
	}
	pair<double, int>* mass = new pair<double, int>[N];
	for (int i = 0; i < N; i++) {
		mass[i].first = data[i].second / data[i].first;
		mass[i].second = i;
	}
	sort(mass, mass + N, [](pair<double, int>& a, pair<double, int>& b) {return a.first > b.first; });
	double value = 0;
	double weight = 0;
	double freeSpace = capacity;
	cout << "items: " << endl;
	for (int i = 0; i < N; i++) {
		if (data[mass[i].second].first <= freeSpace) {
			cout << mass[i].second + 1 << " - " << data[mass[i].second].first << " kg" << endl;
			weight += data[mass[i].second].first;
			value += data[mass[i].second].second;
			freeSpace -= data[mass[i].second].first;
		}
		else if (freeSpace > 0) {
			cout << mass[i].second + 1 << " - " << freeSpace << " kg" << endl;
			weight += freeSpace;
			value += (data[mass[i].second].second * freeSpace) / data[mass[i].second].first;
			break;
		}
		else break;
	}
	cout << "\ntotal weight = " << weight << "\ntotal value = " << value << endl;
}*/

                               //     დაღმავალი დინამიკური პროგრამირება (top-down)

//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int max(int a, int b) {
//	if (b > a)return b;
//	return a;
//}
//
//int knapsack(int** table, pair<int, int>* data, int i, int j) {
//	if (i == 0)return 0;
//	if (j < data[i - 1].first) {
//		if (table[i-1][j] == -1)table[i][j] = knapsack(table, data, i - 1, j);
//		else table[i][j] = table[i - 1][j];
//	}
//	else {
//		int max1, max2;
//		if (table[i - 1][j] == -1)max1 = knapsack(table, data, i - 1, j);
//		else max1 = table[i - 1][j];
//		if (table[i - 1][j - data[i - 1].first] == -1)max2 = data[i - 1].second + knapsack(table, data, i - 1, j - data[i - 1].first);
//		else max2 = data[i - 1].second + table[i - 1][j - data[i - 1].first];
//		table[i][j] = max(max1, max2);
//	}
//}
//
//int main() {
//	int N; 
//	cout << "n = ";
//	cin >> N;
//	int capacity; 
//	cout << "capacity: ";
//	cin >> capacity;
//	pair<int, int>* data = new pair<int, int>[N]; 
//	for (int i = 0; i < N; i++) {
//		cout << "W(" << i + 1 << ") = ";
//		cin >> data[i].first;
//		cout << "V(" << i + 1 << ") = ";
//		cin >> data[i].second;
//	}
//	int** table = new int* [N + 1];
//	for (int i = 0; i < N + 1; i++) {
//		table[i] = new int[capacity + 1];
//	}
//	for (int i = 0; i < N + 1; i++) {
//		table[i][0] = 0;
//	}
//	for (int i = 0; i < capacity + 1; i++) {
//		table[0][i] = 0;
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= capacity; j++) {
//			table[i][j]=-1;
//		}
//	}
//	knapsack(table, data, N, capacity);
//	int totalValue = table[N][capacity];
//	if (totalValue > 0) {
//		cout << "items: ";
//		int j = capacity;
//		int weight = 0;
//		for (int i = N; i > 0; i--) {
//			if (table[i][j] != table[i - 1][j]) {
//				cout << i << "  ";
//				weight += data[i - 1].first;
//				j -= data[i - 1].first;
//			}
//		}
//		cout << endl << "total weight = " << weight << "\ntotal value = " << totalValue;
//	}
//	else cout << "there is not any item" << endl;
//	cout << endl << "         table:" << endl;
//	for (int i = 0; i <= N; i++) {
//		for (int k = 0; k <= capacity; k++) {
//			cout << setw(10)<<table[i][k];
//		}
//		cout << endl;
//	}
//}

                     //         შტოების და საზღვრების მეთოდით (branch-and-bound)

/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double weight;
double value;
double capacity;
int N;
void knapsack(pair<double, double>*data, pair<double, int>* ratio, int i, vector<int>&output) {
	if (i == N) {
		return;
	}
	double leftUB = value + data[ratio[i].second].second + (capacity - (weight + data[ratio[i].second].first)) * (ratio[i + 1].first);
	double rightUB = value + (capacity - weight) * (ratio[i + 1].first);
	if ((leftUB >= rightUB) && (weight + data[ratio[i].second].first) <= capacity) {
		weight += data[ratio[i].second].first;
		value += data[ratio[i].second].second;
		output.push_back(ratio[i].second);
	}
	knapsack(data, ratio, i + 1, output);
}

int main() {
	cout << "n = ";
	cin >> N;
	cout << "capacity: ";
	cin >> capacity;
	pair<double, double>* data = new pair<double, double>[N]; 
	for (int i = 0; i < N; i++) {
		cout << "W(" << i + 1 << ") = ";
		cin >> data[i].first;
		cout << "V(" << i + 1 << ") = ";
		cin >> data[i].second;
	}
	pair<double, int>* ratio = new pair<double, int>[N];
	for (int i = 0; i < N; i++) {
		ratio[i].first = data[i].second / data[i].first;
		ratio[i].second = i;
	}
	sort(ratio, ratio + N, [](pair<double, int>& a, pair<double, int>& b) {return a.first > b.first; });
	weight = 0;
	value = 0;
	vector<int> result;
	knapsack(data, ratio, 0, result);
	if (result.size() != 0) {
		cout << "items: ";
		for (size_t i = 0; i < result.size(); i++) {
			cout << result[i] + 1 << "  ";
		}
		cout << endl;
	}
	cout << "total weight: " << weight << endl << "total value: " << value << endl;
}*/
