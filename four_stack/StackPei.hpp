#ifndef STACK_PEI
#define STACK_PEI

#include "../second_vector/VectorPei.hpp"

template <typename T>
class StackPei: public VectorPei<T>
{
				public:
								void push(T const &e)
								{
												this->insert(e);
								}
								T pop()
								{
												return this->remove(this->_size-1);
								}
								T& top()
								{
												return (*this)[this->_size-1];
								}
};

#endif
