//
// Created by Богдан Полянок on 30.09.2017.
//

#include "neuron.hpp"

Neuron::Neuron(const size_t& nextLayerNeuronQuantity):
  forwardWeights_({}),
  input_(0),
  output_(0)
{
  srand(time(NULL));
  for (size_t i = 0; i<nextLayerNeuronQuantity; i++){
    const float randomWeight = ((float) random() / (RAND_MAX));
    forwardWeights_.push_back(randomWeight);
  }
}

Neuron::Neuron(const float &input, const std::vector<float>& forwardWeights):
  forwardWeights_(forwardWeights),
  input_(input),
  output_(0)
{
  setOutput(activation());
}

float Neuron::activation() const
{
  const float sigmoid = 1 / (1 + exp(-getInput()));
  return sigmoid;
}

void Neuron::setInput(const float &input)
{
  input_=input;
}

void Neuron::setOutput(const float &output)
{
  output_=output;
}

float Neuron::getInput() const
{
  return input_;
}

float Neuron::getOutput() const
{
  return output_;
}

void Neuron::setWeights(const size_t& nextLayerNeuronQuantity)
{
  srand(time(NULL));
  for (size_t i = 0; i<nextLayerNeuronQuantity; i++){
    const float randomWeight = ((float) random() / (RAND_MAX));
    forwardWeights_.push_back(randomWeight);
  }
}

std::vector<float> Neuron::getWeights()
{
  return forwardWeights_;
}

std::ostream& operator<<(std::ostream &out, const Neuron &neuron)
{
  out << "Neuron information:\n"
    << "\tinput: " << neuron.getInput() << "\n"
    << "\toutput: "  << neuron.getOutput() << "\n"
    << "\tweights: ";

  for (const float& weight: neuron.forwardWeights_){
    out << weight << " ";
  }
  out << "\n";
  return out;
}
