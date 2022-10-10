#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <conio.h>
#include<thread>
using namespace std;

class Field {
public:
	Field(int x, int y) 
	{
		SetFieldSize(x, y);
		hero();	// устоновить координаты героя
		PrintField();	// распечатать 
		Move(); // движение
	}
	
	void PrintField() 
	{
		HeroUpdate();
		for (int x = 0; x < field.size(); ++x) 
		{
			for (int y = 0; y < field[0].size(); ++y) 
			{
				cout << left << setw(2);
				cout << field[x][y];
			}
			cout << endl;
		}
	}
	
private:
	char fieldVoid = '0';
	vector<vector<char>> field;
	map<char, int> heroPosition;	// позиция героя

	
	void SetFieldSize(const int& x, const int& y) 
	{
		field.assign(x, vector<char>(y, fieldVoid));	// заполнить символом
	}
	void hero() 
	{	//координаты героя
		heroPosition['x'] = field.size() / 2;
		heroPosition['y'] = field[0].size() / 2;
	}

	void HeroUpdate() 
	{
		field[heroPosition['x']][heroPosition['y']] = 'H';	// обновить позицию героя
	}

	void Move() 
	{
		char key;
		while (true)
		{
			cout << "move: ";
			key = _getch();
			if (key == 'w' or key == 's' or key == 'a' or key == 'd')
			{
				field[heroPosition['x']][heroPosition['y']] = fieldVoid;
				if (key == 'w')
				{
					heroPosition['x'] -= 1;
					Refresh();
				}
				else if (key == 's')
				{
					heroPosition['x'] += 1;
					Refresh();
				}
				else if (key == 'a')
				{
					heroPosition['y'] -= 1;
					Refresh();
				}
				else if (key == 'd')
				{
					heroPosition['y'] += 1;
					Refresh();
				}
			}
			this_thread::sleep_for(chrono::milliseconds(500));
			
		}
	}

	void Refresh() {
		HeroUpdate();
		system("cls");
		PrintField();

	}
};

int main() 
{
	Field one(16, 16);
	one.PrintField();
	
}