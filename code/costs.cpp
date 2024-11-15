#include <bits/stdc++.h>
#include "costs.h"

using namespace std;


int insert_table[26];
int delete_table[26];
int replace_table[26][26];
int transpose_table[26][26];

void set_ins(){
    ifstream insertfile("costs/cost_insert.txt");
    for(int j = 0; j<26; ++j){
        insertfile>>insert_table[j];
    }
}

void set_sub(){
    ifstream replacefile("costs/cost_replace.txt");
    for(int i = 0; i<26; ++i){
        for(int j = 0; j<26; ++j){
            replacefile>>replace_table[i][j];
        }
    }
}

void set_del(){
    ifstream deletefile("costs/cost_delete.txt");
    for(int j = 0; j<26; ++j){
        deletefile>>delete_table[j];
    }
}

void set_trans(){
    ifstream transposefile("costs/cost_transpose.txt");
    for(int i = 0; i<26; ++i){
        for(int j = 0; j<26; ++j){
            transposefile>>transpose_table[i][j];
        }
    }
}

void set_tables(){
    set_del();
    set_ins();
    set_sub();
    set_trans();
    cout<<"Tablas creadas"<<"\n";
}