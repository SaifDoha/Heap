#include "Tas.h"
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <iterator>

using namespace std;
using namespace chrono;
// Insertion dans le Min-Heap
void insererMinHeap(vector<int>& tas, int valeur) {

    tas.push_back(valeur);

    int i = (int)tas.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (tas[parent] <= tas[i])
            break;

        swap(tas[parent], tas[i]);
        i = parent;
    }
}

// Réorganisation du Min-Heap
void heapifyMin(vector<int>& tas, int n, int i) {

    int plusPetit = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;

    if (gauche < n && tas[gauche] < tas[plusPetit])
        plusPetit = gauche;

    if (droite < n && tas[droite] < tas[plusPetit])
        plusPetit = droite;

    if (plusPetit != i) {
        swap(tas[i], tas[plusPetit]);
        heapifyMin(tas, n, plusPetit);
    }
}

// Suppression du minimum
void supprimerMinHeap(vector<int>& tas) {

    if (tas.empty())
        return;

    tas[0] = tas.back();
    tas.pop_back();

    if (!tas.empty())
        heapifyMin(tas, (int)tas.size(), 0);
}

// ==================== TEST MIN-HEAP ====================

Resultat testerMinHeap(const vector<int>& valeurs) {

    Resultat resultat;
    vector<int> tas;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        insererMinHeap(tas, x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Récupération du minimum
    debut = steady_clock::now();

    int minimum = 0;

    if (!tas.empty())
        minimum = tas[0];

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = minimum;

    // Suppression et réorganisation
    debut = steady_clock::now();

    while (!tas.empty())
        supprimerMinHeap(tas);

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST PRIORITY QUEUE MIN ====================

Resultat testerPriorityQueueMin(const vector<int>& valeurs) {

    Resultat resultat;

    priority_queue<int, vector<int>, greater<int>> pq;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        pq.push(x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Récupération du minimum
    debut = steady_clock::now();

    int minimum = 0;

    if (!pq.empty())
        minimum = pq.top();

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = minimum;

    // Suppression et réorganisation
    debut = steady_clock::now();

    while (!pq.empty())
        pq.pop();

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST SET ====================

Resultat testerSetMin(const vector<int>& valeurs) {

    Resultat resultat;
    set<int> s;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        s.insert(x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Récupération du minimum
    debut = steady_clock::now();

    int minimum = 0;

    if (!s.empty())
        minimum = *s.begin();

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = minimum;

    // Suppression et maintien de l'arbre
    debut = steady_clock::now();

    while (!s.empty()) {
        auto it = s.begin();
        s.erase(it);
    }

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST MAP ====================

Resultat testerMapMin(const vector<int>& valeurs) {

    Resultat resultat;
    map<int, int> m;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        m.insert({x, x});

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Récupération du minimum
    debut = steady_clock::now();

    int minimum = 0;

    if (!m.empty())
        minimum = m.begin()->first;

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = minimum;

    // Suppression et maintien de l'arbre
    debut = steady_clock::now();

    while (!m.empty()) {
        auto it = m.begin();
        m.erase(it);
    }

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}
