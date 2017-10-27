//
// Created by Богдан Полянок on 30.09.2017.
//

#include "hiddenLayer.hpp"


HiddenLayer::HiddenLayer(const size_t &neuronQuantity, const bool& hasBias):
  Layer(neuronQuantity),
  bias_(nullptr)
{
  if (hasBias){
    bias_ = std::make_shared<Neuron>();
    bias_->setInput(1);
    bias_->setOutput(1);
  }
}

bool HiddenLayer::hasBias() const
{
  return static_cast<bool>(bias_.get());
}

std::shared_ptr<Neuron> HiddenLayer::getBias() const
{
  return bias_;
}

void HiddenLayer::setWeights(const std::shared_ptr<Layer> &nextLayer)
{
  Layer::setWeights(nextLayer);
  if (hasBias()){
    bias_->setWeights(nextLayer->getNeuronQuantity());
  }
}

void HiddenLayer::changeWeights(const double& learningRate, const double& momentum, const std::shared_ptr<Layer>& nextLayer)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    neurons_.at(i)->setWeightDelta(neurons_.at(i)->countWeightDelta(nextLayer));
    neurons_.at(i)->changeWeights(learningRate, momentum, nextLayer);
  }
  if (hasBias()){
    getBias()->changeWeights(learningRate, momentum, nextLayer);
  }
}

double HiddenLayer::getTotalImpulse(const size_t &toNeuron) const
{
  double impulse = Layer::getTotalImpulse(toNeuron);
  if (hasBias()){
    impulse += getBias()->getWeight(toNeuron);
  }
  return impulse;
}

std::ostream& operator <<(std::ostream &out, const HiddenLayer &layer)
{
  out << "___________________\n"
      << "Hidden layer information:\n"
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
