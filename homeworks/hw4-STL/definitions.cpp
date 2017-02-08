#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


ostream& operator<<(ostream& out, const vector<int>& lst)
{
	for (vector<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
		out << *it << " ";
	}
	return out;
}

void movetoarray(vector<int>& dst, const list<int> lst) {
	for_each(lst.begin(), lst.end(), [&](int i) {
		dst.push_back(i);
	});
}

bool sortMin(int i, int j) {
	return (i < j);
}

void sortLst(list<int>& src) {
	src.sort(sortMin);
}

bool lenoflst(list<int>& lst) {
	return (lst.size() > 3);
}


void arrayListToArray(const vector<list<int>> src, vector<int>& dst) {
	for_each(src.begin(), src.end(), [&](list<int> lst) {
		movetoarray(dst, lst);
	});
}


bool sortByMin(const list<int>& lst, const list<int>& lst1) {
	return (*min_element(lst.begin(), lst.end()) < *min_element(lst1.begin(), lst1.end()));
}
