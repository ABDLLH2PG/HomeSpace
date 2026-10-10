#pragma once
#include <iostream>
#include "clsMyStackArr.h"
using namespace std;

class clsMyString
{
private:
	string _Value;
	clsMyStackArr <string> _UndoStack;
	clsMyStackArr <string> _RedoStack;
	
public:
	clsMyString()
	{
		this->_Value = "";
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;
	
	void SetValue(string NewValue)
	{
		_UndoStack.push(_Value);
		_Value = NewValue;

		_RedoStack.Clear();
	}
	
	string GetValue()
	{
		return _Value;
	}

	void Undo()
	{
		if (!_UndoStack.IsEmpty())
		{
			_RedoStack.push(_Value);
			_Value = _UndoStack.front();
			_UndoStack.pop();
		}
	}

	void Redo()
	{
		if (!_RedoStack.IsEmpty())
		{
			_UndoStack.push(_Value);
			_Value = _RedoStack.front();
			_RedoStack.pop();
		}
	}
};