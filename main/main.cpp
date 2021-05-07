#include <iostream>
//#include "TList.h"
//#include "Stack.h"
#include "Queue.h"

int main()
{
	TQueueList<int> s;
	s.Push(1);
	s.Push(7);
	s.Push(3);
	s.Push(5);

	cout << s.Get();
	cout << s.Get();
	cout << s.Get();
	cout << s.Get();
	//cout << s;

  //cout << s.Max_elem();

	return 0;
}
