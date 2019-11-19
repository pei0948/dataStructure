#include <iostream>
using namespace std;

#include <math.h>

#include <string>

#include "StackPei.hpp"
#include "BackTrack.hpp"

#include "QueueSim.hpp"

////////////////////////////////运算式解析/////////////////////////////
#define N_OPTR 9
const char pri[N_OPTR][N_OPTR]=
{
             //当前运算符
	//栈		//	+,  -,   *,   /,   ^,   !,    (,   ),  \0
 /* + */  	 '>', '>', '<', '<', '<', '<', '<', '>', '>',                               
 /* - */     '>', '>', '<', '<', '<', '<', '<', '>', '>',                               
 /* * */     '>', '>', '>', '>', '<', '<', '<', '>', '>',                                  
 /* / */     '>', '>', '>', '>', '<', '<', '<', '>', '>',                                       
 /* ^ */     '>', '>', '>', '>', '>', '<', '<', '>', '>',                                       
 /* ! */     '>', '>', '>', '>', '>', '>', '<', '>', '>',                                       
 /* ( */     '<', '<', '<', '<', '<', '<', '<', '=', ' ',                                      
 /* ) */     '<', '<', '<', '<', '<', '<', '<', '>', '>',                                       
 /* \0*/     '<', '<', '<', '<', '<', '<', '<', ' ', '='                                     
};



float calcu(float opn)
{
				if(opn==0)
								return 1;
				float product=1;
				while(opn!=0)
				{
								product=product*opn;
								opn--;
				}
				return product;
}

float calcu(float opnB, char opt, float opnA)
{
				
				switch(opt)
				{
								case '+':
												return (opnB+opnA);
								case '-':
												return (opnB-opnA);
								case '*':
												return (opnB*opnA);
								case '/':
												return (opnB/opnA);
								case '^':
												return pow(opnB, opnA);
				}
}

float readNum(const char * (&s))
{
				bool pointA=false;
				int numApoint=0;
				float num=0;
				while(true)
				{
								if(isdigit(*s))
								{	
												if(pointA)
																numApoint++;
												num=num*10+(*s-'0');

								}
								else
								{
												switch(*s)
												{
																case '.':
																				pointA=true;
																				break;
																case '+':
																case '-':
																case '*':
																case '/':
																case '^':
																case '\0':
																				return num/pow(10, numApoint);
												}
								}
								s++;
				}
}

int getIndexOpt(char opt)
{			
				int l;
				switch(opt)
				{
								case '+':
												l=0;
												break;
								case '-':
												l=1;
												break;
								case '*':
												l=2;
												break;
								case '/':
												l=3;
												break;
								case '^':
												l=4;
												break;
								case '!':
												l=5;
												break;
								case '(':
												l=6;
												break;
								case ')':
												l=7;
												break;
								case '\0':
												l=8;
												break;

				}
				return l;
}

char getPri(char optStack, char optCurr)
{
				int r,l;
				r=getIndexOpt(optStack);
				l=getIndexOpt(optCurr);
				return pri[r][l];

}

float evaluate(const char *s, string &prn)
{
				StackPei<float> opn;
				StackPei<char> opt;
				opt.push('\0');
				while(!opt.empty())
				{
								if(isdigit(*s))
								{
												float num=readNum(s);
												prn.append(to_string(num));
												opn.push(num);
								}
								else
								{
												switch(getPri(opt.top(), *s))//在switch case 中定义变量会报错,除非用大括号括起来	
												{
																case '>':
																				{
																					char optTemp=opt.pop();
																					prn.append(&optTemp);
																					if(optTemp=='!')
																					{
																									opn.push(calcu(opn.pop()));
																					}
																					else
																					{
																									float opn1=opn.pop();
																									float opn2=opn.pop();
																									opn.push(calcu(opn2, optTemp, opn1));
																					}
																				}
																				break;
																case '<':
																				opt.push(*s);
																				s++;
																				break;
																case '=':
																				opt.pop();
																				s++;
																				break;
																default:
																				exit(-1);
																				break;
												}	
								}
							
				}
				return opn.pop();
}

////////////////进制转换/////////////////////////////////////
void convert_r(StackPei<char> &sp, long long n, int base)
{
				if(n<=0)
								return;
				static char digit[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
				sp.push(digit[n%base]);
				convert_r(sp, n/base, base);
}

void convert_i(StackPei<char> &sp, long long n, int base)
{
				static char digit[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
				while(n>0)
				{
								sp.push(digit[n%base]);
								n=n/base;
				}
}

////////////////////////括号匹配/////////////////////////////////
void trim(const char exp[], int &lo, int &hi)
{
				while((lo<=hi) && (exp[lo]!='(') && (exp[lo]!=')'))
								lo++;
				while((lo<=hi) && (exp[hi]!=')') && (exp[hi]!='('))
								hi--;
}
int getDivid(const char exp[], int lo, int hi)
{
				int diff=1;
				for(int i=lo+1; i<=hi; i++)
				{
								if(exp[i]=='(')
												diff++;
								else if(exp[i]==')')
												diff--;
								
								if(diff==0)
												return i;
				}
				return lo-1;
}
bool paren_r(const char exp[], int lo, int hi)
{
				trim(exp, lo, hi);
				if(lo>hi)
								return true;
				if(exp[lo]==')')
								return false;
				if(exp[hi]=='(')
								return false;
				int mi=getDivid(exp, lo, hi);
				if(mi<lo)
								return false;
				return (paren_r(exp, lo+1, mi-1) && paren_r(exp, mi+1, hi));
}

bool paren_i(const char exp[], int lo, int hi)//栈很好用啊:1)可以记录入栈历史;2)可以先入后出
{
				StackPei<char> sp;
				for(int i=lo; i<=hi; i++)
				{
								switch(exp[i])
								{
												case '(':
												case '[':
												case '{':
																sp.push(exp[i]);
																break;

												case ')':
																if(sp.empty() || (sp.pop()!='('))
																{
																				return false;
																}
																break;
												case ']':
																if(sp.empty() || (sp.pop()!='['))
																{
																				return false;
																}
																break;
												case '}':
																if(sp.empty() || (sp.pop()!='{'))
																{
																				return false;
																}
																break;
												default:
																break;
								}
				}
				return sp.empty();
}



int main(int argc, char **argv)
{
				simulate(5, 24);
				return 0;
}
