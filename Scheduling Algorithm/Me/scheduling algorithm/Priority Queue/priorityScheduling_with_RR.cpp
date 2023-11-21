#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process
{
public:
    int pNo, at, bt, qNo, variablebt, ct, tat, wt, rt;
};

bool sortOnTheBasisOfArrivalTimeIncOrder(const Process &p1, const Process &p2)
{
    if (p1.at == p2.at)
    {
        if (p1.qNo == p2.qNo)
        {
            return p1.pNo < p2.pNo;
        }

        return p1.qNo > p2.qNo;
    }

    return p1.at < p2.at;
}

bool sortOnTheBasisOfArrivalTimeDecOrder(const Process &p1, const Process &p2)
{
    if (p1.at == p2.at)
    {
        if (p1.qNo == p2.qNo)
        {
            return p1.pNo < p2.pNo;
        }

        return p1.qNo < p2.qNo;
    }

    return p1.at < p2.at;
}

bool compareWithQNoInc(const Process &p1, const Process &p2)
{
    return p1.qNo > p2.qNo;
}

bool compareWithQNoDec(const Process &p1, const Process &p2)
{
    return p1.qNo < p2.qNo;
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
        arr[i].pNo = i + 1;

        temp[i] = arr[i];
    }

    int tq;
    cin >> tq;

    char ch;
    cout << "is priority based on the increasing order of qNo ? (y,n)";

    cin >> ch;

    if (ch == 'y')
    {
        sort(temp, temp + n, sortOnTheBasisOfArrivalTimeIncOrder);
    }

    else
    {
        sort(temp, temp + n, sortOnTheBasisOfArrivalTimeDecOrder);
    }

    vector<Process> q;

    q.push_back(temp[0]);

    int j = 0;

    int time = 0;
    int i = 1;

    while (j < q.size())
    {
        bool check = false;
        Process p = q[j];

        j++;
        if (p.at > time)
        {
            time = p.at;
        }

        if (p.bt == p.variablebt)
        {
            arr[p.pNo - 1].rt = time;
        }

        if (p.variablebt <= tq)
        {
            time += p.variablebt;
            arr[p.pNo - 1].ct = time;
            check = true;
        }

        else
        {
            p.variablebt -= tq;
            time += tq;
        }

        while (i < n && temp[i].at <= time)
        {
            q.push_back(temp[i]);
            i++;
        }

        if (!check)
        {
            q.push_back(p);
        }

        if (ch == 'y')
        {
            sort(q.begin(), q.end(), compareWithQNoInc);
        }

        else
        {
            sort(q.begin(), q.end(), compareWithQNoDec);
        }
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
        cout << arr[i].pNo << "  " << arr[i].at << "  " << arr[i].bt << "  " << arr[i].qNo << "  " << arr[i].ct << "  " << arr[i].tat << "  " << arr[i].wt << "  "
             << arr[i].rt << endl;
    }

    avgWT = (avgWT) / (1.0 * n);
    avgTAT = (avgTAT) / (1.0 * n);

    cout << endl;

    cout << "Average turn arround time is : " << avgTAT << endl;
    cout << "Average waiting time is : " << avgWT << endl;
}

/*

4
0 4 1
0 3 1
0 8 2
10 5 1
2

*/