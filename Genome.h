
#ifndef GENOME_H_
#define GENOME_H_

#include <vector>

using namespace std;

class Genome {
private:
    double fitness;
    vector<double> weights;

public:
    Genome();
    virtual ~Genome();
    friend bool operator<(const Genome& lhs, const Genome& rhs) {
        return (lhs.fitness < rhs.fitness);
    }
};

#endif /* GENOME_H_ */
