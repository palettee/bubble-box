#include <stdio.h>

class Animal {
    public:
        virtual int walk(int steps) = 0;
};

class Kangaroo: public Animal {
    public:
        int walk(int steps) { return 2*steps; }
};

class Trainer {
    public:
        int orderWalk(Animal* animal) { return animal->walk(4); }
};