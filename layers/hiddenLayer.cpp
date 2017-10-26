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
  static_cast<bool>(bias_.get());
}

std::shared_ptr<Neuron> HiddenLayer::getBias() const
{
  return bias_;
}

void HiddenLayer::setWeights(const std::shared_ptr<Layer> &nextLayer)
{
  const size_t linksQuantity = nextLayer->getNeuronQuantity();
  for (const std::shared_ptr<Neuron>& neuron: neurons_){
    neuron->setWeights(linksQuantity);
  }
  if (hasBias()){
    bias_->setWeights(linksQuantity);
  }
}

void HiddenLayer::error(const double& expected,
                        const double& learningRate,
                        const double& alpha,
                        const std::shared_ptr<Layer>& nextLayer)
{
  for (size_t i = 0; i < getNeuronQuantity(); i++){
    const double sigDx = neurons_.at(i)->getOutput() * (1 - neurons_.at(i)->getOutput());

    double sum = 0;
    for (size_t j = 0; j < nextLayer->getNeuronQuantity(); j++){
      const double delta = (*nextLayer)[j]->getWeightDelta() * neurons_.at(i)->getWeight(j);
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
