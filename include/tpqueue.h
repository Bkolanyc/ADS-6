// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T a[size] = { 0 };
    int last, first;
public:
    void push(T x) {
        int i = last;
        for (; (i >= first) && a[i % size].prior < x.prior; --i) {
            a[(i + 1) % size] = a[i % size];
        }
        a[(i + 1) % size] = x;
        ++last;
    }
    T pop() {
        return a[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
