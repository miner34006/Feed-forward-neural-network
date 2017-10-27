//
// Created by Богдан Полянок on 30.09.2017.
//

#include "neuron.hpp"


void Neuron::activation()
{
  const double sigmoid = 1 / (1 + exp(-getInput()));
  output_ = sigmoid;
}

void Neuron::setInput(const double &input)
{
  input_=input;
}

void Neuron::setOutput(const double &output)
{
  output_=output;
}

double Neuron::getInput() const
{
  return input_;
}

double Neuron::getOutput() const
{
  return output_;
}

void Neuron::setWeight(const size_t &index, const double &value)
{
  forwardWeights_.at(index) = value;
}

void Neuron::setWeights(const size_t& nextLayerNeuronQuantity)
{
  for (size_t i = 0; i<nextLayerNeuronQuantity; i++){
    const double randomWeight = ((double) random() / (RAND_MAX)) * 2 - 1;
    forwardWeights_.push_back(randomWeight);
    previousWeightDelta.push_back(0);
  }
}

double Neuron::getWeight(const size_t &index) const
{
  return forwardWeights_.at(index);
}

void Neuron::setWeightDelta(const double &weightDelta)
{
  weightDelta_ = weightDelta;
}

double Neuron::getWeightDelta() const
{
  return weightDelta_;
}

double Neuron::getPreviousDelta(const size_t& index)
{
  return previousWeightDelta.at(index);
}

void Neuron::setPreviousDelta(const size_t &index, const double &delta)
{
  previousWeightDelta.at(index) = delta;
}

std::ostream& operator<<(std::ostream &out, const Neuron &neuron)
{
  out << "Neuron information:\n"
      << "\tinput: " << neuron.getInput() << "\n"
      << "\toutput: "  << neuron.getOutput() << "\n"
      << "\tweightDelta_: "  << neuron.getWeightDelta() << "\n"
      << "\tweights: ";

  for (const double& weight: neuron.forwardWeights_){
    out << weight << " ";
  }
  out << "\n";
  return out;
}
