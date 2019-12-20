#ifndef GRAPH_PEI
#define GRAPH_PEI

#include <iostream>
using namespace std;

#include <limits.h>
#include <algorithm>

#include "../four_stack/StackPei.hpp"
#include "../four_stack/QueuePei.hpp"

typedef enum{UNDISCOVERED, DISCOVERED, VISITED} Vstatus;
typedef enum{UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} Etype;

template <typename Tv, typename Te>
class GraphPei
{
				private:
								void reset()
								{
												for(int i=0; i<v; i++)
												{
																this->getVstatus(i)=UNDISCOVERED;
																this->getDtime(i)=this->getFtime(i)=-1;
																this->getParent(i)=-1;
																this->getPriority(i)=INT_MAX;

																for(int j=0; j<v; j++)
																{
																				if(this->exist(i, j))
																				{
																								this->getEtype(i, j)=UNDETERMINED;
																				}
																}
												}
								}

								void BFS(int, int&);
								void DFS(int, int&);
								void BCC(int, int&, StackPei<int>&);
								bool TSort(int, int&, StackPei<Tv>*);

								template <typename PU>
								void PFS(int, PU&);

				public:
								int v;
								virtual int insert(Tv const&)=0;
								virtual Tv remove(int)=0;
								virtual Tv& vertex(int)=0;
								virtual int getInDegree(int)=0;
								virtual int getOutDegree(int)=0;
								virtual int firstNbr(int)=0;
								virtual int nextNbr(int, int)=0;
								virtual Vstatus& getVstatus(int)=0;
								virtual int& getDtime(int)=0;
								virtual int& getFtime(int)=0;
								virtual int& getParent(int)=0;
								virtual int& getPriority(int)=0;

								int e;
								virtual bool exist(int, int)=0;
								virtual void insert(Te const&, int, int, int)=0;
								virtual Te remove(int, int)=0;
								virtual Etype& getEtype(int, int)=0;
								virtual Te& getEdge(int, int)=0;
								virtual int& getWeight(int, int)=0;

								void bfs(int);
								void dfs(int);
								void bcc(int);
								StackPei<Tv>* tSort(int);
								void prim(int);
								void dijkstra(int);

								template <typename PU>
								void pfs(int, PU&);
};

template <typename Tv, typename Te>
void GraphPei<Tv, Te>::bfs(int start)
{
				this->reset();
				int clock=0;
				int travV=start;
				do{
								if(this->getVstatus(travV) == UNDISCOVERED)
								{
												BFS(travV, clock);
								}
								travV++;
				}while(start != (travV%v));
}

template <typename Tv, typename Te>
void GraphPei<Tv, Te>::BFS(int travV, int &clock)
{
				QueuePei<int> qp;
				qp.enqueue(travV);
				while(!qp.empty())
				{
								int vTemp=qp.deQueue();
								this->getDtime(vTemp)=++clock;
								for(int iV=this->firstNbr(vTemp); iV>-1; iV=nextNbr(vTemp, iV))
								{
												if(this->getVstatus(iV)==UNDISCOVERED)
												{
																qp.enqueue(iV);
																this->getVstatus(iV)=DISCOVERED;
																this->getEtype(vTemp, iV)=TREE;
																this->getParent(iV)=vTemp;
												}
												else
												{
																this->getEtype(vTemp, iV)=CROSS;
												}
								}
								this->getVstatus(vTemp)=VISITED;
								cout<<this->vertex(vTemp)<<endl;
				}
}

template <typename Tv, typename Te>
void GraphPei<Tv, Te>::dfs(int start)
{
				int clock=0;
				int vTrav=start;
				do
				{
								if(this->getVstatus(vTrav)==UNDISCOVERED)
								{
												DFS(vTrav, clock);
								}
								vTrav++;
								vTrav=vTrav%v;
				}while(start!=vTrav);
}
template <typename Tv, typename Te>
void GraphPei<Tv, Te>::DFS(int vTrav, int &clock) 
{
				this->getVstatus(vTrav)=DISCOVERED;
				clock++;
				this->getDtime(vTrav)=clock;
				for(int vTemp=this->firstNbr(vTrav); vTemp>-1; vTemp=nextNbr(vTrav, vTemp))
				{
								switch(this->getVstatus(vTemp))
								{
												case UNDISCOVERED:
																this->getEtype(vTrav, vTemp)=TREE;
																this->getParent(vTemp)=vTrav;
																DFS(vTemp, clock);
																break;
												case DISCOVERED:
																this->getEtype(vTrav, vTemp)=BACKWARD;
																break;
												default:
																this->getEtype(vTrav, vTemp)=
																				(this->getDtime(vTrav) > this->getDtime(vTemp))? CROSS:FORWARD;
																break;
								}
				}
				this->getVstatus(vTrav)=VISITED;
				this->getFtime(vTrav)=++clock;
				cout<<this->vertex(vTrav)<<endl;
}

