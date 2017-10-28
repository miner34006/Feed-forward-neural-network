//
// Created by Богдан Полянок on 01.10.2017.
//

#include "neuralNetwork.hpp"

#include "../layers/inputLayer.hpp"
#include "../layers/hiddenLayer.hpp"
#include "../layers/outputLayer.hpp"

NeuralNetwork::NeuralNetwork(const std::vector<int> &neuronsPerLayer, const bool& hasBias)
{
  if (neuronsPerLayer.size() <= 2){
    throw std::invalid_argument("Number of layers must be more than 2");
  }
  NeuralNetwork::createLayers(neuronsPerLayer, hasBias);
}

void NeuralNetwork::setInputData(const std::vector<double> &data)
{
  inputLayer_->setInputData(data);
}

size_t NeuralNetwork::getLayersCount() const
{
  return hiddenLayers_.size() + 2;
}

std::shared_ptr<Layer> NeuralNetwork::operator[](const size_t &layerNumber)
{
  if (layerNumber >= getLayersCount()){
    throw std::out_of_range("Invalid neuron index;");
  }

  if (layerNumber == 0){
    return inputLayer_;
  } else if (layerNumber == hiddenLayers_.size() + 1){
    return outputLayer_;
  } else {
    return hiddenLayers_.at(layerNumber - 1);
  }
}

void NeuralNetwork::passDataForward(const size_t &fromLayer, const size_t &toLayer)
{
  std::shared_ptr<Layer> from = (*this)[fromLayer];
  std::shared_ptr<Layer> to = (*this)[toLayer];

  for (size_t i = 0; i < to->getNeuronQuantity(); i++){
    double impulse = from->getTotalImpulse(i);
    (*to)[i]->setInput(impulse);
    (*to)[i]->activation();
  }
}

double NeuralNetwork::feedForward(const std::vector<double> &data)
{
  setInputData(data);
  for (size_t i = 0; i < getLayersCount() - 1; i++){
    passDataForward(i, i + 1);
  }
  const double answer = (*outputLayer_).getMaxImpulse();
  return answer;
}

void NeuralNetwork::backPropagation(const double &expect, const double &learningRate, const double &momentum)
{
  outputLayer_->changeWeights(expect, learningRate, momentum);

  const size_t lastHiddenLayer = hiddenLayers_.size() - 1;
  hiddenLayers_[lastHiddenLayer]->changeWeights(learningRate, momentum, outputLayer_);
  for (auto hiddenLayer = hiddenLayers_.rbegin() + 1; hiddenLayer != hiddenLayers_.rend(); ++hiddenLayer){
    (*hiddenLayer)->changeWeights(learningRate, momentum, *(hiddenLayer - 1));
  }

  const size_t firstHiddenLayer = 0;
  inputLayer_->changeWeights(learningRate, momentum, hiddenLayers_[firstHiddenLayer]);
}

void NeuralNetwork::createLayers(const std::vector<int> &neuronPerLayer, const bool& hasBias)
{
  inputLayer_ = std::make_shared<InputLayer>(neuronPerLayer.front(), hasBias);

  for (size_t i = 1; i < neuronPerLayer.size() - 1; i++){
    hiddenLayers_.push_back(std::make_shared<HiddenLayer>(neuronPerLayer.at(i), hasBias));
  }

  outputLayer_ = std::make_shared<OutputLayer>(neuronPerLayer.back());

  NeuralNetwork::setWeights();
}

void NeuralNetwork::setWeights()
{
  const size_t firstHiddenLayer = 0;
  inputLayer_->setWeights(hiddenLayers_.at(firstHiddenLayer));

  for (auto hiddenLayer = hiddenLayers_.begin(); hiddenLayer != hiddenLayers_.end() - 1; ++hiddenLayer){
    (*hiddenLayer)->setWeights(*(hiddenLayer + 1));
  }

  const size_t lastHiddenLayer = hiddenLayers_.size() - 1;
  hiddenLayers_.at(lastHiddenLayer)->setWeights(outputLayer_);
}

std::ostream& operator<<(std::ostream &out, const NeuralNetwork &neuralNetwork)
{
  out << "Neural network information:\n"
      << "\tNumber of layers: " << neuralNetwork.getLayersCount() << "\n\n";

  out << *(neuralNetwork.inputLayer_);

  for (size_t i = 0; i < neuralNetwork.hiddenLayers_.size(); i++){
    out << *neuralNetwork.hiddenLayers_.at(i);
  }

  out << *(neuralNetwork.outputLayer_);

  return out;
}
