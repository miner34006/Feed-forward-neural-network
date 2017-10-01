//
// Created by Богдан Полянок on 30.09.2017.
//

#include "layer.hpp"

using layerPtr = Layer::layerPtr;

Layer::Layer(const size_t &neuronQuantity):
  neurons_({})
{
  for (size_t i = 0; i < neuronQuantity; i++){
    neurons_.push_back(std::make_shared<Neuron>());
  }
}

Layer::Layer(const std::vector<std::shared_ptr<Neuron>>& neurons):
  neurons_(neurons)
{}

void Layer::setNeuronQuantity(const size_t& neuronQuantity)
{
  for (size_t i = 0; i < neuronQuantity; i++){
    neurons_.push_back(std::make_shared<Neuron>());
  }
}

size_t Layer::getNeuronQuantity() const
{
  return neurons_.size();
}

void Layer::setInputData(const std::vector<float> &data)
{
  for (size_t i = 0; i < neurons_.size(); i++){
    neurons_.at(i)->setInput(data.at(i));
  }
}

std::ostream& operator <<(std::ostream &out, const Layer &layer)
{
  out << "Layer information:\n"
    << "\tNeuron quantity: " << layer.getNeuronQuantity() << ";\n";

  size_t j = 0;
  for (const std::shared_ptr<Neuron>& neuron: layer.neurons_){
    out << "\tNeuron № " << j++ << ": " << *neuron << "\n";
  }
  out << "\n";
  return out;
}
