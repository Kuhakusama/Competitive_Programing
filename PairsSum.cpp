#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> somaPar(vector<int> arr, int Sum) {
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) { // Corrigido: use < em vez de <<
        int x = Sum - arr[i];
        if (s.find(x) != s.end()) {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    return result; // Adicionado: retorna um vetor vazio se nenhum par for encontrado
}

int main() {
    vector<int> arr{10, 5, 2, 3, -6, 11};
    int S = 4;

    auto p = somaPar(arr, S);

    if (p.size() == 0) {
        cout << "No such pair" << endl;
    } else {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}
