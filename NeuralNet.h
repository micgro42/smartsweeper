/*
 * NeuralNet.h
 *
 *  Created on: May 8, 2016
 *      Author: michael
 */

#ifndef NEURALNET_H_
#define NEURALNET_H_

#include <vector>
#include "NeuronLayer.h"

using namespace std;

class NeuralNet {

private:
    unsigned int NumInputs;
    int NumOutputs;
    int NumHiddenLayers;
    int NeuronsPerHiddenLayer;
    vector<NeuronLayer> neuronLayers;

public:
    //gets the weights from the NN
    vector<double> getWeights() const;

    //returns the total number of weights in the net
    unsigned int getNumberOfWeights()const;

    //replaces the weights with new ones
    void putWeights(vector<double> &weights);

    vector<double> processInputs(vector<double> inputs);

    vector<double> update(vector<double> &inputs);

    NeuralNet();
    virtual ~NeuralNet();
};

#endif /* NEURALNET_H_ */
