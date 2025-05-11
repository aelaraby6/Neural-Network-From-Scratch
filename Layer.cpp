#include "Layer.h"

Layer::Layer( Matrix& weights,  Matrix& biases,int n)
    : weights(weights), biases(biases),neurnCount(n) {}

Layer::Layer(Matrix& inputLayer) : outputs(inputLayer){}



Matrix Layer::Forward(Matrix& i,string activation) {
    inputs = i;

    activationFun = activation;
    
    outputs = (weights * inputs) + biases;

    if (activation == "binary_sigmoid") {
        outputs = binary_sigmoid(outputs);
    }
    else if (activation == "bipolar_sigmoid") {
        outputs = bipolar_sigmoid(outputs);
    }
    else {
        outputs = ramp(outputs);
    }

    return outputs;

}


Matrix Layer::getOutput() const {
    return outputs;
}

Matrix Layer::getweights() const {
    return weights;
}

Matrix Layer::getbiases() const {
    return biases;
}

void Layer::setOutputs(Matrix& m) {
    outputs = m;
}

// Activation function - binary sigmoid
Matrix Layer::binary_sigmoid( Matrix& m) {
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            result.in(i, j) = 1.0 / (1.0 + exp(-m.in(i, j)));
        }
    }
    return result;
}

// Activation function - bipolar sigmoid
Matrix Layer::bipolar_sigmoid( Matrix& m) {
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            result.in(i, j) = 2.0 / (1.0 + exp(-m.in(i, j))) - 1.0;
        }
    }
    return result;
}

// Activation function - ramp (ReLU)
Matrix Layer::ramp( Matrix& m) {
    Matrix result(m.getRows(), m.getCols());
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            result.in(i, j) = max(0.0f, m.in(i, j));
        }
    }
    return result;
}

void Layer::layerDetailes() const {
    cout << "-----------------------------------" << endl;
    cout << "Layer Information: " << endl;

    cout << "Weights (size " << weights.getRows() << "x" << weights.getCols() << "):" << endl;
    for (size_t i = 0; i < weights.getRows(); ++i) {
        for (size_t j = 0; j < weights.getCols(); ++j) {

            cout << weights.at(i, j) << "\t";
        }
        cout << endl;
    }

    cout << "-----------------------------------" << endl;

    cout << "Bias (size " << biases.getRows() << "x" << biases.getCols() << "):" << endl;
    for (size_t i = 0; i < biases.getRows(); ++i) {

        cout << biases.at(i, 0) << "\t"; 
    }
    cout << endl;

    cout << "-----------------------------------" << endl;
}

