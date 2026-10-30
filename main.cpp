#include "Tas.h"
#include "Heap_Max.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

vector<int> genererValeurs(int n, mt19937& generateur) {
    vector<int> valeurs;
    for (int i = 1; i <= n; i++)
        valeurs.push_back(i);
    shuffle(valeurs.begin(), valeurs.end(), generateur);
    return valeurs;
}

int main() {

    vector<int> tailles = {
        10, 100, 1000, 5000, 10000, 50000, 100000};

    mt19937 generateur(42);
    cout << fixed << setprecision(6);

    cout << "================================================================================================================================\n";
    cout << "                         COMPARAISON DES STRUCTURES DE DONNEES\n";
    cout << "================================================================================================================================\n";

    cout << left
         << setw(12) << "N"
         << setw(15) << "Max trouve"
         << setw(38) << "Operation"
         << right
         << setw(15) << "Max-Heap"
         << setw(18) << "Priority Queue"
         << setw(12) << "Set"
         << setw(12) << "Map"
         << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int n : tailles) {

        vector<int> valeurs = genererValeurs(n, generateur);

        // Execution des tests
        Resultat heap = testerMaxHeap(valeurs);
        Resultat pq = testerPriorityQueue(valeurs);
        Resultat s = testerSet(valeurs);
        Resultat m = testerMap(valeurs);

        // Verification du maximum
        if (heap.maximum != pq.maximum ||
            heap.maximum != s.maximum ||
            heap.maximum != m.maximum) {

            cout << "Erreur : les maximums sont differents !\n";
            return 1;
        }

        int maximumTrouve = heap.maximum;

        // Temps total
        double heapTotal =
            heap.insertion + heap.reorganisation;

        double pqTotal =
            pq.insertion + pq.reorganisation;

        double setTotal =
            s.insertion + s.reorganisation;

        double mapTotal =
            m.insertion + m.reorganisation;

        // Insertion
        cout << left
             << setw(12) << n
             << setw(15) << maximumTrouve
             << setw(38) << "Insertion (ms)"
             << right
             << setw(15) << heap.insertion
             << setw(18) << pq.insertion
             << setw(12) << s.insertion
             << setw(12) << m.insertion
             << endl;

        // Recuperation
        cout << left
             << setw(12) << ""
             << setw(15) << ""
             << setw(38) << "Recuperation du maximum (ms)"
             << right
             << setw(15) << heap.recuperation
             << setw(18) << pq.recuperation
             << setw(12) << s.recuperation
             << setw(12) << m.recuperation
             << endl;

        // Suppression et reorganisation
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

        // Temps total
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
