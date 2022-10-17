#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

class Time
{
public:
	int year;
	int month;
	int date;
	int hour;
	int min;
	int sec;
};
char days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool leapYear(int Year)
{
	if (Year % 400 == 0 ||
		(Year % 100 != 0 && Year % 4 == 0))
		return true;
	else
		return false;
}
long long int changetosec(Time time1)
{
	long long int sec1 = 0;
	if (leapYear(time1.year))
		days[2] = 29;
	for (int i = 1900; i < time1.year; i++)
	{
		if (leapYear(i))
			sec1 += 366 * 24 * 60 * 60;
		else
			sec1 += 365 * 24 * 60 * 60;

	}
	for (int i = 1; i < time1.month; i++)
	{
		sec1 += days[i] * 24 * 60 * 60;
	}
	sec1 += (time1.date - 1) * 24 * 60 * 60;
	sec1 += time1.hour * 60 * 60;
	sec1 += time1.min * 60;
	sec1 += time1.sec;
	return sec1;
}



Time add30(Time time1)
{
	time1.min += 30;
	if (time1.min >= 60)
	{
		time1.hour++;
		time1.min -= 60;
	}
	if (time1.hour >= 24)
	{
		time1.hour -= 24;
		time1.date++;
	}

	if (leapYear(time1.year))
		days[2] = 29;
	if (time1.date > days[time1.month])
	{
		time1.date -= days[time1.month];
		time1.month++;
	}
	if (time1.month > 12)
	{
		time1.month = 1;
		time1.year++;
	}
	return time1;
}
Time add3day(Time time1)
{
	char days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	time1.date += 3;
	if (leapYear(time1.year))
		days[2] = 29;
	if (time1.date > days[time1.month])
	{
		time1.date -= days[time1.month];
		time1.month++;
	}
	if (time1.month > 12)
	{
		time1.month = 1;
		time1.year++;
	}
	return time1;
}
//1<2
int smaller30(Time time1, Time time2)
{
	long long int sec1 = 0, sec2 = 0;
	for (int i = 1900; i < time1.year; i++)
	{

		if (leapYear(i))
			sec1 += 366 * 24 * 60 * 60;
		else
			sec1 += 365 * 24 * 60 * 60;

	}
	for (int i = 1; i < time1.month; i++)
	{
		if (leapYear(time1.year))
			days[2] = 29;
		sec1 += days[i] * 24 * 60 * 60;
	}
	sec1 += time1.date * 24 * 60 * 60;
	sec1 += time1.hour * 60 * 60;
	sec1 += time1.min * 60;
	sec1 += time1.sec;
	for (int i = 1900; i < time2.year; i++)
	{
		if (leapYear(i))
			sec2 += 366 * 24 * 60 * 60;
		else
			sec2 += 365 * 24 * 60 * 60;
	}
	for (int i = 1; i < time2.month; i++)
	{
		if (leapYear(time2.year))
			days[2] = 29;
		sec2 += days[i] * 24 * 60 * 60;
	}
	sec2 += time2.date * 24 * 60 * 60;
	sec2 += time2.hour * 60 * 60;
	sec2 += time2.min * 60;
	sec2 += time2.sec;
	sec2 += 1800;
	if ((sec2 - sec1) >= 0)
		return true;
	else
		return false;
}

