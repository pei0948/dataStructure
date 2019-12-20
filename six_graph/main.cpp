#include <iostream>
using namespace std;

#include "GraphMatrixPei.hpp"

int main(int argc, char **argv)
{
				GraphMatrixPei<char, int> graphM;
				graphM.insert('A');
				graphM.insert('B');
				graphM.insert('C');
				graphM.insert('D');
				graphM.insert('E');
				graphM.insert('F');
				graphM.insert('G');
				graphM.insert('H');

				graphM.getWeight(0, 1)=4;
				graphM.getWeight(1, 0)=4;
				graphM.getWeight(0, 6)=7;
				graphM.getWeight(6, 0)=7;
				graphM.getWeight(0, 3)=6;
				graphM.getWeight(3, 0)=6;

				graphM.getWeight(1, 2)=12;
				graphM.getWeight(2, 1)=12;

				graphM.getWeight(2, 3)=9;
				graphM.getWeight(3, 2)=9;
				graphM.getWeight(2, 4)=1;
				graphM.getWeight(4, 2)=1;
				graphM.getWeight(2, 5)=2;
				graphM.getWeight(5, 2)=2;
				graphM.getWeight(2, 7)=10;
				graphM.getWeight(7, 2)=10;

				graphM.getWeight(3, 6)=2;
				graphM.getWeight(6, 3)=2;
				graphM.getWeight(3, 4)=13;
				graphM.getWeight(4, 3)=13;

				graphM.getWeight(4, 5)=5;
				graphM.getWeight(5, 4)=5;
				graphM.getWeight(4, 6)=11;
				graphM.getWeight(6, 4)=11;
				graphM.getWeight(4, 7)=8;
				graphM.getWeight(7, 4)=8;


				graphM.getWeight(5, 7)=7;
				graphM.getWeight(7, 5)=7;

				graphM.getWeight(6, 7)=14;
				graphM.getWeight(7, 6)=14;

				PU_DIJISTRA<char, int> pu;
				graphM.pfs(0, pu);
				return 0;
}
