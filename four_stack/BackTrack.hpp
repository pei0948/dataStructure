#include <iostream>
using namespace std;

#include "StackPei.hpp"

////////////////////////////八皇后问题///////////////////
struct Queen
{
				int x=0,
						y=0;
				Queen(int xx=0, int yy=0):x(xx),y(yy)
				{}

				bool operator== (Queen const &q) const
				{
								return ((x==q.x) ||
												(y==q.y) ||
												(x+y==q.x+q.y) ||
												(y-x==q.y-q.x));
				}

				bool operator!= (Queen const &q) const
				{
								return !(*this==q);
				}
};

void placeQueen(StackPei<Queen> &qsp, int N)
{
				Queen q(0, 0);
				while(q.x < N || q.y <N)
				{
								if(q.y>=N)
								{
												q=qsp.pop();
												q.y++;
								}
								else
								{
												while((q.y<N) && (qsp.find(q)>=0))
												{
																q.y++;
												}
												
												if(q.y<N)
												{
																
																qsp.push(q);

																if(qsp.size()>=N)
																{
																				break;
																}
																q.x++;
																q.y=0;
												}
								}
				}
}

void printQueen(StackPei<Queen> &qsp, int N)//不用引用,在N=8时,最后一个出错,很奇怪的事情
{
				for(int r=0; r<N; r++)
				{

								Queen q=qsp.pop();
								for(int l=0; l<N; l++)
								{
												if(l==q.y)
												{
																cout<<'@'<<' ';
												}
												else
												{
																cout<<'*'<<' ';
												}
								}
								cout<<endl;
				}
}

////////////////////////////////////迷宫寻径//////////////////
typedef enum{available, routed, backward, wall} Status;
typedef enum{unKnown, east, south, west, north, noWay} ESWN;

#define LABY_SIZE 24

struct Cell
{
				int x,y;
				Status status;
				ESWN inDirection, outDirection;
};

inline ESWN nextDirection(ESWN direction)
{
				return ESWN(direction+1);
}

Cell* next(Cell *c)
{
				Cell *next;
				switch(c->outDirection)
				{
								case east:
												next=c+4;//一个int占4个字节,每个存储地址为1个字节
												next->inDirection=west;
												break;
								case south:
												next=c+LABY_SIZE*4;
												next->inDirection=north;
												break;
								case west:
												next=c-4;
												next->inDirection=east;
												break;
								case north:
												next=c-LABY_SIZE*4;
												next->inDirection=south;
												break;
				}
				return next;
}

bool laby(Cell cell[LABY_SIZE][LABY_SIZE], Cell *s, Cell *t)
{
				if((s->status!=available) || (t->status!=available))
				{
								return false;
				}
				s->status=routed;
				s->inDirection=unKnown;
				s->outDirection=unKnown;

				StackPei<Cell*> path;
				path.push(s);
				while(!path.empty())
				{
								Cell *c=path.top();
								if(c==t)
												return true;
								while(c->outDirection < noWay)
								{
												if((c->outDirection>unKnown) && (next(c)->status == available))
												{
																c=next(c);
																c->outDirection=unKnown;
																c->status=routed;
																path.push(c);
																break;
												}
												else
												{
																c->outDirection=nextDirection(c->outDirection);
												}
								}
								if(c->outDirection>=noWay)
								{
												c->status=backward;
												path.pop();
								}
				}
				return false;	
}
