#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process
{
public:
    int processNum;
    int at;
    int bt;
    int variablebt;
    int ct;
    int tat;
    int wt;
    int rt;
};

bool sortOnTheBasisOfArrivalTime(const Process &p1, const Process &p2)
{
    if (p1.at == p2.at)
    {
        return p1.bt < p2.bt;
    }

    return p1.at < p2.at;
}

class CompareRemainingTime
{
public:
    bool operator()(Process &p1, Process &p2)
    {
        if (p1.variablebt == p2.variablebt)
        {
            return p1.at > p2.at;
        }

        return p1.variablebt > p2.variablebt;
    }
};

int main()
{
    int n;
    cin >> n;

    int timeQuantum;
    cin >> timeQuantum;

    vector<Process> arr;
    vector<Process> temp;

    for (int i = 0; i < n; i++)
    {
        int at, bt;
        cin >> at >> bt;

        Process p;
        p.at = at;
        p.bt = bt;
        p.variablebt = bt;
        p.processNum = i + 1;

        arr.push_back(p);
        temp.push_back(p);
    }

    sort(temp.begin(), temp.end(), sortOnTheBasisOfArrivalTime);

    priority_queue<Process, vector<Process>, CompareRemainingTime> q;

    q.push(temp[0]);

    int time = 0;

    int i = 1;

    while (!q.empty())
    {
        Process p = q.top();

        q.pop();

        if (p.variablebt <= timeQuantum)
        {
            if (p.variablebt == p.bt)
            {
                arr[p.processNum - 1].rt = time;
            }
            time += p.variablebt;

            p.variablebt = 0;
            arr[p.processNum - 1].ct = time;

            while (i < n && temp[i].at <= time)
            {
                q.push(temp[i++]);
            }
        }

        else
        {
            if (p.variablebt == p.bt)
            {
                arr[p.processNum - 1].rt = time;
            }

            time += timeQuantum;
            p.variablebt -= timeQuantum;

            while (i < n && temp[i].at <= time)
            {
                q.push(temp[i++]);
            }

            q.push(p);
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
    }

    cout << "PNo  AT  BT  CT  TAT  WT  RT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].at << "  " << arr[i].bt << "  " << arr[i].ct << "  " << arr[i].tat << "  " << arr[i].wt << "  "
             << arr[i].rt << endl;
    }

    return 0;
}

/*
6
4
0 5
1 6
2 3
3 1
4 5
6 4


5
4
2 6
5 2
1 8
0 3
4 4
*/