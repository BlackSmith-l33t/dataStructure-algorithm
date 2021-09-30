#include <iostream>
#include <queue>
#include <string>

using namespace std;;

enum jobMenu
{
	None,
	Add,
	Print,
	Exit
};

class Job
{
public:
	string id;
	string name;
	int countPage;

	void toString()
	{
		cout << id << endl;		
	}
};

class Printer : Job
{
private:
	queue<Job> jobList;
	int jobNumber;
	jobMenu newJobMenu = None;
public:

	void inputJob(Job& job) {

		cout << "�۾� ID : ";
		cin >> job.id;

		cout << "��û�� �̸� : ";
		cin >> job.name;

		cout << "�μ� ������ �� : ";
		cin >> job.countPage;
	}

	void AddJob()
	{
		Job newJob;
		inputJob(newJob);
		jobList.push(newJob);
	}

	void ProcessJob()
	{
		if (!jobList.empty())
		{			
			cout << "ó���� �۾� ID: " << jobList.front().id;			
			jobList.pop();
			cout << endl;
		}
		else
		{
			cout << "�Ҵ�� �۾� ����" << endl;
			cout << endl;
			return;
		}
	}

	void Operate()
	{
		while (true)
		{
			cout << "1. �۾� �߰� | 2. �μ� ���� | 3. ����" << endl;
			cin >> jobNumber;

			newJobMenu = (jobMenu)jobNumber;

			switch (newJobMenu)
			{
			case Add:
				AddJob();
				break;
			case Print:
				ProcessJob();
				break;
			case Exit:
				return;
			default:
				cout << "�ٽ� �Է��ϼ���" << endl;
				break;
			}
		}
	}
};


int main() {
	Job newJob;
	Printer newPrinter;
	newPrinter.Operate();
	cout << "�����͸� �����մϴ�.";
}