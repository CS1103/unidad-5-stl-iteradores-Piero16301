#ifndef ITERADORES_ARITHPROGRESSION_H
#define ITERADORES_ARITHPROGRESSION_H

using namespace std;

class ArithProgressionIterator {
    int curr;
    int step;
    friend class ArithProgression;
    ArithProgressionIterator(int curr, int step):
        curr{curr}, step{step} {}

public:
    bool operator==(const ArithProgressionIterator& other) const;
    bool operator!=(const ArithProgressionIterator& other) const;
    int& operator*();
    ArithProgressionIterator& operator++();
    ArithProgressionIterator& operator++(int);
};

class ArithProgression {
    int start;
    int stop;
    int step;

public:
    ArithProgression(int stop): start{0}, stop{stop}, step{1} {}
    ArithProgression(int start, int stop): start{start}, stop{stop}, step{1} {}
    ArithProgression(int start, int stop, int step): start{start}, stop{stop}, step{step} {}
    using iterator = ArithProgressionIterator;
    iterator begin() const {
        return ArithProgression::iterator(start, step);
    }

    iterator end() const {
        return ArithProgression::iterator(stop, step);
    }
};

bool ArithProgressionIterator::operator==(const ArithProgressionIterator &other) const {
    return curr == other.curr;
}

bool ArithProgressionIterator::operator!=(const ArithProgressionIterator &other) const {
    return curr < other.curr;
}

int &ArithProgressionIterator::operator*() {
    return curr;
}

ArithProgressionIterator &ArithProgressionIterator::operator++() {
    curr += step;
    return *this;
}

ArithProgressionIterator& ArithProgressionIterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}

#endif //ITERADORES_ARITHPROGRESSION_H