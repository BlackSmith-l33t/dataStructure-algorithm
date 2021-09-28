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
		cout << "작업 ID : ";
		cin >> id;
		
		cout << "요청자 이름 : ";
		cin >> name;
		
		cout << "인쇄 페이지 수 : ";
		cin >> countPage;
	}

	void toString()
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
		cout << "처리된 작업 요청: " << endl;
		toString();	
		jobList.pop();
	}	

	void Operate()
	{
		while (true)
		{
			cout << "1. 작업 추가 | 2. 종료" << endl;
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
				cout << "올바른 작업을 선택하세요" << endl;
			}			
		}	

		if (!jobList.empty())
		{
			ProcessJob();
		}
		else
		{
			cout << "할당된 작업 없음";
		}
		return;
	}
};



int main() {
	Job newJob;
	Printer newPrinter;
	newPrinter.Operate();
}