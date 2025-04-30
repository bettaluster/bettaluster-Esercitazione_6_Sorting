#pragma once

#include <iostream>
#include <vector>
#include <algorithm> // per std::swap
#include <concepts>  // per std::convertible_to

using namespace std;

namespace SortLibrary {

    template<typename T>
    concept Sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>;
    };

    template<Sortable T>
    void BubbleSort(std::vector<T>& v)
    {
        const unsigned int n = v.size();
        bool scambiato;
        do {
            scambiato = false;
            for (unsigned int i = 1; i < n; ++i) {
                if (v[i - 1] > v[i]) {
                    std::swap(v[i - 1], v[i]);
                    scambiato = true;
                }
            }
        } while (scambiato);    
    }
    
    template<Sortable T>
    void HeapSort(std::vector<T>& v) {
        int n = v.size();

        // Costruisci il max heap
        for (int i = n / 2 - 1; i >= 0; --i) {
            int root = i;
            while (2 * root + 1 < n) {
                int child = 2 * root + 1; // figlio sinistro
                if (child + 1 < n && v[child] < v[child + 1])
                    child++; // figlio destro è più grande
                if (v[root] < v[child]) {
                    std::swap(v[root], v[child]);
                    root = child;
                } else {
                    break;
                }
            }
        }

        // Estrai elementi uno a uno
        for (int i = n - 1; i > 0; --i) {
            std::swap(v[0], v[i]); // porta il massimo in fondo
            int root = 0;
            int heap_size = i;

            while (2 * root + 1 < heap_size) {
                int child = 2 * root + 1;
                if (child + 1 < heap_size && v[child] < v[child + 1])
                    child++;
                if (v[root] < v[child]) {
                    std::swap(v[root], v[child]);
                    root = child;
                } else {
                    break;
                }
            }
        }
    }

}
