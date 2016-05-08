#include <vector>
#include "NeuronLayer.h"

using namespace std;

NeuronLayer::NeuronLayer(int numNeurons, int numInputs): numNeurons(numNeurons){
    for (int i = 0; i < numNeurons; i += 1) {
        neurons.push_back(Neuron(numInputs));
    }
}

NeuronLayer::~NeuronLayer() {
}

vector<double> NeuronLayer::getWeights() const {
    vector<double> weights;
    for (auto &i : neurons) {
        vector<double> neuron_weights = i.getWeights();
        weights.insert( weights.end(), neuron_weights.begin(), neuron_weights.end() );
    }
    return weights;
}

unsigned int NeuronLayer::getNumberOfWeights() const {
    return neurons.size() * neurons.at(0).getNumInputs()+1;
}

void NeuronLayer::setWeights(vector<double> weights) {
    int weightsPerNeuron = neurons.at(0).getNumInputs()+1;
    if (weights.size() != weightsPerNeuron * neurons.size()) {
        throw "Wrong number of weights provided to layer!";
    }
    auto it = weights.begin();
    for (auto &neuron : neurons) {
        neuron.setWeights(vector<double>(it, it + weightsPerNeuron));
        it += weightsPerNeuron;
    }
}

vector<double> NeuronLayer::processInputs(vector<double> inputs) {
    vector <double> outputs;
    for (auto &neuron : neurons) {
        outputs.push_back(neuron.processInputs(inputs));
    }
    return outputs;
}
