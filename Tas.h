
#ifndef TAS_H
#define TAS_H

#include <vector>

using namespace std;
struct Resultat {
    double insertion = 0;
    double recuperation = 0;
    double reorganisation = 0;
    int maximum = 0;
};
void insererMaxHeap(vector<int>& tas, int valeur);
void heapify(vector<int>& tas, int n, int i);
void supprimerMaxHeap(vector<int>& tas);
Resultat testerMaxHeap(const vector<int>& valeurs);
Resultat testerPriorityQueue(const vector<int>& valeurs);
Resultat testerSet(const vector<int>& valeurs);
Resultat testerMap(const vector<int>& valeurs);

#endif
