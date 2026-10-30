
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
// ==================== FONCTIONS MIN-HEAP ====================

void insererMinHeap(vector<int>& tas, int valeur);
void heapifyMin(vector<int>& tas, int n, int i);
void supprimerMinHeap(vector<int>& tas);
Resultat testerMinHeap(const vector<int>& valeurs);
Resultat testerPriorityQueueMin(const vector<int>& valeurs);
Resultat testerSetMin(const vector<int>& valeurs);
Resultat testerMapMin(const vector<int>& valeurs);

#endif
