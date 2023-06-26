#ifndef ENTITY_H_
#define ENTITY_H_

struct Vector {
    int x;
    int y;        
};

class Entity {
    public:
        Entity(int x, int y);
        Vector pos;
};

#endif