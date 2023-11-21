#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Process
{
public:
    int processNum;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnArroundTime;
    int waitTime;
    int responseTime;
};

bool comp(Process &l, Process &r)
{
    if (l.arrivalTime == r.arrivalTime)
    {
        return l.burstTime < r.burstTime;
    }

    else
    {
        return l.arrivalTime < r.arrivalTime;
    }
}

bool compareProcess(const Process &p1, const Process &p2)
{
    return p1.processNum < p2.processNum;
}

int main()
{
    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    vector<Process> arr(n);

    for (int i = 0; i < n; i++)
    {
        int at, bt;
        cout << "Enter the arriving time of process " << i + 1 << " : ";
        cin >> at;

        cout << "Enter the burst time of process " << i + 1 << " : ";
        cin >> bt;

        arr[i].arrivalTime = at;
        arr[i].burstTime = bt;
        arr[i].processNum = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    int i = 0;

    int time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> processes;

    for (int i = 0; i < n;)
    {
        if (arr[i].arrivalTime > time)
        {
            arr[i].completionTime = arr[i].arrivalTime + arr[i].burstTime;
            time = arr[i].completionTime;
        }

        else
        {
            while (i < n && arr[i].arrivalTime <= time)
            {
                processes.push({arr[i].burstTime, i});
                i++;
            }
        }

        if (processes.size())
        {
            int index = processes.top().second;

            arr[index].completionTime = time + arr[index].burstTime;
            time = arr[index].completionTime;

            processes.pop();
        }
    }

    while (processes.size())
    {
        int index = processes.top().second;

        arr[index].completionTime = time + arr[index].burstTime;
        time = arr[index].completionTime;

        processes.pop();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].turnArroundTime = arr[i].completionTime - arr[i].arrivalTime;
        arr[i].waitTime = arr[i].turnArroundTime - arr[i].burstTime;
        arr[i].responseTime = arr[i].waitTime;
    }

    sort(arr.begin(), arr.end(), compareProcess);

    cout << "PNo  AT  BT  CT  TAT  WT  RT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].arrivalTime << "  " << arr[i].burstTime << "  " << arr[i].completionTime << "  " << arr[i].turnArroundTime << "  " << arr[i].waitTime << "  "
             << arr[i].responseTime << endl;
    }

    return 0;
}

/*
5
2
6
5
2
1
8
0
3
4
4
*/