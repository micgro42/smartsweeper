#include <stdlib.h>
#include <cmath>
#include "Neuron.h"

/**
 * Initialize Neuron with weights. Add one additional weight in order to evolve
 * the threshold as well
 *
 * @param numInputs
 */
Neuron::Neuron(int numInputs): numInputs(numInputs+1) {
    for (int i = 0; i < numInputs+1; i += 1) {
           weights.push_back(rand());
    }
}

Neuron::~Neuron() {
}

/**
 * Calculate the response of the neuron
 *
 * ToDo: Research what p is
 *
 * @param input
 * @param p
 * @return
 */
double Neuron::sigmoid(double input, double p)
{
    return ( 1 / ( 1 + exp(-input / p)));
}

double Neuron::processInputs(vector<double> inputs) {
    double neuronResponse = 0;
    for(unsigned int i = 0; i < inputs.size(); i += 1) {
        neuronResponse += inputs.at(i) * weights.at(i);
    }
    neuronResponse += -1 * weights.back();
    return sigmoid(neuronResponse, 1.0);
}
