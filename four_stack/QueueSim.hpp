#include <stdlib.h>

#include <iostream>
using namespace std;

#include "QueuePei.hpp"

struct Customer
{
				int window;
				unsigned int serveTime;
};


int getBestWin(QueuePei<Customer> *queue, int nWin)
{
				int optWin=0;
				int optWinSize=queue[0].size();

				for(int n=1; n<nWin; n++)
				{
								int winSize=queue[n].size();
								if(optWinSize>winSize)
								{
												optWinSize=winSize;
												optWin=n;
								}
				}
				return optWin;
}

void simulate(int nWin, unsigned int servTime)
{
				QueuePei<Customer> *queue=new QueuePei<Customer>[nWin];
				for(int now=0; now<servTime; now++)
				{
								if(rand()%(1+nWin))
								{
												Customer customer;
												customer.serveTime=rand()%24;
												customer.window=getBestWin(queue, nWin);
												queue[customer.window].enqueue(customer);
								}
								for(int n=0; n<nWin; n++)
								{
												if(!queue[n].empty())
												{
																queue[n].front().serveTime--;
																if(queue[n].front().serveTime<=0)
																{
																				queue[n].deQueue();
																}
												}


												cout<<queue[n].size()<<" ";
								}
								cout<<endl;
				}
				delete []queue;
}
