//
// Created by Богдан Полянок on 30.09.2017.
//

#include "layer.hpp"

#include "../neuron.hpp"


Layer::Layer(const size_t &neuronQuantity)
{
  for (size_t i = 0; i < neuronQuantity; i++){
    neurons_.push_back(std::make_shared<Neuron>());
  }
}

size_t Layer::getNeuronQuantity() const
{
  return neurons_.size();
}

void Layer::setInputData(const std::vector<double> &data)
{
  if (data.size() != neurons_.size()){
    throw std::invalid_argument("Wrong data size;");
  }
  for (size_t i = 0; i < neurons_.size(); i++){
    neurons_.at(i)->setInput(data.at(i));
  }
}

double Layer::getTotalImpulse(const size_t &toNeuron) const
{
  double impulse = 0;
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double input = (*this).neurons_.at(i)->getOutput();
    const double weight = (*this).neurons_.at(i)->getWeight(toNeuron);
    impulse += (input * weight);
  }
  return impulse;
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

std::shared_ptr<Neuron> Layer::operator[](const size_t &neuronIndex)
{
  return neurons_.at(neuronIndex);
}

void Layer::setWeights(const std::shared_ptr<Layer> &nextLayer)
{
  const size_t linksQuantity = nextLayer->getNeuronQuantity();
  for (const std::shared_ptr<Neuron>& neuron: neurons_){
    neuron->setWeights(linksQuantity);
  }
}

std::shared_ptr<Neuron> Layer::getBias() const
{
  return nullptr;
}

bool Layer::hasBias() const
{
  return false;
}
