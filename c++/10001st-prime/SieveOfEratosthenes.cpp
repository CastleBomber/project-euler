#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> SieveOfEratosthenes()
{
    unordered_map<int, int> umap;
    umap[0] = 0;
    umap[1] = 10;
    umap[2] = 20;

    return umap;

}