#ifndef GRAPHMATRIX_PEI
#define GRAPHMATRIX_PEI

#include "../second_vector/VectorPei.hpp"
#include "GraphPei.hpp"
//////////////////////////////////INT_MAX///////////////
#include <limits.h>

#include <cstddef>

template <typename Tv>
struct VertexPei
{
				Tv data;
				int inDegree;
				int outDegree;
				Vstatus status;

				int dTime, fTime;
				int parent;
				int priority;

				VertexPei(Tv const &d = (Tv)0):data(d),
																			inDegree(0),
																			outDegree(0),
																			status(UNDISCOVERED),
																			dTime(-1),
																			fTime(-1),
																			parent(-1),
																			priority(INT_MAX)
				{}
};

template <typename Te>
struct EdgePei
{
				Te data;
				int weight;
				Etype type;

				EdgePei(Te const &d=(Te)0, int w=INT_MAX):data(d),
																weight(w),
																type(UNDETERMINED)
				{}
};

template <typename Tv, typename Te>
class GraphMatrixPei: public GraphPei<Tv, Te>
{
				private:
								VectorPei<VertexPei<Tv>> vvp;
								VectorPei<VectorPei<EdgePei<Te>*>> vvep;

				public:
								GraphMatrixPei()
								{
												this->v=this->e=0;
								}
								~GraphMatrixPei()
								{
												for(int i=0; i<this->v; i++)
																for(int j=0; j<this->v; j++)
																				delete this->vvep[i][j];
								}

								virtual Tv& vertex(int i)
								{
												return vvp[i].data;
								}
								virtual int getInDegree(int i)
								{
												return vvp[i].inDegree;
								}
								virtual int getOutDegree(int i)
								{
												return vvp[i].outDegree;
								}
								virtual int firstNbr(int i)
								{
												return nextNbr(i, this->v);
								}
								virtual int nextNbr(int i, int j)
								{
												j--;
												while((j>-1) && !exist(i, j))
																j--;
												return j;
								}
								virtual Vstatus& getVstatus(int i)
								{
												return vvp[i].status;
								}
								virtual int& getFtime(int i)
								{
												return vvp[i].fTime;
								}
								virtual int& getDtime(int i)
								{
												return vvp[i].dTime;
								}
								virtual int& getParent(int i)
								{
												return vvp[i].parent;
								}
								virtual int& getPriority(int i)
								{
												return vvp[i].priority;
								}

								virtual int  insert(Tv const &vtp)
								{
												for(int i=0; i<this->v; i++)
												{
																EdgePei<Te> *edgeTemp=new EdgePei<Te>();
																vvep[i].insert(edgeTemp);
												}
												this->v++;
												VectorPei<EdgePei<Te>*> vp;
												for(int i=0; i<this->v; i++)
												{
																EdgePei<Te> *edgeTemp=new EdgePei<Te>();
																vp.insert(edgeTemp);
												}
												vvep.insert(vp);
												//vvep.insert(VectorPei<EdgePei<Te>*>(this->v, this->v, (EdgePei<Te>*)NULL));
												return vvp.insert(VertexPei<Tv>(vtp));
								}

								virtual void insert(Te const &edgeD, int w,int i, int j)
								{
												if(exist(i, j))
																return;
												EdgePei<Te> *edgeTemp=new EdgePei<Te>(edgeD, w);
												vvep[i].insert(j, edgeTemp);
												this->e++;
												vvp[i].outDegree++;
												vvp[j].inDegree++;
								}

								virtual Tv remove(int i)
								{

												Tv dataI=vertex(i);
												vvp.remove(i);
												this->v--;
												for(int j=0; j<this->v; j++)
												{
																if(exist(i, j))
																				vvp[j].inDegree--;

																EdgePei<Te> *edgeTemp=vvep[j].remove(i);
																if(edgeTemp)
																				vvp[j].outDegree--;
												}
												
												vvep.remove(i);
												return dataI;
								}

								virtual Te remove(int i, int j)
								{
												if(!exist(i, j))
																	return (Te) NULL;
												Te edgeD=vvep[i][j]->data;
												vvep[i][j]=NULL;
												this->e--;
												vvp[i].outDegree--;
												vvp[j].inDegree--;
												return edgeD;
								}

								virtual bool exist(int i, int j)
								{
												return (i>=0) && (i<this->v) &&
																(j>=0) && (j<this->v) &&
																(getWeight(i, j) != INT_MAX);
								}

								virtual Etype& getEtype(int i, int j)
								{
												return vvep[i][j]->type;
								}

								virtual Te& getEdge(int i, int j)
								{
												return vvep[i][j]->data;
								}

								virtual int& getWeight(int i, int j)
								{
												return vvep[i][j]->weight;
								}

};

#endif
