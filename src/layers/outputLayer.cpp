//
// Created by Богдан Полянок on 30.09.2017.
//

#include "outputLayer.hpp"

#include "../neuron/neuron.hpp"


OutputLayer::OutputLayer(const size_t &neuronQuantity):
  Layer(neuronQuantity)
{}

void OutputLayer::changeWeights(const std::vector<double> &expectedAnswer, const double& learningRate, const double& alpha)
{
  if (expectedAnswer.size() != getNeuronQuantity()){
    throw std::invalid_argument("Wrong expected output data;");
  }
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double output = neurons_.at(i)->getOutput();
    const double error = expectedAnswer[i] - output;
    const double sigDx = output * (1 - output);
    neurons_.at(i)->setWeightDelta(error * sigDx);
  }
}

std::ostream& operator <<(std::ostream &out, const OutputLayer &layer)
{
  out << "___________________\n"
      << "Output layer information:\n"
      << "\tNeuron quantity: " << layer.getNeuronQuantity() << ";\n";

  size_t j = 0;
  for (const std::shared_ptr<Neuron>& neuron: layer.neurons_){
    out << "\tNeuron №" << j++ << ": \n\t" << *neuron << "\n";
  }
  out << "\n";
  return out;
}

double OutputLayer::getError(const std::vector<double> &expectedAnswer) const
{
  if (expectedAnswer.size() != neurons_.size()){
    throw std::invalid_argument("Wrong expected output data;");
  }
  double numerator = 0;
  for (size_t i = 0; i < neurons_.size(); i++){
    numerator += pow(expectedAnswer.at(i) - neurons_.at(i)->getOutput(), 2);
  }
  const double error = numerator / neurons_.size();
  return error;
}

double OutputLayer::getMaxImpulse() const
{
  double maxImpulse = neurons_.at(0)->getOutput();
  for (auto neuron = neurons_.begin() + 1; neuron != neurons_.end(); ++neuron){
    const double neuronImpulse = (*neuron)->getOutput();
    if (neuronImpulse > maxImpulse){
      maxImpulse = neuronImpulse;
    }
  }
  return maxImpulse;
}

double OutputLayer::getMaxImpulseIndex() const
{
  double maxImpulse = neurons_.at(0)->getOutput();
  double maxImpulseIndex = 0;

  for (size_t i = 1; i < neurons_.size(); i++){
    const double neuronImpulse = neurons_.at(i)->getOutput();
    if (neuronImpulse > maxImpulse){
      maxImpulse = neuronImpulse;
      maxImpulseIndex = i;
    }
  }
  return maxImpulseIndex;
}