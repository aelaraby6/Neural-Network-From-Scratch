#pragma once
#include "Matrix.h"

class Layer
{
private :
	Matrix inputs;
	Matrix outputs;
	Matrix weights;
	Matrix biases;

	/*Matrix delta;
	Matrix dWeights; 
	Matrix dBiases;*/

	int neurnCount;
	string activationFun;

public:

	Layer(Matrix& w, Matrix& b,int n);
	Layer(Matrix& inputLayer);

	// Go Forward to output layer
	Matrix Forward(Matrix& i,string activation = "binary_sigmoid");

	Matrix getOutput() const;

	Matrix getweights() const;

	Matrix getbiases() const;

	void setOutputs(Matrix& m);


	// Activation functions 
	Matrix binary_sigmoid(Matrix& m);
	Matrix bipolar_sigmoid(Matrix& m);
	Matrix ramp(Matrix& m);

	// print layer information
	void layerDetailes()const;

};

