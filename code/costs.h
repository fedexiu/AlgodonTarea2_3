#ifndef COSTS_H
#define COSTS_H
#include <bits/stdc++.h>

using namespace std;

extern int insert_table[26];
extern int delete_table[26];
extern int replace_table[26][26];
extern int transpose_table[26][26];

int costo_sub(char a, char b);

int costo_ins(char a);

int costo_del(char a);

int costo_trans(char a, char b);

void set_sub();

void set_ins();

void set_del();

void set_trans();

void set_tables();



#endif