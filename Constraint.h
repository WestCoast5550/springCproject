#ifndef RECURSIVETEMPLATE_CONSTRAINT_H
#define RECURSIVETEMPLATE_CONSTRAINT_H

#include <vector>

template<class T, class K>
class Constraint {
public:
    virtual bool CheckConstraint(std::vector<T *>, T *, K *) = 0;
};


#endif //RECURSIVETEMPLATE_CONSTRAINT_H
