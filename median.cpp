#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;

template<class T>
T median(vector<T> vec) {

    typename vector<T>::size_type a = 2;
    auto vec_size = vec.size();

    if (vec_size == 0) {
        throw std::domain_error("The vector is empty");
    }

    std::sort(vec.begin(), vec.end());
    auto mid = vec_size / 2;

    return vec_size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}