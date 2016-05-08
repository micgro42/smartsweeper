#ifndef NEURON_H_
#define NEURON_H_

#include <vector>

using namespace std;

class Neuron {

private:
    int numInputs;
    vector<double> weights;

public:
    Neuron(int numInputs);
    virtual ~Neuron();

    const vector<double>& getWeights() const {
        return weights;
    }

    void setWeights(const vector<double>& weights) {
        this->weights = weights;
    }

    int getNumInputs() const {
        return numInputs; // todo: implement with weights.size()-1
    }

    double processInputs(vector<double> inputs);
    double sigmoid(double input, double p);
};

#endif /* NEURON_H_ */
