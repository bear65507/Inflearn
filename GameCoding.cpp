#include <iostream>
using namespace std;

class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }
private:
	int _userCount = 0;
};

#define GET_MANAGER (UserManager::GetInstance())

int main()
{
	GET_MANAGER->AddUser();
	cout << UserManager::GetInstance()->GetUserCount() << endl;

}