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
		cout << "작업 ID : ";
		cin >> id;
		
		cout << endl << "요청자 이름 : ";
		cin >> name;
		
		cout << "인쇄 페이지 수 : ";
		cin >> countPage;
	}

	string toString()
	{
		cout << "작업 ID : " << id << endl;
		cout << "요청자 이름 : " << name << endl;
		cout << "인쇄 페이지 수 : " <<  countPage << endl;
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
		cout << "처리된 작업 요청: " << endl;
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