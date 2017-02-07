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
	cout << i << " ";

}

void viewlst(list<int> lst) {
	for_each(lst.begin(), lst.end(), viewel);
	cout << endl;
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


int main() {
	vector<list<int>> src = {{1,2},{30,13,31},{4,2,1,2},{0,1,10,0},{4,5,3,6},{2,5,6}};
	vector<list<int>> temp(src.size());
	vector<int> dst;
	copy_if(src.begin(), src.end(), temp.begin(), lenoflst);
	src.clear();
	sort(temp.begin(), temp.end() - 3, sortByMin);
	for_each(temp.begin(), temp.end(), sortLst);
	arrayListToArray(temp, dst);
	for_each(dst.begin(), dst.end(), viewel);
	return 0;
}


