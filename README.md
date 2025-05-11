# Neural Network From Scratch

## Project Overview

This project is a simple implementation of a **Feed-Forward Neural Network** using C++. It demonstrates the basic concepts of neural networks including layers, weights, biases, and activation functions. The network is designed to process input data through multiple layers to generate output predictions.


## Classes

 Matrix Class : represents a  matrix used to store weights and biases in the neural network. It provides methods to manage and access matrix data 

- **`Matrix(vector<vector<float>> data, int rows, int cols)`**  
    Initializes a matrix with a 2D vector of `float` values, and sets the dimensions
- **`at(int row, int col)`**  
    Returns the value at the specified row and column.
- **`transpose()`**  
    Returns the transposed matrix (swapping rows and columns). Useful for many matrix operations during the network's forward pass and weight updates.
    
**Layer Class** : represents a layer in the neural network. It holds the layer's inputs, outputs, weights, and biases, and provides activation functions to transform the data as it propagates through the network.

- **`Layer(Matrix& weights, Matrix& biases, int n)`**  
    Initializes the layer with the provided weights, biases, and the number of neurons. The weights and biases matrices are used for the forward pass, and `n` specifies the number of neurons in the layer.
    
- **`Forward(Matrix& i, string activation = "binary_sigmoid")`**  
    Performs the forward pass through the layer. It computes the output by applying the specified activation function (default is `binary_sigmoid`). Accepts an input matrix and returns the output matrix after applying the weights, biases, and activation.

