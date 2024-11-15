#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H
#include <bits/stdc++.h>

using namespace std;


int editdistancebf(vector<char> s, int n, vector<char> t, int m);
int editdistancedp(vector<char> s, int n, vector<char> t, int m);

#endif