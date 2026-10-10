#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}

		OriginalArray[Index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize == _Size || NewSize < 0)
			return;

		_TempArray = new T[NewSize];
		for (int i = 0; i < _Size && i < NewSize; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		if (Index >= _Size || Index < 0)
			return T();

		return OriginalArray[Index];
	}

	void Reverse()
	{
		if (_Size <= 1)
			return;
		T temp;
		for (int i = 0; i < _Size / 2; i++)
		{
			temp = OriginalArray[_Size - i - 1];
			OriginalArray[_Size - i - 1] = OriginalArray[i];
			OriginalArray[i] = temp;
		}
	}

	void Clear()
	{
		_Size = 0;
		delete[] OriginalArray;
		OriginalArray = new T[_Size];
	}

	bool DeleteItemAt(int Index)
	{
		if (Index >= _Size || Index < 0)
			return false;

		for (int i = Index; i < _Size - 1; i++)
		{
			OriginalArray[i] = OriginalArray[i + 1];
		}

		Resize(_Size - 1);
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}

		return -1;
	}

	bool DeleteItem(T Value)
	{
		int index = Find(Value);

		if (index == -1)
		{
			return false;
		}

		DeleteItemAt(index);
		return true;
	}

	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
			return false;

		Resize(_Size + 1);
		for (int i = _Size - 1; i > Index; i--)
		{
			OriginalArray[i] = OriginalArray[i - 1];
		}

		OriginalArray[Index] = Value;
		return true;
	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
			return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}
};