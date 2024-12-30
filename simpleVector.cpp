#include "simpleVector.h"
#include <iostream>

using namespace std;

template <typename Element>
SimpleVector<Element>::SimpleVector()
{
	s_vec = new Element[10];
	cnt=0;
	space = 10;
}

template <typename Element>
SimpleVector<Element>::SimpleVector(int length)
{
	s_vec = new Element[length];
	cnt=0;
	space = length;
}

template <typename Element>
SimpleVector<Element>::~SimpleVector()
{
	delete[] s_vec;
	cnt=0;
	space = 0;
}

template <typename Element>
void SimpleVector<Element>::push_back(Element val)
{
	if(cnt<space)
	{
		s_vec[cnt]=val;
		cnt++;
	}
}
/*
template <typename Element>
void SimpleVector<Element>::pop_back()
{
//	Element* after_vec = new Element[length];
	if(cnt>0)
	{
		delete s_vec[cnt];
		cnt--;
	}
}

template <typename Element>
int SimpleVector<Element>::size()
{
	return cnt;
}

template <typename Element>
int SimpleVector<Element>::capacity()
{
	return space;
}
*/