template <typename Tv, typename Te>
StackPei<Tv>* GraphPei<Tv, Te>::tSort(int start)
{
				this->reset();
				StackPei<Tv> *sp=new StackPei<Tv>();
				int clock=0;
				int vTemp=start;
				do{

								if(this->getVstatus(vTemp)==UNDISCOVERED)
								{
												bool sorted=TSort(vTemp, clock, sp);
												if(!sorted)
												{
																return NULL;
												}
								}
								vTemp++;
								vTemp=vTemp%v;
				}while(start != vTemp);
				return sp;
}
template <typename Tv, typename Te>
bool GraphPei<Tv, Te>::TSort(int vTemp, int &clock, StackPei<Tv> *sp)
{
				clock++;
				this->getDtime(vTemp)=clock;
				this->getVstatus(vTemp)=DISCOVERED;
				for(int iv=this->firstNbr(vTemp); iv>-1; iv=nextNbr(vTemp, iv))
				{
								switch(this->getVstatus(iv))
								{
												case UNDISCOVERED:
																this->getParent(iv)=vTemp;
																this->getEtype(vTemp, iv)=TREE;
																if(!TSort(iv, clock, sp))
																				return false;
																break;
												case DISCOVERED:
																this->getEtype(vTemp, iv)=BACKWARD;
																return false;
												default:
																this->getEtype(vTemp, iv)=
																				(this->getDtime(vTemp)>= this->getDtime(iv))? CROSS:FORWARD;
																break;
								}
				}
				this->getVstatus(vTemp)=VISITED;
				sp->push(this->vertex(vTemp));
				return true;
}

template <typename Tv, typename Te>
void GraphPei<Tv, Te>::bcc(int start)
{
				int vTemp=start;
				StackPei<int> sp;
				int clock=0;
				this->reset();
				do{
								if(this->getVstatus(vTemp)==UNDISCOVERED)
								{
												BCC(vTemp, clock, sp);
												sp.pop();
								}

								vTemp++;
								vTemp=vTemp%v;
				}while(start != vTemp);
}

#define hca(x) (getFtime(x))
template <typename Tv, typename Te>
void GraphPei<Tv, Te>::BCC(int vTemp, int &clock, StackPei<int> &sp)
{
				clock++;
				this->getFtime(vTemp)=clock;
				this->getDtime(vTemp)=clock;

				this->getVstatus(vTemp)=DISCOVERED;
				sp.push(vTemp);
				for(int iv=this->firstNbr(vTemp); iv>-1; iv=nextNbr(vTemp, iv))
				{
								switch(this->getVstatus(iv))
								{
												case UNDISCOVERED:
																this->getEtype(vTemp, iv)=TREE;
																this->getParent(iv)=vTemp;
																BCC(iv, clock, sp);
																if(hca(iv)<this->getDtime(vTemp))
																{
																				hca(vTemp)=min(hca(iv), hca(vTemp));
																}
																else
																{
																				int vDomin;
																				do{
																								vDomin=sp.pop();
																				}while(vDomin!=vTemp);
																				cout<<this->vertex(vTemp)<<endl;
																				sp.push(vTemp);
																}
																break;
												case DISCOVERED:
																this->getEtype(vTemp, iv)=BACKWARD;
																if(this->getParent(vTemp)!=iv)
																				hca(vTemp)=min(hca(vTemp), this->getDtime(iv));
																break;
												default:
																this->getEtype(vTemp, iv)=
																				(this->getDtime(vTemp) < this->getDtime(iv))? FORWARD:CROSS;
																break;
								}
				}
				this->getVstatus(vTemp)=VISITED;
}
#undef hca

template <typename Tv, typename Te>
template <typename PU>
void GraphPei<Tv, Te>::pfs(int start, PU &prioUp)
{
			  this->reset();
				int vTemp=start;
				do{
								if(this->getVstatus(vTemp)==UNDISCOVERED)
								{
												PFS(vTemp, prioUp);
								}
								vTemp++;
								vTemp=vTemp%v;
				}while(start!=vTemp);
}

template <typename Tv, typename Te>
template <typename PU>
void GraphPei<Tv, Te>::PFS(int vTemp, PU &prioUp)
{
				this->getPriority(vTemp)=0;
				this->getVstatus(vTemp)=VISITED;
				cout<<this->vertex(vTemp)<<endl;
				while(1)
				{
								for(int vNbr=firstNbr(vTemp); vNbr>-1; vNbr=nextNbr(vTemp, vNbr))
								{
												prioUp(this, vTemp, vNbr);
											//	cout<<this->vertex(vNbr)<<" "<<this->getPriority(vNbr)<<endl;
								}
//								cout<<endl;
								int shortest=INT_MAX;
								for(int vNbr=0; vNbr<v; vNbr++)
								{
												if(this->getVstatus(vNbr)==UNDISCOVERED)
												{
																if(this->getPriority(vNbr)<shortest)
																{
																				shortest=this->getPriority(vNbr);
																				vTemp=vNbr;
																}
												}
								}
								if(this->getVstatus(vTemp)==VISITED)
												break;

								this->getEtype(this->getParent(vTemp), vTemp)=TREE;
								this->getVstatus(vTemp)=VISITED;
								cout<<this->vertex(vTemp)<<endl;
				}
}

template <typename Tv, typename Te>
struct PU_PRIM
{
				virtual void operator() (GraphPei<Tv, Te> *graph, int uk, int vTemp)
				{
								if(graph->getVstatus(vTemp)==UNDISCOVERED)
								{
												if(graph->getPriority(vTemp)>graph->getWeight(uk, vTemp))
												{
																graph->getPriority(vTemp)=graph->getWeight(uk, vTemp);
																graph->getParent(vTemp)=uk;
												}
								}
				}
};

template <typename Tv, typename Te>
struct PU_DIJISTRA
{
				virtual void operator() (GraphPei<Tv, Te> *graph, int uk, int vTemp)
				{
								if(graph->getVstatus(vTemp)==UNDISCOVERED)
								{
												if(graph->getPriority(vTemp)>graph->getPriority(uk)+graph->getWeight(uk, vTemp))
												{
																graph->getPriority(vTemp)=graph->getPriority(uk)+graph->getWeight(uk, vTemp);
																graph->getParent(vTemp)=uk;
												}
								}
				}
};

#endif
