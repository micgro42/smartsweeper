
#include <vector>
#include "NeuralNet.h"

using namespace std;

NeuralNet::NeuralNet() {
    // TODO Auto-generated constructor stub

}

vector<double> NeuralNet::getWeights() const{
    vector<double> weights;
    for (auto &i : neuronLayers) {
        vector<double> layerWeights = i.getWeights();
    }
    return weights;
}

void NeuralNet::putWeights(vector<double>& weights) {
    if (weights.size() != this->getNumberOfWeights()) {
        throw "Wrong number of weights provided to net.";
    }
    auto it = weights.begin();
    for (auto &layer : neuronLayers) {
        layer.setWeights(vector<double>(it, it + layer.getNumberOfWeights()));
        it += layer.getNumberOfWeights();
    }
}

vector<double> NeuralNet::processInputs(vector<double> inputs) {
    //first check that we have the correct amount of inputs
    if (inputs.size() != NumInputs) {
        // todo: replace by number of inputs of first layer?
        throw "Wrong number of inputs to process by net!";
    }


    for (auto &layer : neuronLayers) {
        inputs = layer.processInputs(inputs);
    }

    return inputs;

}

unsigned int NeuralNet::getNumberOfWeights() const {
    int numberOfWeights = 0;
    for (auto &layer : neuronLayers) {
        numberOfWeights += layer.getNumberOfWeights();
    }
    return numberOfWeights;
}

NeuralNet::~NeuralNet() {
}