int smaller3day(Time time1, Time time2)
{
	long long int sec1 = 0, sec2 = 0;
	for (int i = 1900; i < time1.year; i++)
	{

		if (leapYear(i))
			sec1 += 366 * 24 * 60 * 60;
		else
			sec1 += 365 * 24 * 60 * 60;

	}
	for (int i = 1; i < time1.month; i++)
	{
		if (leapYear(time1.year))
			days[2] = 29;
		sec1 += days[i] * 24 * 60 * 60;
	}
	sec1 += time1.date * 24 * 60 * 60;
	sec1 += time1.hour * 60 * 60;
	sec1 += time1.min * 60;
	sec1 += time1.sec;
	for (int i = 1900; i < time2.year; i++)
	{
		if (leapYear(i))
			sec2 += 366 * 24 * 60 * 60;
		else
			sec2 += 365 * 24 * 60 * 60;
	}
	for (int i = 1; i < time2.month; i++)
	{
		if (leapYear(time2.year))
			days[2] = 29;
		sec2 += days[i] * 24 * 60 * 60;
	}
	sec2 += time2.date * 24 * 60 * 60;
	sec2 += time2.hour * 60 * 60;
	sec2 += time2.min * 60;
	sec2 += time2.sec;
	sec2 += 259200;
	if ((sec2 - sec1) >= 0)
		return true;
	else
		return false;
}
int smaller(Time time1, Time time2)
{
	long long int sec1 = 0, sec2 = 0;
	for (int i = 1900; i < time1.year; i++)
	{

		if (leapYear(i))
			sec1 += 366 * 24 * 60 * 60;
		else
			sec1 += 365 * 24 * 60 * 60;

	}
	for (int i = 1; i < time1.month; i++)
	{
		if (leapYear(time1.year))
			days[2] = 29;
		sec1 += days[i] * 24 * 60 * 60;
	}
	sec1 += time1.date * 24 * 60 * 60;
	sec1 += time1.hour * 60 * 60;
	sec1 += time1.min * 60;
	sec1 += time1.sec;
	for (int i = 1900; i < time2.year; i++)
	{
		if (leapYear(i))
			sec2 += 366 * 24 * 60 * 60;
		else
			sec2 += 365 * 24 * 60 * 60;
	}
	for (int i = 1; i < time2.month; i++)
	{
		if (leapYear(time2.year))
			days[2] = 29;
		sec2 += days[i] * 24 * 60 * 60;
	}
	sec2 += time2.date * 24 * 60 * 60;
	sec2 += time2.hour * 60 * 60;
	sec2 += time2.min * 60;
	sec2 += time2.sec;
	if (sec1 <= sec2)
		return true;
	else
		return false;
}


