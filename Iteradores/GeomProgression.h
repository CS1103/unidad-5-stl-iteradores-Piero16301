#ifndef ITERADORES_GEOMPROGRESSION_H
#define ITERADORES_GEOMPROGRESSION_H

class GeomProgressionIterator {
    int curr;
    int base;
    friend class GeomProgression;
    GeomProgressionIterator(int curr, int base):
        curr{curr}, base{base} {}

public:
    bool operator==(const GeomProgressionIterator& other) const;
    bool operator!=(const GeomProgressionIterator& other) const;
    int& operator*();
    GeomProgressionIterator& operator++();
    GeomProgressionIterator& operator++(int);
};

class GeomProgression {
    int start;
    int stop;
    int base;

public:
    GeomProgression(int stop): start{0}, stop{stop}, base{2} {}
    GeomProgression(int start, int stop): start{start}, stop{stop}, base{2} {}
    GeomProgression(int start, int stop, int base): start{start}, stop{stop}, base{base} {}
    using iterator = GeomProgressionIterator;
    iterator begin() const {
        return GeomProgression::iterator(start, base);
    }

    iterator end() const {
        return GeomProgression::iterator(stop, base);
    }
};

bool GeomProgressionIterator::operator==(const GeomProgressionIterator &other) const {
    return curr == other.curr;
}

bool GeomProgressionIterator::operator!=(const GeomProgressionIterator &other) const {
    return curr < other.curr;
}

int &GeomProgressionIterator::operator*() {
    return curr;
}

GeomProgressionIterator &GeomProgressionIterator::operator++() {
    curr += base;
    return *this;
}

GeomProgressionIterator& GeomProgressionIterator::operator++(int) {
    auto it = this;
    ++(*this);
    return *it;
}

#endif //ITERADORES_GEOMPROGRESSION_H