//
// Created by Богдан Полянок on 30.09.2017.
//

#include "inputLayer.hpp"


InputLayer::InputLayer(const size_t &neuronQuantity, const bool& hasBias):
  Layer(neuronQuantity),
  bias_(nullptr)
{
  if (hasBias){
    bias_ = std::make_shared<Neuron>();
    bias_->setInput(1);
    bias_->setOutput(1);
  }
}

void InputLayer::setInputData(const std::vector<double> &data)
{
  if (data.size() != neurons_.size()){
    throw std::invalid_argument("Wrong data size;");
  }
  for (size_t i = 0; i < neurons_.size(); i++){
    const double number = data.at(i);
    neurons_.at(i)->setInput(number);
    neurons_.at(i)->setOutput(number);
  }
}

bool InputLayer::hasBias() const
{
  return static_cast<bool>(bias_.get());
}

std::shared_ptr<Neuron> InputLayer::getBias() const
{
  return bias_;
}

void InputLayer::setWeights(const std::shared_ptr<Layer> &nextLayer)
{
  Layer::setWeights(nextLayer);
  if (hasBias()){
    bias_->setWeights(nextLayer->getNeuronQuantity());
  }
}

void InputLayer::changeWeights(const double& learningRate, const double& momentum, const std::shared_ptr<Layer>& nextLayer)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    neurons_.at(i)->setWeightDelta(neurons_.at(i)->countWeightDelta(nextLayer));
    neurons_.at(i)->changeWeights(learningRate, momentum, nextLayer);
  }
  if (hasBias()){
    getBias()->changeWeights(learningRate, momentum, nextLayer);
  }
}

double InputLayer::getTotalImpulse(const size_t &toNeuron) const
{
  double impulse = Layer::getTotalImpulse(toNeuron);
  if (hasBias()){
    impulse += getBias()->getWeight(toNeuron);
  }
  return impulse;
}

std::ostream& operator <<(std::ostream &out, const InputLayer &layer)
{
  out << "___________________\n"
      << "Input layer information:\n"
      << "\tNeuron quantity: " << layer.getNeuronQuantity() << ";\n";

  size_t j = 0;
  for (const std::shared_ptr<Neuron>& neuron: layer.neurons_){
    out << "\tNeuron №" << j++ << ": \n\t" << *neuron << "\n";
  }
  if (layer.hasBias()){
    out << "\tBias neuron: \n\t" << *layer.getBias();
  }
  out << "\n";
  return out;
}