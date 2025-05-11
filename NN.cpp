#include "NN.h"



NN::NN(vector<Layer>& layers) {
	if (layers.size() < 2) {
		throw invalid_argument("Invalid Neural Network");
	}
	nn = layers;
	hiddenCount = nn.size() - 2;
	nnCount = nn.size();
}


void NN::AddLayer(Layer& l) {
	nn.insert(nn.begin() + (nnCount - 2), l);
}

Matrix NN::forwardNN() {
	for (int i = 1; i < nnCount; i++) {
		Matrix x = nn[i - 1].getOutput();
		nn[i].Forward(x, "binary_sigmoid");
	}
	return nn[nnCount - 1].getOutput();
}
