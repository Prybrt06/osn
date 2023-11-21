#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process
{
public:
    int processNum;
    int arrivalTime;
    int burstTime;
    int variableBurstTime;
    int completionTime;
    int turnArroundTime;
    int waitTime;
    int responseTime;
};

bool sortOnTheBasisOfArrivalTime(const Process &p1, const Process &p2)
{
    if (p1.arrivalTime == p2.arrivalTime)
    {
        return p1.burstTime < p2.burstTime;
    }

    return p1.arrivalTime < p2.arrivalTime;
}

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
        p.arrivalTime = at;
        p.burstTime = bt;
        p.variableBurstTime = bt;
        p.processNum = i + 1;

        arr.push_back(p);
        temp.push_back(p);
    }

    sort(temp.begin(), temp.end(), sortOnTheBasisOfArrivalTime);

    queue<Process> q;
    q.push(temp[0]);

    int time = 0;
    int i = 1;

    while (!q.empty())
    {
        Process p = q.front();
        q.pop();
        // Process p = arr[0];

        if (p.variableBurstTime <= timeQuantum)
        {
            if (p.variableBurstTime == p.burstTime)
            {
                arr[p.processNum - 1].responseTime = time;
            }
            time += p.variableBurstTime;

            p.variableBurstTime = 0;
            arr[p.processNum - 1].completionTime = time;

            while (i < 0 && temp[i].arrivalTime <= time)
            {
                q.push(temp[i++]);
            }
        }

        else
        {
            if (p.variableBurstTime == p.burstTime)
            {
                arr[p.processNum - 1].responseTime = time;
            }

            time += timeQuantum;
            p.variableBurstTime -= timeQuantum;

            // cout << i << endl;
            while (i < n && temp[i].arrivalTime <= time)
            {
                // cout << "hello " << temp[i].arrivalTime << endl;
                q.push(temp[i++]);
            }

            q.push(p);
        }

        // cout << time << endl;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].turnArroundTime = arr[i].completionTime - arr[i].arrivalTime;
        arr[i].waitTime = arr[i].turnArroundTime - arr[i].burstTime;
    }

    cout << "PNo  AT  BT  CT  TAT  WT  RT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].arrivalTime << "  " << arr[i].burstTime << "  " << arr[i].completionTime << "  " << arr[i].turnArroundTime << "  " << arr[i].waitTime << "  "
             << arr[i].responseTime << endl;
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
*/