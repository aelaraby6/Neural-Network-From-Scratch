#pragma once
#include "Layer.h"

class NN
{

private:
	int hiddenCount;
	int nnCount;
	vector<Layer>nn;

public:

	NN(vector<Layer>& layers);
	void AddLayer(Layer& l);

	Matrix forwardNN();
};

