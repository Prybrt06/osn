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
    int qNo;
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
        if (p1.qNo == p2.qNo)
        {
            return p1.processNum < p2.processNum;
        }

        return p1.qNo > p2.qNo;
    }

    return p1.at < p2.at;
}

class compInReadyQueue
{
public:
    bool operator()(Process &p1, Process &p2)
    {
        if (p1.qNo == p2.qNo)
        {
            return p1.at > p2.at;
        }

        return p1.qNo < p2.qNo;
    }
};

bool compareWithQNo(const Process &p1, const Process &p2)
{
    return p1.qNo > p2.qNo;
}

int main()
{
    int n;
    cin >> n;

    Process arr[n];
    Process temp[n];

    for (int i = 0; i < n; i++)
    {
        int at, bt, qNo;
        cin >> at >> bt >> qNo;

        arr[i].at = at;
        arr[i].bt = bt;
        arr[i].qNo = qNo;
        arr[i].variablebt = bt;
        arr[i].processNum = i + 1;

        temp[i] = arr[i];
    }

    int tq = 1;

    sort(temp, temp + n, sortOnTheBasisOfArrivalTime);

    priority_queue<Process, vector<Process>, compInReadyQueue> q;

    q.push(temp[0]);

    int j = 0;

    int time = 0;
    int i = 1;

    while (q.size())
    {
        bool check = false;
        Process p = q.top();
        cout << p.processNum << endl;
        q.pop();
        j++;
        if (p.at > time)
        {
            time = p.at;
        }

        if (p.bt == p.variablebt)
        {
            arr[p.processNum - 1].rt = time;
        }

        if (p.variablebt <= tq)
        {
            time += p.variablebt;
            arr[p.processNum - 1].ct = time;
            check = true;
        }

        else
        {
            p.variablebt -= tq;
            time += tq;
        }

        while (i < n && temp[i].at <= time)
        {
            // cout << "hey" << endl;
            q.push(temp[i]);
            i++;
        }

        if (!check)
        {
            q.push(p);
        }

        // sort(q.begin(), q.end(), compareWithQNo);
    }
    double avgWT = 0;
    double avgTAT = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        avgWT += arr[i].wt;
        avgTAT += arr[i].tat;
    }

    cout << "PNo  AT  qNo  BT  CT  TAT  WT  RT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].at << "  " << arr[i].bt << "  " << arr[i].qNo << "  " << arr[i].ct << "  " << arr[i].tat << "  " << arr[i].wt << "  "
             << arr[i].rt << endl;
    }

    avgWT = (avgWT) / (1.0 * n);
    avgTAT = (avgTAT) / (1.0 * n);

    cout << endl;

    cout << "Average turn arround time is : " << avgTAT << endl;
    cout << "Average waiting time is : " << avgWT << endl;
}

/*

7
0 1 2
1 7 6
2 3 3
3 6 5
4 5 4
5 15 10
15 8 9

*/