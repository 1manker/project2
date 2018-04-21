//Shan Li and Lucas Manker

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> QS(vector<T>& vec1, int lIndex, int rIndex);
template<typename T>
vector<T> QuickSort(vector<T>& vec1);
template<typename T>
void print(vector<T> vect);
template<typename T>
bool BinSearch(vector<T>& vec1, int lower, int upper, T val);
template<typename T>
void BinSearch(vector<T>& vec1, T val);

int main() {
	vector<int> one = { 4,1,3,2 };
	vector<double>two = { 3.4,5.5,55,18.1 };
	vector<char>three = { 'c','a','b','z','x','m' };
	cout << "+=+=+=+=+=+unsorted+=+=+=+=+=+" << endl;
	print(one);
	QuickSort(one);
	cout << "+=+=+=+=+=+sorted+=+=+=+=+=+" << endl;
	print(one);
	cout << "+=+=+=+=+=+unsorted+=+=+=+=+=+" << endl;
	print(two);
	QuickSort(two);
	cout << "+=+=+=+=+=+sorted+=+=+=+=+=+" << endl;
	print(two);
	cout << "+=+=+=+=+=+unsorted+=+=+=+=+=+" << endl;
	print(three);
	QuickSort(three);
	cout << "+=+=+=+=+=+sorted+=+=+=+=+=+" << endl;
	print(three);
	BinSearch(one, 4);
	BinSearch(one, 42);
	BinSearch(two, 18.1);
	BinSearch(two, 99.0);
	BinSearch(three, 'c');
	BinSearch(three, 'n');

	return 0;
}

template<typename T>
vector<T> QS(vector<T>& vec1, int lIndex, int rIndex) {
	T temp;
	int i = lIndex;
	int j = rIndex;
	T pivot = vec1[(lIndex + rIndex) / 2];

	while (i <= j) {
		while (vec1[i] < pivot) {
			i++;
		}
		while (vec1[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = vec1[i];
			vec1[i] = vec1[j];
			vec1[j] = temp;
			i++;
			j--;
		}
	}

	if (lIndex < j) {
		QS(vec1, lIndex, j);
	}
	if (i < rIndex) {

		QS(vec1, i, rIndex);
	}
	return vec1;
}
//A large portion of this code was adapted from algolist.net

template<typename T>
vector<T> QuickSort(vector<T>& vec1) {
	QS(vec1, 0, vec1.size() - 1);
	return vec1;
}

template<typename T>
bool BinSearch(vector<T>& vec1, int lower, int upper, T val) {
	if (upper < lower) {
		return false;
	}
	int mid = (lower + upper) / 2;
	if (val < vec1[mid]) {
		return BinSearch(vec1, lower, mid - 1, val);
	}
	else if (val > vec1[mid]) {
		return BinSearch(vec1, mid + 1, upper, val);
	}
	return true;
}

template<typename T>
void BinSearch(vector<T>& vec1, T val) {
	int upper = size(vec1) - 1;
	bool result = BinSearch(vec1, 0, upper, val);
	if (result) {
		cout << val << " was found!" << endl;
	}
	else{
		cout << val << " was not found!" << endl;
	}
}

template<typename T>
void print(vector<T> vect) {
	cout << endl;
	vector<T> ::iterator it;
	for (it = vect.begin(); it != vect.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	return;
}