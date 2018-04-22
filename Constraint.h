#ifndef RECURSIVETEMPLATE_CONSTRAINT_H
#define RECURSIVETEMPLATE_CONSTRAINT_H

#include <vector>

template<class T>
class Constraint {
public:
    virtual bool CheckConstraint(std::vector<T *>, T *) = 0;
};


#endif //RECURSIVETEMPLATE_CONSTRAINT_H
