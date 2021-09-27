## Implementation of the perceptron learning algorithm:

  > Perceptron learning. Implement the perceptron-learning algorithm (PLA). Choose
  > three domains from the UCI repository and evaluate the PLA’s behavior for each of
  > them. Make sure that each domain contains only two classes. Report the results
  > along the following criteria: (1) error rate measured on an independent testing set,
  > and (2) computational costs, expressed as the number of example presentations
  > needed to achieve 100% accuracy. Discuss the different results in each domain.
  > Apart from domains with linearly separable classes, consider also a domain where
  > 100% accuracy on the training set is impossible to achieve because the classes are
  > not linearly separable.


Our version of the perceptron learning algorithm was implemented in C++. We created a class to hold all model data and functions. There are three main functions that implement the core of the algorithm.
 	These functions include:
hypothesis() -> returns a positive or negative value for the class distinction. 
updateWeights() -> iterates through the epochs and updates the weights’ values depending on if the example is positive or negative.
classifyData() -> iterates through all data points and determines class based on the hypothesis value.
	We used vectors as the primary data structure to hold all attributes, weights, and class data. As many of our datasets contained more than one attribute, we used a vector of vectors of doubles to hold attribute data. A difficulty we encountered was matching the size of the attributes to weights. This was overcome by the use of vectors, as we were able to dynamically run the model using datasets of various sizes and attributes. 
	We tested eight different datasets on our model (all from the UCI machine learning repository): cesarean section, banknote, iris, balloons, tic-tac-toe, haberman’s survival, and political house. The model was run using a set learning rate of 0.02 and 10 epochs to determine the accuracy of the classification. We also ran an optimization function with a set learning rate of 0.02 to find the minimum epochs to reach the maximum accuracy. Finally we ran the optimization function on both the epochs and learning rate to find the optimal combination of the two.
  
Our results and discussion is documented in ECE548-Perceptron-Writeup.pdf


