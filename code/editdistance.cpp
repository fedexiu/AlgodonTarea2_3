#include <bits/stdc++.h>
#include "costs.h"

using namespace std;


/*Entrada: dos palabras s y t de largo n y m
 *Salida: distancia minima de edicion 
 *Primero con costos constantes (1)

 *Operaciones
 *Sustitucion: Reemplaza un caracter i por otro
 *Inserción: Inserta un caracter en algun lugar
 *Borrado: Borra un caracter de s
 *Transposicion: Transpone dos caracteres consecutivos
*/

int editdistancebf(vector<char> s, int n, vector<char> t, int m){
    
    if(m == 0) return n;
    else if(n == 0) return m;
    
    int result1, result2, result3, result4;
    
    if(n>0 && m>0)  result1 = editdistancebf(s, n-1, t, m-1) + 2*(s[n-1]!=t[m-1]);//result 1 guarda lo que de el algoritmo en el caso de sustitución sus ultimos caracteres son diferentes
    
    if (m>0 ) result2 = editdistancebf(s,n,t,m-1) + 1; //result2 guarda el resultado en el caso de insertar un elemento al final de s 
    
    if (n>0) result3 = editdistancebf(s,n-1,t,m) + 1; //result3 guarda el resultado en el caso del borrado
    
    if(n >1 && m>1 && ( s[n]== t[m-1] && s[n-1] == t[m] )) result4 = editdistancebf(s,n-2, t, m-2) + 1;//caso de transposicion en el que checkea si dos caracteres estan transpuestos en s respecto a t

    return min({result1, result2, result3, result4});
}

/*Entrada: dos palabras s y t de largo n y m
 *Salida: distancia minima de edicion 
 *Primero con costos constantes (1)

 *Operaciones
 *Sustitucion: Reemplaza un caracter i por otro
 *Inserción: Inserta un caracter en algun lugar
 *Borrado: Borra un caracter de s
 *Transposicion: Transpone dos caracteres consecutivos
*/
int editdistancedp(vector<char> s, int n, vector<char> t, int m){
    int M[n+1][m+1];
    for(int j = 0; j<=m; ++j)M[0][j] = j;//rellenar M[0][j] con j
    for(int i = 0; i<=n; ++i)M[i][0] = i;//rellenar M[i][0] con i

    for(int i = 1; i<=n; ++i){
        for(int j = 1; j<=m; ++j){
            if(t[j-2]!= s[i-1] || s[i-2]!=t[j-1]){
                M[i][j] = min({
                    M[i-1][j-1] + ((s[i-1]!=t[j-1])?1:0),
                    M[i][j-1] +1,
                    M[i-1][j] + 1});
            }
            else if(i >1 && j >1 && (s[i-1] == t[j-2] && s[i-2] == t[j-1])){
                M[i][j] = min({
                    M[i-1][j-1] + ((s[i-1]!=t[j-1])?1:0),
                    M[i][j-1] +1,
                    M[i-1][j] + 1,
                    M[i-2][j-2] + 1});
            }
        }
    }
    return M[n][m];
}
