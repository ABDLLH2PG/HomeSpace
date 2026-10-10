#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "Myclasses/clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefex = "";

	class clsTicket
	{
	private:
		short _TotalTickets = 0;
		short _AverageServeTime = 0;
		string _Prefex = "";
		short _WaitingClients = 0;
		short _ExpectedServeTime = 0;
		string _TicketTime;

	public:
		clsTicket(string Prefex, short AverageServeTime, short TotalTickets, short WaitingClients)
		{
			this->_Prefex = Prefex;
			this->_AverageServeTime = AverageServeTime;
			this->_TotalTickets = TotalTickets;
			this->_WaitingClients = WaitingClients;

			_TicketTime = clsDate::GetSystemDateTimeString();
		}
	
		string _TicketCode()
		{
			if (_TotalTickets < 10)
				return (_Prefex + to_string(_TotalTickets));
			else
				return (_Prefex[0] + to_string(_TotalTickets));
		}
		
		short ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void PrintTicket()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " + _TicketCode() + "\n";
			cout << "\n\t\t\t    " + _TicketTime;
			cout << "\n\t\t\t    Wating Clients = " + to_string(_WaitingClients);
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " + to_string(ExpectedServeTime()) + " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}

		void SetWatingClient(int WatingClient)
		{
			this->_WaitingClients = WatingClient;
		}

		void SetExpectedServeTime(int ExpectedServeTime)
		{
			this->_ExpectedServeTime = ExpectedServeTime;
		}
	};
	
	queue <clsTicket> QueueLine;
public:
	clsQueueLine(string Prefex, int AverageServeTime)
	{
		this->_Prefex = Prefex;
		this->_AverageServeTime = AverageServeTime;
	}
	
	int WaitingClient()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClient();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefex;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClient();
		cout << "\n\t\t\t _________________________\n\n";
	}
	
	void IssueTicket()
	{
		_TotalTickets++;;
		clsTicket New_Ticket(_Prefex, _AverageServeTime, _TotalTickets, WaitingClient());
		QueueLine.push(New_Ticket);
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		queue <clsTicket> TempQueueLine = QueueLine;
		while (!TempQueueLine.empty())
		{
			cout << " " << TempQueueLine.front()._TicketCode() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			cout << " " << TempStackLine.top()._TicketCode() << " --> ";

			TempStackLine.pop();
		}
		cout << "\n";
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		queue <clsTicket> TempQueueLine = QueueLine;
		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().PrintTicket();
			TempQueueLine.pop();
		}
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		UpdateTicketsWaitTime();
		return true;
	}

	void UpdateTicketsWaitTime()
	{
		queue <clsTicket> TempQueue;
		int CurrentWaiting = 0;

		while (!QueueLine.empty())
		{
			clsTicket t = QueueLine.front();
			t.SetWatingClient(CurrentWaiting);
			t.SetExpectedServeTime(CurrentWaiting * WaitingClient());

			TempQueue.push(t);
			QueueLine.pop();
			CurrentWaiting++;
		}

		QueueLine = TempQueue;
	}
};