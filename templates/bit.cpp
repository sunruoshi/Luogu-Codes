// template of binary indexed tree
// sam@2aliens.net
#include <vector>

template <class T>
class BinaryIndexedTree {
    private:
        std::vector<T> c;

    public:
        BinaryIndexedTree(size_t n) { c.resize(n); }
        void update(size_t pos, T v);
        T query(size_t pos);
};

template <class T>
void BinaryIndexedTree<T>::update(size_t pos, T v) {
    while (pos < c.size()) {
        c[pos] += v;
        pos += pos & (-pos);
    }
}

template <class T>
T BinaryIndexedTree<T>::query(size_t pos) {
    T res = 0;
    while (pos > 0) {
        res += c[pos];
        pos -= pos & (-pos);
    }
    return res;
}
