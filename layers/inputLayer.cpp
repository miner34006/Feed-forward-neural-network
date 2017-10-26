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
  const size_t linksQuantity = nextLayer->getNeuronQuantity();
  for (const std::shared_ptr<Neuron>& neuron: neurons_){
    neuron->setWeights(linksQuantity);
  }
  if (hasBias()){
    bias_->setWeights(linksQuantity);
  }
}

void InputLayer::error(const double &expected,
                       const double& learningRate,
                       const double& alpha,
                       const std::shared_ptr<Layer>& nextLayer)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double sigDx = neurons_.at(i)->getOutput() * (1 - neurons_.at(i)->getOutput());

    double sum = 0;
    for (size_t j = 0; j < nextLayer->getNeuronQuantity(); j++){
      double delta = (*nextLayer)[j]->getWeightDelta() * neurons_.at(i)->getWeight(j);
      sum += delta;
    }

    const double weightDelta = sigDx * sum;
    neurons_.at(i)->setWeightDelta(weightDelta);

    for (size_t j = 0; j < nextLayer->getNeuronQuantity(); j++){
      const double delta = (*nextLayer)[j]->getWeightDelta();
      const double gradient = neurons_.at(i)->getOutput() * delta;

      const double deltaW = learningRate * gradient + alpha * neurons_.at(i)->getPreviousDelta(j);
      neurons_.at(i)->setPreviousDelta(j, deltaW);
      neurons_.at(i)->setWeight(j, neurons_.at(i)->getWeight(j) + deltaW);
    }
  }

  if (hasBias()){
    for (size_t j = 0; j < nextLayer->getNeuronQuantity(); j++){
      const double delta = (*nextLayer)[j]->getWeightDelta();
      const double gradient = getBias()->getOutput() * delta;

      const double deltaW = learningRate * gradient + alpha * getBias()->getPreviousDelta(j);
      getBias()->setPreviousDelta(j, deltaW);
      getBias()->setWeight(j, getBias()->getWeight(j) + deltaW);
    }
  }
}