#include <iostream>
#include <vector>

#include "src/training/xorTraining.hpp"
#include "src/neuralNetwork/neuralNetwork.hpp"

void func(const double& number){
  if (number >= 0.5){
    std::cout << "true " << "(" << number << ")";
  }
  if (number < 0.5){
    std::cout << "false " << "(" << number << ")";
  }
}

bool func1(char *Word,char *Mask)
{
  int MaskLength;
  bool *OldColumn;
  bool *CurrentColumn;
  bool result;
  int y;

  if((Mask[0]!='?')&&(Mask[0]!='*')&&(Mask[0]!=Word[0]))
    return false;
  MaskLength=0;
  while(Mask[MaskLength])
    MaskLength++;
  CurrentColumn=new bool[MaskLength];
  OldColumn=new bool[MaskLength];
  CurrentColumn[0]=true;
  for(y=1;y<MaskLength;y++)
    CurrentColumn[y]=false;
  Word++;
  while(*Word)
  {
    delete[] OldColumn;
    OldColumn=CurrentColumn;
    CurrentColumn=new bool[MaskLength];
    CurrentColumn[0]=(Mask[0]=='*');
    for(y=1;y<MaskLength;y++)
    {
      CurrentColumn[y]=false;
      if(Mask[y]=='*')
        CurrentColumn[y]=OldColumn[y] || OldColumn[y-1] || CurrentColumn[y-1];
      if(Mask[y]==*Word)
        CurrentColumn[y]=OldColumn[y-1];
      if(Mask[y]=='?')
        CurrentColumn[y]=OldColumn[y-1];
    }
    Word++;
  }
  result=CurrentColumn[MaskLength-1];
  delete[] CurrentColumn;
  return result;
}

int main() {
  srandom((unsigned)time(nullptr));

  const bool hasBias = true;
  std::shared_ptr<NeuralNetwork> neuralNetwork(new NeuralNetwork({2, 2, 1}, hasBias));

  double data = neuralNetwork->feedForward({0, 0});
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1});
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0});
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1});
  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  std::cout << "\n\n";

  XORTraining xorTrainer(neuralNetwork, 0.7, 0.7);
  xorTrainer.train(10000);
  std::cout << "TRAINING\n\n\n";

  data = neuralNetwork->feedForward({0, 0});
  std::cout << "false xor false = "; func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({0, 1});
  std::cout << "false xor true = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 0});
  std::cout << "true xor false = ";  func(data); std::cout << "\n";

  data = neuralNetwork->feedForward({1, 1});
  std::cout << "true xor true = ";   func(data); std::cout << "\n";

  return 0;
}