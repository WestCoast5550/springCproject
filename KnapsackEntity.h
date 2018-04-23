//
// Created by Ринат Гумаров on 23/04/2018.
//

#ifndef RECURSIVETEMPLATE_KNAPSACKENTITY_H
#define RECURSIVETEMPLATE_KNAPSACKENTITY_H


class KnapsackEntity{
private:
    int weight;
    int cost;
public:
    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        KnapsackEntity::weight = weight;
    }

    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        KnapsackEntity::cost = cost;
    }

    bool operator == (const KnapsackEntity& knapsackEntity){
        return this->getWeight() == knapsackEntity.getWeight() && this->getCost() == knapsackEntity.getCost();
    }

    KnapsackEntity(int weight, int cost) : weight(weight), cost(cost) {}
    ~KnapsackEntity(){}

};


#endif //RECURSIVETEMPLATE_KNAPSACKENTITY_H
