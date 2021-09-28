#include <iostream>
#include <queue>
#include <string>

using namespace std;;

enum jobMenu
{
	None,
	AddJob,	
	Exit
};

class Job 
{
protected:
	int id;
	int countPage;
	string name;
	
public:

	void inputJob() {
		cout << "�۾� ID : ";
		cin >> id;
		
		cout << "��û�� �̸� : ";
		cin >> name;
		
		cout << "�μ� ������ �� : ";
		cin >> countPage;
	}

	void toString()
	{
		cout << "�۾� ID : " << id << endl;
		cout << "��û�� �̸� : " << name << endl;
		cout << "�μ� ������ �� : " <<  countPage << endl;
	}
};

class Printer : Job 
{
private:
	queue<Job> jobList;
	int jobNumber;
	jobMenu newJobMenu = None;
public:
	void AddJob() 
	{
		Job newJob;
		inputJob();
		jobList.push(newJob);
	}

	void ProcessJob() 
	{
		cout << "ó���� �۾� ��û: " << endl;
		toString();	
		jobList.pop();
	}	

	void Operate()
	{
		while (true)
		{
			cout << "1. �۾� �߰� | 2. ����" << endl;
			cin >> jobNumber;
			newJobMenu = (jobMenu)jobNumber;

			if (newJobMenu == jobMenu::AddJob)
			{
				AddJob();				
			}
			else if (newJobMenu == jobMenu::Exit)
			{
				break;
			}
			else
			{
				cout << "�ùٸ� �۾��� �����ϼ���" << endl;
			}			
		}	

		if (!jobList.empty())
		{
			ProcessJob();
		}
		else
		{
			cout << "�Ҵ�� �۾� ����";
		}
		return;
	}
};



int main() {
	Job newJob;
	Printer newPrinter;
	newPrinter.Operate();
}