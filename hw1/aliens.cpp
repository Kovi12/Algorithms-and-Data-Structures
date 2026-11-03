#include <iostream>
#include <fstream>
#include <vector>
#define N 100000
#define H 100000
using namespace std;

int best_dna(int v[]) {
    int max = 0;
    int indice = 0;
    for (int i = 0; i < H; i++)
    {
        if (max < v[i])
        {
            max = v[i];
            indice = i;
        }
    }
    return indice;
}

int main()
{
    ifstream input("aliens.in");
    
    int houses;
    input >> houses;
    int dna[N];
    int dna_no[H];

    for (int i = 0; i < houses; i++)
        input >> dna[i];
    input.close();

    for (int i = 0; i < H; i++)
        dna_no[i] = 0;

    int last_indice = 0;
    dna_no[dna[0]]++;
    for (int i = 1; i < houses; i++)
    {
        if (dna[i] != dna[i-1] || last_indice != i - 1)
        {
            dna_no[dna[i]]++;
            last_indice = i;
        }
    }
    ofstream output("aliens.out");
    output << best_dna(dna_no);
    output.close();
}
