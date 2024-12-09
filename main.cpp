#include <iostream>
#include <utility>
#include <vector>

#include "includes/hashtable.h"

using namespace std;

// Você recebeu uma lista de números inteiros e um número alvo (target). Seu
// objetivo é encontrar todos os pares de números distintos na lista que somam
// exatamente o valor do alvo.
// Por exemplo, dada a lista [2, 4, 3, 6, 5, 1, 7] e o alvo 8, os pares que somam 8
// seriam (2, 6), (3, 5).

vector<pair<int, int>> FindPairs(int list[], int size, int target) {
    vector<pair<int, int>> pairs;
    HashTable<int> complements(size);
    HashTable<int> seenPairs(size);


    for (int i = 0; i < size; i++) {
        int complement = target - list[i];

        if (complements.contains(complement)) {
            int num1 = min(list[i], complement);
            int num2 = max(list[i], complement);
            int uniqueKey = (num1 * 1000) + num2; // Criar uma chave única para o par

            // Adicionar apenas pares únicos
            if (!seenPairs.contains(uniqueKey)) {
                pairs.push_back({num1, num2});
                seenPairs.insert(uniqueKey);
            }
        }else {
            complements.insert(list[i]);
        }
    }
    
    return pairs;
}

int main() {
    int list[] = {2, 4, 3, 6, 5, 1, 7, 3, 5, 2, 6, 8, 0, 9, 10};

    int target = 10;

    int size = sizeof(list) / sizeof(list[0]);

    vector<pair<int, int>> pairs = FindPairs(list, size, target);

    cout << "Pairs that sum " << target << ":";

    for (pair<int, int> p : pairs) {
        cout << " (" << p.first << ", " << p.second << ")";
    }

    cout << endl;

    system("pause");
}