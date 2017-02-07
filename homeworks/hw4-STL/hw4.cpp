#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool sortMin(int i, int j) {
	return (i < j);
}

void sortLst(list<int>& src) {
	src.sort(sortMin);
}

bool lenoflst(list<int>& lst) {
	return (lst.size() > 3);
}

void viewel(int i) {
	cout << i << " " ;


}

void arrayListToArray(vector<list<int>> src, vector<int>& dst) {
	for (auto it = src.begin(); it != src.end(); ++it) {
		for (auto itt = begin(*it); itt != end(*it); ++itt) {
			dst.push_back(*itt);
		}
	}
}


bool sortByMin(list<int>& lst, list<int>& lst1) {
	list<int>::iterator it, it1;
	it = min_element(lst.begin(), lst.end());
	it1 = min_element(lst1.begin(), lst1.end());
	return (*it < *it1);
}


int transformation(vector<list<int>> src) {
	vector<list<int>> temp(src.size());
	vector<int> dst;
	vector<list<int>>::iterator it;
	it = copy_if(src.begin(), src.end(), temp.begin(), lenoflst);
	temp.resize(it - temp.begin());
	try {
		if (temp.empty())
			throw temp.empty();
	}
	catch (...) {
		cout << "No lists to transform!" << endl;
		return 0;
	}
	src.clear();
	sort(temp.begin(), temp.end(), sortByMin);
	for_each(temp.begin(), temp.end(), sortLst);
	arrayListToArray(temp, dst);
	for_each(dst.begin(), dst.end(), viewel);
	cout << endl;
	return 1;
}

int main() {
	vector<list<int>> src1 = {{1,2},{30,13,31},{4,2,1,2},{0,1,10,0},{4,5,3,6},{2,5,6}};
	vector<list<int>> src2 = { {1},{1,7,9,99,5,6,2},{5,4,-3,6,0,11},{2,3},{4,5},{-10,1,1,5},{-100,789,456} };
	vector<list<int>> src3 = { {1}, {2}, {3}, {4}, {5}, {3,2,1}, {1,5,5} };
	vector<list<int>> src4 = { {0,0,0,0}, {1,-10,-150,778},{4,4,2,1,1,0,11,5,6,-1 } ,{1,1},{3,3,4},{4,4,2,1} };
	transformation(src1);
	transformation(src2);
	transformation(src3);
	transformation(src4);
	return 2;
}


