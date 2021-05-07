#ifndef _STACKLIST_
#define _STACKLIST_
#include <iostream>
#include <fstream>
#include "TList.h"

using namespace std;

template <class T>
class TStackList
{
protected:
  TList<T> list;
public:
  TStackList();
  TStackList(TStackList<T>& _v);
  ~TStackList();
  
  TStackList<T>& operator =(TStackList<T>& _v);

  void Push(T d); //Вставка элемента
  T Get(); //Получение элемента

  int IsEmpty(void) const; // контроль пустоты
  int IsFull(void) const; //контроль переполнения

  //DOP
  T Min_elem();
  T Max_elem();
  void File();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TStackList<T1> &A);
  template <class T1>
  friend istream& operator>> (istream& istr, TStackList<T1> &A);

  int GetCount();
};

template<class T>
inline TStackList<T>::TStackList()
{
}

template<class T>
inline TStackList<T>::TStackList(TStackList<T>& _v)
{
  list = _v.list;
}

template<class T>
inline TStackList<T>::~TStackList()
{
}

template<class T>
inline TStackList<T>& TStackList<T>::operator=(TStackList<T>& _v)
{
  if (this == &_v)
  {
    return *this;
  }
  else
  {
    list = _v.list;
  }
  return *this;
}

template<class T>
inline void TStackList<T>::Push(T d)
{
  list.InsFirst(d); 
}

template<class T>
inline T TStackList<T>::Get()
{
  if (list.IsEmpty())
  {
    throw "Oshibka";
  }

  T tmp = list.GetFirst()->GetData();
  list.DelFirst();

  return tmp;
}

template<class T>
inline int TStackList<T>::IsEmpty(void) const
{
  return list.IsEmpty();
}

template<class T>
inline int TStackList<T>::IsFull(void) const
{
  return list.IsFull();
}

template<class T>
inline T TStackList<T>::Min_elem()
{
  int count = this->GetCount();
  T temp = NULL;
  for (int i = 0; i < count; i++)
  {
    if (temp == NULL)
    {
      temp = this->Get();
    }
    else
    {
      T temp_for = this->Get();
      if (temp_for < temp)
      {
        temp = temp_for;
      }
    }
  }
  return temp;
}

template<class T>
inline T TStackList<T>::Max_elem()
{
  int count = this->GetCount();
  T temp = NULL;
  for (int i = 0; i < count; i++)
  {
    if (temp == NULL)
    {
      temp = this->Get();
    }
    else
    {
      T temp_for = this->Get();
      if (temp_for > temp)
      {
        temp = temp_for;
      }
    }
  }
  return temp;
}

template<class T>
inline void TStackList<T>::File()
{
  ofstream outf("DataStack.txt");
  if (!outf)
  {
    throw "Oshibka file";
  }
  int temp = this->GetCount();
  for (int i = 0; i < temp; i++)
  {
    outf << this->Get() << endl;
  }
}

template<class T>
inline int TStackList<T>::GetCount()
{
  return list.GetCount();
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TStackList<T1>& A)
{
  return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TStackList<T1>& A)
{
  return istr >> A.list;
}

#endif