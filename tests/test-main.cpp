#define BOOST_TEST_MAIN


#include <boost/test/included/unit_test.hpp>

#include "../neuron.hpp"
#include "../neuralNetwork.hpp"

BOOST_AUTO_TEST_SUITE(testNeuralNetwork)

  BOOST_AUTO_TEST_CASE(testGetNeuronQuantity)
  {
    NeuralNetwork neuralNetwork(0, 0, {1, 2, 4});

    BOOST_CHECK_EQUAL(neuralNetwork[0]->getNeuronQuantity(), 1);
    BOOST_CHECK_EQUAL(neuralNetwork[1]->getNeuronQuantity(), 2);
    BOOST_CHECK_EQUAL(neuralNetwork[2]->getNeuronQuantity(), 4);
  }

  BOOST_AUTO_TEST_CASE(testSetInputData)
  {
    NeuralNetwork neuralNetwork(0, 0, {3, 2, 4});
    neuralNetwork.setInputData({0, 1, 2});

    BOOST_CHECK_CLOSE((*neuralNetwork[0])[0]->getInput(), 0, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[0])[1]->getInput(), 1, 0.1);
    BOOST_CHECK_CLOSE((*neuralNetwork[0])[2]->getInput(), 2, 0.1);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testNeuron)

  BOOST_AUTO_TEST_CASE(testSetGetInput)
  {
    Neuron neuron;
    neuron.setInput(1);
    BOOST_CHECK_CLOSE(neuron.getInput(), 1, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testSetGetOutput)
  {
    Neuron neuron;
    neuron.setOutput(1);
    BOOST_CHECK_CLOSE(neuron.getOutput(), 1, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testActivation1)
  {
    Neuron neuron;
    neuron.setInput(1);
    neuron.activation();
    BOOST_CHECK_CLOSE(neuron.getOutput(), 0.731, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testActivation2)
  {
    Neuron neuron;
    neuron.setInput(10);
    neuron.activation();
    BOOST_CHECK_CLOSE(neuron.getOutput(), 0.999, 0.1);
  }

  BOOST_AUTO_TEST_CASE(testSetGetWeight)
  {
    Neuron neuron;
    neuron.setWeights(4);

    neuron.setWeight(0, 0);
    neuron.setWeight(1, 1);
    neuron.setWeight(2, 2);
    neuron.setWeight(3, 3);

    BOOST_CHECK_CLOSE(neuron.getWeight(0), 0, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(1), 1, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(2), 2, 0.1);
    BOOST_CHECK_CLOSE(neuron.getWeight(3), 3, 0.1);
  }

BOOST_AUTO_TEST_SUITE_END()
