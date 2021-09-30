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

		cout << "작업 ID : ";
		cin >> job.id;

		cout << "요청자 이름 : ";
		cin >> job.name;

		cout << "인쇄 페이지 수 : ";
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
			cout << "처리된 작업 ID: " << jobList.front().id;			
			jobList.pop();
			cout << endl;
		}
		else
		{
			cout << "할당된 작업 없음" << endl;
			cout << endl;
			return;
		}
	}

	void Operate()
	{
		while (true)
		{
			cout << "1. 작업 추가 | 2. 인쇄 실행 | 3. 종료" << endl;
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
				cout << "다시 입력하세요" << endl;
				break;
			}
		}
	}
};


int main() {
	Job newJob;
	Printer newPrinter;
	newPrinter.Operate();
	cout << "프린터를 종료합니다.";
}