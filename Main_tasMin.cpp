#include "Tas.h"
#include "Heap_Min.cpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// ==================== GENERATION DES VALEURS ====================

vector<int> genererValeurs(int n, mt19937& generateur) {

    vector<int> valeurs;

    for (int i = 1; i <= n; i++)
        valeurs.push_back(i);

    shuffle(valeurs.begin(), valeurs.end(), generateur);

    return valeurs;
}

// ==================== PROGRAMME PRINCIPAL ====================

int main() {

    vector<int> tailles = {
        10, 100, 1000, 5000, 10000, 50000, 100000
    };

    mt19937 generateur(42);

    cout << fixed << setprecision(6);

    cout << "================================================================================================================================\n";
    cout << "                         COMPARAISON DES STRUCTURES DE DONNEES - MIN HEAP\n";
    cout << "================================================================================================================================\n";

    cout << left
         << setw(12) << "N"
         << setw(15) << "Min trouve"
         << setw(38) << "Operation"
         << right
         << setw(15) << "Min-Heap"
         << setw(18) << "Priority Queue"
         << setw(12) << "Set"
         << setw(12) << "Map"
         << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int n : tailles) {

        vector<int> valeurs = genererValeurs(n, generateur);

        // Execution des tests
        Resultat heap = testerMinHeap(valeurs);
        Resultat pq = testerPriorityQueueMin(valeurs);
        Resultat s = testerSetMin(valeurs);
        Resultat m = testerMapMin(valeurs);

        // Verification du minimum
        if (heap.maximum != pq.maximum ||
            heap.maximum != s.maximum ||
            heap.maximum != m.maximum) {

            cout << "Erreur : les minimums sont differents !\n";
            return 1;
        }

        int minimumTrouve = heap.maximum;

        // Temps total
        double heapTotal =
            heap.insertion + heap.reorganisation;

        double pqTotal =
            pq.insertion + pq.reorganisation;

        double setTotal =
            s.insertion + s.reorganisation;

        double mapTotal =
            m.insertion + m.reorganisation;

        // ==================== INSERTION ====================

        cout << left
             << setw(12) << n
             << setw(15) << minimumTrouve
             << setw(38) << "Insertion (ms)"
             << right
             << setw(15) << heap.insertion
             << setw(18) << pq.insertion
             << setw(12) << s.insertion
             << setw(12) << m.insertion
             << endl;

        // ==================== RECUPERATION ====================

        cout << left
             << setw(12) << ""
             << setw(15) << ""
             << setw(38) << "Recuperation du minimum (ms)"
             << right
             << setw(15) << heap.recuperation
             << setw(18) << pq.recuperation
             << setw(12) << s.recuperation
             << setw(12) << m.recuperation
             << endl;

        // ==================== SUPPRESSION ====================

        cout << left
             << setw(12) << ""
             << setw(15) << ""
             << setw(38) << "Suppression + reorganisation (ms)"
             << right
             << setw(15) << heap.reorganisation
             << setw(18) << pq.reorganisation
             << setw(12) << s.reorganisation
             << setw(12) << m.reorganisation
             << endl;

        // ==================== TEMPS TOTAL ====================

        cout << left
             << setw(12) << ""
             << setw(15) << ""
             << setw(38) << "Temps total (ms)"
             << right
             << setw(15) << heapTotal
             << setw(18) << pqTotal
             << setw(12) << setTotal
             << setw(12) << mapTotal
             << endl;

        cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    return 0;
}