int bigger(Time time1, Time time2)
{
	long long int sec1 = 0;
	long long int sec2 = 0;
	for (int i = 1900; i < time1.year; i++)
	{
		if (leapYear(i))
			sec1 += 366 * 24 * 60 * 60;
		else
			sec1 += 365 * 24 * 60 * 60;
	}
	for (int i = 1; i < time1.month; i++)
	{
		if (leapYear(time1.year))
			days[2] = 29;
		sec1 += days[i] * 24 * 60 * 60;
	}
	sec1 += time1.date * 24 * 60 * 60;
	sec1 += time1.hour * 60 * 60;
	sec1 += time1.min * 60;
	sec1 += time1.sec;
	for (int i = 1900; i < time2.year; i++)
	{
		if (leapYear(i))
			sec2 += 366 * 24 * 60 * 60;
		else
			sec2 += 365 * 24 * 60 * 60;

	}
	for (int i = 1; i < time2.month; i++)
	{
		if (leapYear(time2.year))
			days[2] = 29;
		sec2 += days[i] * 24 * 60 * 60;
	}
	sec2 += time2.date * 24 * 60 * 60;
	sec2 += time2.hour * 60 * 60;
	sec2 += time2.min * 60;
	sec2 += time2.sec;

	if ((sec1 - sec2) >= 0)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	vector<string>ansstore;//第一層感染者去過的商店
	vector<Time>anstime;//第一層去過商店時間
	vector<Time>firstime;
	vector<Time> Alltime;
	vector<int>recordnum;//第幾個
	vector<string>ans;//第一層感染者
	vector<string>ans2;//第二層感染者
	vector<string>record;
	vector<string> file;
	vector<string>num;//實名制編號
	vector<string>store;//商店
	string line;
	ifstream fin1;
	fin1.open(argv[1]);
	while (!fin1.eof())
	{
		getline(fin1, line);
		file.push_back(line);
	}
	string first = file[0];
	Time timebegin;//first one
	timebegin.year = stoi(file[1].substr(0, 4));
	timebegin.month = stoi(file[1].substr(5, 2));
	timebegin.date = stoi(file[1].substr(8, 2));
	timebegin.hour = 0;
	timebegin.min = 0;
	timebegin.sec = 0;
	Time timeend;//first one
	timeend.year = stoi(file[2].substr(0, 4));
	timeend.month = stoi(file[2].substr(5, 2));
	timeend.date = stoi(file[2].substr(8, 2));
	timeend.hour = 0;
	timeend.min = 0;
	timeend.sec = 0;
	timeend.date += 1;
	for (int i = 3; i < file.size() - 1; i++)
	{
		int timepos = file[i].find('-');
		Time time1;
		time1.year = stoi(file[i].substr(timepos - 4, 4));
		time1.month = stoi(file[i].substr(timepos + 1, 2));
		time1.date = stoi(file[i].substr(timepos + 4, 2));
		//先抓實名制編號 商店編號 OK
		int pos = file[i].find(',');
		string temp = file[i].substr(0, pos);
		if (pos != -1)
		{
			num.push_back(temp);
		}
		int pos2 = file[i].find(',', pos + 1);
		if (pos2 != -1)
		{
			string temp2 = file[i].substr(pos + 1, pos2 - pos - 1);
			long long int one = changetosec(time1);
			long long int two = changetosec(timebegin);
			long long int three = changetosec(timeend);
			if (temp == first && one - two >= 0 && three - one >= 0)//第一個的東西 && bigger(time1, timebegin) && smaller(time1, timeend)
			{
				record.push_back(temp2);//把第一個去過的商店抓起來
				Time time2;
				time2.year = stoi(file[i].substr(timepos - 4, 4));
				time2.month = stoi(file[i].substr(timepos + 1, 2));
				time2.date = stoi(file[i].substr(timepos + 4, 2));
				time2.hour = stoi(file[i].substr(timepos + 7, 2));
				time2.min = stoi(file[i].substr(timepos + 10, 2));
				time2.sec = stoi(file[i].substr(timepos + 13, 2));
				firstime.push_back(time2);
			}
			store.push_back(temp2);
		}
		time1.hour = stoi(file[i].substr(timepos + 7, 2));
		time1.min = stoi(file[i].substr(timepos + 10, 2));
		time1.sec = stoi(file[i].substr(timepos + 13, 2));
		Alltime.push_back(time1);
	}
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < record.size(); j++)
		{
			if (store[i] == record[j] && num[i] != first)//同間 期間內&& bigger(firstime[j], timebegin) && smaller(firstime[j], timeend)
			{
				long long int one = changetosec(Alltime[i]);
				long long int two = changetosec(firstime[j]);
				if (one - two >= 0 && one - two <= 1800)//三十分鐘內bigger(Alltime[i], firstime[j]) && smaller30(Alltime[i], firstime[j])
				{
					ans.push_back(num[i]);//第一層感染者
					anstime.push_back(Alltime[i]);//那幾間店的時間
					//recordnum.push_back(i);
				}
			}
		}
	}
	/**/for (int i = 0; i < ans.size(); i++)
	{
		for (int j = i + 1; j < ans.size(); j++)
		{
			if (ans[i] == ans[j])
			{
				ans.erase(ans.begin() + j);
				anstime.erase(anstime.begin() + j);
				j--;
			}
		}
	}
	vector<Time>anstime2;
	vector<string>ansnum;
	//以上ans ok
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < ans.size(); j++)
		{
			long long int one = changetosec(Alltime[i]);
			long long int two = changetosec(anstime[j]);
			if (num[i] == ans[j] && one - two >= 0 && one - two <= 259200)//第一層感染者的三日內去過的bigger(Alltime[i], anstime[j]) && smaller3day(Alltime[i],anstime[j])
			{
				ansnum.push_back(num[i]);
				ansstore.push_back(store[i]);
				anstime2.push_back(Alltime[i]);//第一層他們去那些商店的時間
			}
		}
	}
	for (int i = 0; i < store.size(); i++)
	{
		for (int j = 0; j < ansstore.size(); j++)
		{
			long long int one = changetosec(Alltime[i]);
			long long int two = changetosec(anstime2[j]);
			if (store[i] == ansstore[j] && one - two >= 0 && one - two <= 1800)//重疊30分鐘內&& !equal(Alltime[i], anstime2[j]) bigger(Alltime[i], anstime2[j]) && smaller30(Alltime[i],anstime2[j])
			{
				ans2.push_back(num[i]);
			}
		}
	}
	//cout << ans[0];
	//cout << anstime[0].hour;
	//cout << ansstore[0];
	//cout << ansnum[0];
	//cout << anstime2[0].date;
	vector<int> number;
	ans.push_back(first);
	for (int i = 0; i < ans.size(); i++)
	{
		int nuum = stoi(ans[i].substr(1, ans[i].size() - 1));
		number.push_back(nuum);
	}
	for (int i = 0; i < ans2.size(); i++)
	{
		int nuum = stoi(ans2[i].substr(1, ans2[i].size() - 1));
		number.push_back(nuum);
	}
	for (int i = 0; i < number.size(); i++)
	{
		for (int j = i + 1; j < number.size(); j++)
		{
			if (number[i] == number[j])
			{
				number.erase(number.begin() + j);
				j--;
			}
		}
	}
	sort(number.begin(), number.end());
	for (int i = 0; i < number.size(); i++)
	{
		cout << 'A' << number[i] << endl;
	}
}