#include <iostream>
#include <queue>
#include <string>

using namespace std;;

class Job 
{
protected:
	int id;
	int countPage;
	string name;
	
public:
	/*Job(int id, int countPage, int name)
	{
		this->id = id;
		this->countPage = countPage;
		this->name = name;
	}*/

	void inputJob() {
		cout << "�۾� ID : ";
		cin >> id;
		
		cout << endl << "��û�� �̸� : ";
		cin >> name;
		
		cout << "�μ� ������ �� : ";
		cin >> countPage;
	}

	string toString()
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
public:
	void AddJob(Job job) 
	{
		jobList.push(job);
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
			ProcessJob();
		}
	}
};



int main() {
	
}