
#ifndef NEURONLAYER_H_
#define NEURONLAYER_H_

#include <vector>
#include "Neuron.h"

using namespace std;

class NeuronLayer {
private:
    int numNeurons; // ToDo: Check if we actually need this member
    vector<Neuron> neurons;
public:
    NeuronLayer(int numNeurons, int numInputs);
    virtual ~NeuronLayer();

    vector<double> getWeights() const;
    unsigned int getNumberOfWeights() const;
    void setWeights(vector<double> weights);
    vector<double> processInputs(vector<double> inputs);
};

#endif /* NEURONLAYER_H_ */
