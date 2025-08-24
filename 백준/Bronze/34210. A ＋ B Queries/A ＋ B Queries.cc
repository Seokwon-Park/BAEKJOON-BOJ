#include "aplusb.h"

std::vector<int> vecA;
std::vector<int> vecB;

void initialize(std::vector<int> A, std::vector<int> B) {
  vecA = A;
  vecB = B;
}

int answer_question(int i, int j) {
  return vecA[i] + vecB[j];
}