#include <bits/stdc++.h>
using namespace std;

// busca e remove 'value' no vetor. Eficiente pois o vetor.length tem no maximo
// 2 valores
void removeVal(vector<int> &vec, int value) {
    auto it = find(vec.begin(), vec.end(), value);
    vec.erase(it);
}

int main() {
    int n, a, b;
    cin >> n;

    // set com o valor inicial e final
    unordered_set<int> endPoints;

    // Lista de adjacencia, a chave é o vertice de origem,
    // o valor é um vetor com os vertices de destino
    unordered_map<int, vector<int>> adjacenceList;

    while (n--) {
        cin >> a >> b;
        adjacenceList[a].push_back(b);
        adjacenceList[b].push_back(a);

        // Como temos certeza que o valor inicial e final so aparece uma vez,
        // removemos o valor se ele já estiver no set, caso contrario adiciona.
        // Após isso vamos ter um set apenas com os valores inicial e final.
        if (endPoints.count(a)) {
            endPoints.erase(a);
        } else {
            endPoints.insert(a);
        }
        if (endPoints.count(b)) {
            endPoints.erase(b);
        } else {
            endPoints.insert(b);
        }
    }

    // Pegamos o valor inicial, pode ser qualquer um dos dois valores do set.
    int city = *endPoints.begin();

    // Se tivermos o valor inicial correto, temos a certeza que a partir dele
    // so vamos ter um caminho possivel, basta seguir por ele imprimindo as
    // cidades
    while (!adjacenceList[city].empty() && adjacenceList[city].back()) {
        int destiny = adjacenceList[city].back();
        removeVal(adjacenceList[destiny], city);
        adjacenceList.erase(city);
        cout << city << ' ';
        city = destiny;
    }
    cout << city;
}