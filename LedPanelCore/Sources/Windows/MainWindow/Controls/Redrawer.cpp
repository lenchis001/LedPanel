#include "Redrawer.h"



void Redrawer::Notify()
{
	_delegateFunction();
}

Redrawer::Redrawer(std::function<void()> delegateFunction)
{
	_delegateFunction = delegateFunction;
}

Redrawer::~Redrawer()
{
}
