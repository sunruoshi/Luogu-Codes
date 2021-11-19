// template of linked list
// sam@2aliens.net
#include <cstdlib>

template <class T>
class List {
    public:
        class Iterator;
        size_t len;

        List() : len(0), head(new Iterator), tail(new Iterator) {
            head->next = tail;
            tail->prev = head;
            rear = head;
        }

        Iterator begin();
        Iterator end();
        Iterator find(const T &x);
        Iterator insert(const Iterator &it, const T &x);
        Iterator erase(const Iterator &it);

        T front();
        T back();

        void push_front(const T &x);
        void push_back(const T &x);
        void pop_front();
        void pop_back();

        size_t size();

    private:
        Iterator *head, *tail, *rear;
};

template <class T>
class List<T>::Iterator {
    public:
        T val;
        Iterator *prev, *next;
        Iterator(T x = 0, Iterator* p = NULL, Iterator* n = NULL) : val(x), prev(p), next(n) {}

        bool operator == (const Iterator &other) const;
        bool operator != (const Iterator &other) const;

        Iterator operator ++ ();
        Iterator operator ++ (int);
        Iterator operator -- ();
        Iterator operator -- (int);
        
        T operator * ();
};

template <class T>
bool List<T>::Iterator::operator == (const Iterator &other) const {
    return prev == other.prev && next == other.next;
}

template <class T>
bool List<T>::Iterator::operator != (const Iterator &other) const {
    return prev != other.prev || next != other.next;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator ++ () {
    Iterator res = *this;
    val = res.next->val;
    prev = res.next->prev;
    next = res.next->next;
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator ++ (int) {
    Iterator res = *this;
    val = res.next->val;
    prev = res.next->prev;
    next = res.next->next;
    return res;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator -- () {
    Iterator res = *this;
    val = res.prev->val;
    prev = res.prev->prev;
    next = res.prev->next;
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator -- (int) {
    Iterator res = *this;
    val = res.prev->val;
    prev = res.prev->prev;
    next = res.prev->next;
    return res;
}

template <class T>
T List<T>::Iterator::operator * () {
    return this->val;
}

template <class T>
size_t List<T>::size() {
    return this->len;
}

template <class T>
void List<T>::push_front(const T &x) {
    Iterator* p = new Iterator(x);
    p->prev = head;
    p->next = head->next;
    head->next->prev = p;
    head->next = p;
    this->len++;
}

template <class T>
void List<T>::push_back(const T &x) {
    Iterator* p = new Iterator(x);
    rear->next = p;
    p->prev = rear;
    p->next = tail;
    tail->prev = p;
    rear = p;
    this->len++;
}

template <class T>
void List<T>::pop_front() {
    Iterator* tmp = head->next;
    Iterator* nex = tmp->next;
    head->next = nex;
    nex->prev = head;
    delete(tmp);
    this->len--;
}

template <class T>
void List<T>::pop_back() {
    Iterator* tmp = tail->prev;
    Iterator* pre = tmp->prev;
    pre->next = tail;
    tail->prev = pre;
    rear = pre;
    delete(tmp);
    this->len--;
}

template <class T>
typename List<T>::Iterator List<T>::begin() {
    return *(head->next);
}

template <class T>
typename List<T>::Iterator List<T>::end() {
    return *tail;
}

template <class T>
T List<T>::front() {
    return head->next->val;
}

template <class T>
T List<T>::back() {
    return rear->val;
}

template <class T>
typename List<T>::Iterator List<T>::find(const T &x) {
    Iterator* p = head;
    while (p->next) {
        if (x == p->val) break;
        p = p->next;
    }
    return *p;
}

template <class T>
typename List<T>::Iterator List<T>::insert(const Iterator &it, const T &x) {
    Iterator* pre = it.prev;
    Iterator* res = new Iterator(x);
    res->next = pre->next;
    pre->next->prev = res;
    res->prev = pre;
    pre->next = res;
    this->len++;
    return *res;
}

template <class T>
typename List<T>::Iterator List<T>::erase(const Iterator &it) {
    if (it == *tail) return it;
    Iterator* pre = it.prev;
    Iterator* nex = it.next;
    Iterator* tmp = pre->next;
    pre->next = nex;
    nex->prev = pre;
    delete(tmp);
    this->len--;
    return *(pre->next);
}
