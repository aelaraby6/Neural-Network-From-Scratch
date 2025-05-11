#include <iostream>
#include "NN.h"
#include "Layer.h"
#include "Matrix.h"

using namespace std;

int main() {
    vector<float> inputVec = { 0.8f, 0.6f, 0.4f };
    Matrix inputMatrix = Matrix::toMatrix(inputVec); // column vector
    Layer inputLayer(inputMatrix);

    //  Hidden Layer 1: 4 neurons, 3 inputs
    vector<float> w1 = {
        0.2f, -0.3f, 0.4f,
        0.7f, -0.5f, 0.1f,
        -0.4f, 0.9f, 0.3f,
        0.5f, 0.2f, -0.6f
    };
    Matrix weights1 = Matrix(vector<vector<float>>{
        {0.2f, -0.3f, 0.4f},
        { 0.7f, -0.5f, 0.1f },
        { -0.4f, 0.9f, 0.3f },
        { 0.5f, 0.2f, -0.6f }
    }, 4, 3);

    vector<float> b1 = { 0.1f, 0.2f, 0.05f, -0.05f };
    Matrix bias1 = Matrix::toMatrix(b1); // 4x1

    Layer hidden1(weights1, bias1, 4);

    //  Hidden Layer 2: 3 neurons, 4 inputs
    Matrix weights2 = Matrix(vector<vector<float>>{
        {0.1f, -0.2f, 0.3f, 0.5f},
        { -0.4f, 0.6f, -0.1f, 0.2f },
        { 0.7f, -0.3f, 0.8f, -0.5f }
    }, 3, 4);

    vector<float> b2 = { 0.1f, -0.1f, 0.05f };
    Matrix bias2 = Matrix::toMatrix(b2); // 3x1

    Layer hidden2(weights2, bias2, 3);

    // Output Layer: 1 neuron, 3 inputs
    vector<float> w3 = { 0.2f, 0.5f, -0.3f };
    Matrix weights3 = Matrix::toMatrix(w3, true); // 1x3
    vector<float> b3 = { 0.2f };
    Matrix bias3 = Matrix::toMatrix(b3); // 1x1

    Layer outputLayer(weights3, bias3, 1);

    vector<Layer> layers = { inputLayer, hidden1, hidden2, outputLayer };
    NN network(layers);

    for (size_t i = 0; i < layers.size(); i++) {
        cout << "-----------------------------------\n";
        cout << "Details of Layer " << i + 1 << ":\n";
        layers[i].layerDetailes();
        cout << "-----------------------------------\n";
        cout << endl;
    }

    Matrix output = network.forwardNN();

    cout << "Network output:\n" << output << endl;

    return 0;
}


