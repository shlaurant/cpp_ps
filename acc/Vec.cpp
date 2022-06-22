#include "Vec.h"

using namespace std;

template<class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T &val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator b, const_iterator e) {
    data = alloc.allocate(e - b);
    limit = avail = uninitialized_copy(b, e, data);
}

template<class T>
void Vec<T>::uncreate() {
    if (data) {
        auto it = avail;
        while (it != data) {
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit - data);
    }

    data = avail = limit = 0;
}

template<class T>
void Vec<T>::grow() {
    auto ns = max(2 * (limit - data), ptrdiff_t(1));

    auto nd = alloc.allocate(ns);
    auto na = uninitialized_copy(data, avail, nd);

    uncreate();

    data = nd;
    avail = na;
    limit = data + ns;
}

template<class T>
void Vec<T>::unchecked_append(const T &val) {
    alloc.template construct(avail++, val);
}