#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Process
{
public:
    int processNum, at, bt, ct, tat, wt, rt;
};

bool comp(Process &l, Process &r)
{
    if (l.at == r.at)
    {
        return l.bt > r.bt;
    }

    return l.at < r.at;
}

bool compareProcess(const Process &p1, const Process &p2)
{
    return p1.processNum < p2.processNum;
}

int main()
{
    int n;
    cin >> n;

    vector<Process> arr(n);

    for (int i = 0; i < n; i++)
    {
        int at, bt;

        cin >> at;
        cin >> bt;

        arr[i].at = at;
        arr[i].bt = bt;
        arr[i].processNum = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    int i = 0;

    int time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>> processes;

    for (int i = 0; i < n;)
    {
        if (arr[i].at > time)
        {
            time = arr[i].at;
        }

        time += arr[i].bt;

        arr[i].ct = time;
        i++;

        while (i < n && arr[i].at <= time)
        {
            processes.push({arr[i].bt, i});
            i++;
        }

        if (processes.size())
        {
            int index = processes.top().second;

            arr[index].ct = time + arr[index].bt;
            time = arr[index].ct;

            processes.pop();
        }
    }

    while (processes.size())
    {
        int index = processes.top().second;

        arr[index].ct = time + arr[index].bt;
        time = arr[index].ct;

        processes.pop();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        arr[i].rt = arr[i].wt;
    }

    sort(arr.begin(), arr.end(), compareProcess);

    cout << "PNo  AT  BT  CT  TAT  WT  RT" << endl;
    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].at << "  " << arr[i].bt << "  " << arr[i].ct << "  " << arr[i].tat << "  " << arr[i].wt << "  "
             << arr[i].rt << endl;

        avgWT += arr[i].wt;
        avgTAT += arr[i].tat;
    }

    avgWT = (avgWT) / (1.0 * n);
    avgTAT = (avgTAT) / (1.0 * n);

    cout << endl;

    cout << "Average turn arround time is : " << avgTAT << endl;
    cout << "Average waiting time is : " << avgWT << endl;

    return 0;
}

/*

4
1 2
2 4
3 6
4 8

*/