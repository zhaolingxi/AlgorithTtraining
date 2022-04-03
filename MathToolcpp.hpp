#include"MathTool.h"

template<typename T>
inline void Swap(T &t1, T &t2)
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}