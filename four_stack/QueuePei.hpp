#ifndef QUEUE_PEI
#define QUEUE_PEI

#include "../third_list/ListPei.hpp"

template <typename T>
class QueuePei: public ListPei<T>
{
public:
				void enqueue(T const &e)
				{
								this->insertAsLast(e);
				}
				T deQueue()
				{
								return this->remove(this->first());
				}

				T& front()
				{
								return this->first()->data;
				}
};

#endif
