#include "Tas.h"
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <chrono>
#include <iterator>

using namespace std;
using namespace chrono;

void insererMaxHeap(vector<int>& tas, int valeur) {

    tas.push_back(valeur);
    int i = (int)tas.size() - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (tas[parent] >= tas[i])
            break;

        swap(tas[parent], tas[i]);
        i = parent;
    }
}

void heapify(vector<int>& tas, int n, int i) {

    int plusGrand = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;

    if (gauche < n && tas[gauche] > tas[plusGrand])
        plusGrand = gauche;

    if (droite < n && tas[droite] > tas[plusGrand])
        plusGrand = droite;

    if (plusGrand != i) {
        swap(tas[i], tas[plusGrand]);
        heapify(tas, n, plusGrand);
    }
}

void supprimerMaxHeap(vector<int>& tas) {

    if (tas.empty())
        return;

    tas[0] = tas.back();
    tas.pop_back();

    if (!tas.empty())
        heapify(tas, (int)tas.size(), 0);
}

// ==================== TEST MAX-HEAP ====================

Resultat testerMaxHeap(const vector<int>& valeurs) {

    Resultat resultat;
    vector<int> tas;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        insererMaxHeap(tas, x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Recuperation du maximum
    debut = steady_clock::now();

    volatile int maximum = tas[0];

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = maximum;

    // Suppression et reorganisation
    debut = steady_clock::now();

    while (!tas.empty())
        supprimerMaxHeap(tas);

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST PRIORITY QUEUE ====================

Resultat testerPriorityQueue(const vector<int>& valeurs) {

    Resultat resultat;
    priority_queue<int> pq;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        pq.push(x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Recuperation du maximum
    debut = steady_clock::now();

    volatile int maximum = pq.top();

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = maximum;

    // Suppression et reorganisation
    debut = steady_clock::now();

    while (!pq.empty())
        pq.pop();

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST SET ====================

Resultat testerSet(const vector<int>& valeurs) {

    Resultat resultat;
    set<int> s;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        s.insert(x);

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Recuperation du maximum
    debut = steady_clock::now();

    volatile int maximum = *s.rbegin();

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = maximum;

    // Suppression et maintien de l'arbre
    debut = steady_clock::now();

    while (!s.empty()) {
        auto it = prev(s.end());
        s.erase(it);
    }

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}

// ==================== TEST MAP ====================

Resultat testerMap(const vector<int>& valeurs) {

    Resultat resultat;
    map<int, int> m;

    // Insertion
    auto debut = steady_clock::now();

    for (int x : valeurs)
        m.insert({x, x});

    auto fin = steady_clock::now();

    resultat.insertion =
        duration<double, milli>(fin - debut).count();

    // Recuperation du maximum
    debut = steady_clock::now();

    volatile int maximum = m.rbegin()->first;

    fin = steady_clock::now();

    resultat.recuperation =
        duration<double, milli>(fin - debut).count();

    resultat.maximum = maximum;

    // Suppression et maintien de l'arbre
    debut = steady_clock::now();

    while (!m.empty()) {
        auto it = prev(m.end());
        m.erase(it);
    }

    fin = steady_clock::now();

    resultat.reorganisation =
        duration<double, milli>(fin - debut).count();

    return resultat;
}