![sigmoid](https://github.com/user-attachments/assets/93794493-fd68-469b-b4c4-cd0263d1dc7d)

    
- **Activation Functions:**

- ![activationFunctions](https://github.com/user-attachments/assets/82875a28-aeb8-4106-a55f-e21c4d60d58f)


    - **`binary_sigmoid(Matrix& m)`**  
        Applies the binary sigmoid activation function to the matrix `m` element-wise. The function maps input values to the range `[0, 1]`.
        
    - **`bipolar_sigmoid(Matrix& m)`**  
        Applies the bipolar sigmoid activation function to the matrix `m` element-wise. This function maps input values to the range `[-1, 1]`.
        
    - **`ramp(Matrix& m)`**  
        Applies the ramp activation function to the matrix `m` element-wise. This function replaces all negative values with zero and leaves positive values unchanged.
        
- **`layerDetailes()`**  
    Prints the details of the laye

**NN Class** : represents a simple feedforward neural network. It manages a list of layers and performs the forward pass through the network.

- **`AddLayer(Layer& l)`**  
    Adds a new layer (`l`) to the neural network. This method allows for dynamically expanding the network by appending additional layers after the initial network creation.
    
- **`forwardNN()`**  
    Performs the forward pass through the entire neural network by passing the input through all layers sequentially. It returns the output matrix after propagating through all layers.


## Example: Neural Network Forward Pass

![NN](https://github.com/user-attachments/assets/89cbd593-7a01-4cdc-9e7e-42018b83bc6b)


This example demonstrates a simple neural network with an input layer, two hidden layers, and an output layer. Each layer is initialized with specific weights and biases. The network performs a forward pass through each layer to produce the output.

### Code Walkthrough

1. **Input Layer Initialization:**
    The input layer consists of 3 inputs, represented as a column vector:

    ```cpp
    vector<float> inputVec = { 0.8f, 0.6f, 0.4f };
    Matrix inputMatrix = Matrix::toMatrix(inputVec); // column vector
    Layer inputLayer(inputMatrix);
    ```

    **Matrix Representation of Input Layer:**
    ```
    Input Matrix (3x1):
    -------------------
    | 0.8 |
    | 0.6 |
    | 0.4 |
    -------------------
    ```

2. **Hidden Layer 1 (4 Neurons, 3 Inputs):**
    This layer has 4 neurons, each receiving 3 inputs. Weights and biases are provided for this layer:

    ```cpp
    Matrix weights1 = Matrix(vector<vector<float>>{
        {0.2f, -0.3f, 0.4f},
        {0.7f, -0.5f, 0.1f},
        {-0.4f, 0.9f, 0.3f},
        {0.5f, 0.2f, -0.6f}
    }, 4, 3);

    Matrix bias1 = Matrix::toMatrix({ 0.1f, 0.2f, 0.05f, -0.05f }); // 4x1
    Layer hidden1(weights1, bias1, 4);
    ```

    **Matrix Representation of Weights for Hidden Layer 1:**
    ```
    Weights (4x3):
    -------------------
    |  0.2 | -0.3 |  0.4 |
    |  0.7 | -0.5 |  0.1 |
    | -0.4 |  0.9 |  0.3 |
    |  0.5 |  0.2 | -0.6 |
    -------------------
    ```

    **Matrix Representation of Biases for Hidden Layer 1:**
    ```
    Bias (4x1):
    -------------------
    | 0.1  |
    | 0.2  |
    | 0.05 |
    | -0.05|
    -------------------
    ```

3. **Hidden Layer 2 (3 Neurons, 4 Inputs):**
    The second hidden layer has 3 neurons, each receiving 4 inputs. The weights and biases are as follows:

    ```cpp
    Matrix weights2 = Matrix(vector<vector<float>>{
        {0.1f, -0.2f, 0.3f, 0.5f},
        {-0.4f, 0.6f, -0.1f, 0.2f},
        {0.7f, -0.3f, 0.8f, -0.5f}
    }, 3, 4);

    Matrix bias2 = Matrix::toMatrix({ 0.1f, -0.1f, 0.05f }); // 3x1
    Layer hidden2(weights2, bias2, 3);
    ```

    **Matrix Representation of Weights for Hidden Layer 2:**
    ```
    Weights (3x4):
    -------------------------
    |  0.1 | -0.2 |  0.3 |  0.5 |
    | -0.4 |  0.6 | -0.1 |  0.2 |
    |  0.7 | -0.3 |  0.8 | -0.5 |
    -------------------------
    ```

    **Matrix Representation of Biases for Hidden Layer 2:**
    ```
    Bias (3x1):
    -------------------
    | 0.1   |
    | -0.1  |
    | 0.05  |
    -------------------
    ```

4. **Output Layer (1 Neuron, 3 Inputs):**
    The output layer has 1 neuron, receiving 3 inputs:

    ```cpp
    Matrix weights3 = Matrix::toMatrix({ 0.2f, 0.5f, -0.3f }, true); // 1x3
    Matrix bias3 = Matrix::toMatrix({ 0.2f }); // 1x1
    Layer outputLayer(weights3, bias3, 1);
    ```

    **Matrix Representation of Weights for Output Layer:**
    ```
    Weights (1x3):
    -------------------
    |  0.2 |  0.5 | -0.3 |
    -------------------
    ```

    **Matrix Representation of Biases for Output Layer:**
    ```
    Bias (1x1):
    -------------------
    | 0.2  |
    -------------------
    ```

5. **Neural Network Initialization:**
    The layers are combined into a neural network:

    ```cpp
    vector<Layer> layers = { inputLayer, hidden1, hidden2, outputLayer };
    NN network(layers);
    ```

7. **Forward Pass:**
    The forward pass is computed and output:

    ```cpp
    Matrix output = network.forwardNN();
    cout << "Network output:
" << output << endl;
    ```

## Future Enhancements

- [ ] **Backpropagation Implementation:** Implement backpropagation for the network to update weights and biases during training based on the error between predicted and actual outputs.

- [ ] **Different Activation Functions:** Add more activation functions such as `tanh`, `Leaky ReLU`, or `Softmax` for classification tasks.

- [ ] **Cost Functions:** Implement additional cost functions like Cross-Entropy or Mean Squared Logarithmic Error (MSLE) for different use cases.

- [ ] **Advanced Visualizations:** Add graph plotting for loss, accuracy, and other metrics over epochs to visualize training progress.
