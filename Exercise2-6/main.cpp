#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <iostream>
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}
template<typename T>
float cronometraggio_medio_BubbleSort(vector<T>& v)
{
    unsigned int num_experiment = 300;
    float time_elapsed= 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<T> v_copy(v);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort(v_copy);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    return time_elapsed / num_experiment;
}
template<typename T>
float cronometraggio_medio_HeapSort(vector<T>& v)
{
    unsigned int num_experiment = 300;
    float time_elapsed = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<T> v_copy(v);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort(v_copy);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    return time_elapsed / num_experiment;
}


int main()
{
    size_t m ;
    cout << "inserisci lunghezza vettori: ";
    cin >> m ; 

    vector<int> v1(m);
    iota(v1.begin(), v1.end(),0);
    //cout << "vettore ordinato: " << ArrayToString(v1) << endl;
    cout << "Cronometraggio_medio_BubbleSort " << cronometraggio_medio_BubbleSort(v1)<< endl;
    cout << "Cronometraggio_medio_HeapSort " << cronometraggio_medio_HeapSort(v1)<< endl;

    srand(2);
    vector<float> v2(m);
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX);
    //cout << "vettore di elementi decimali: " << ArrayToString(v2) << endl;
    cout << "Cronometraggio_medio_BubbleSort " << cronometraggio_medio_BubbleSort(v2)<< endl;
    cout << "Cronometraggio_medio_HeapSort " << cronometraggio_medio_HeapSort(v2)<< endl;

    vector<float> v3(m, 0);
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
    //cout << "vettore semi-ordinato: " << ArrayToString(v3) << endl;
    cout << "Cronometraggio_medio_BubbleSort " << cronometraggio_medio_BubbleSort(v3)<< endl;
    cout << "Cronometraggio_medio_HeapSort " << cronometraggio_medio_HeapSort(v3)<< endl;
    





}