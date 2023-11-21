#include <bits/stdc++.h>
using namespace std;

struct process
{
    int arrival;
    int burst;
    int no;
};

int main()
{
    cout << "Enter no of Processes\n";
    int n;
    cin >> n;
    vector<process> arr(n);
    cout << "Enter Process Arrival Time and Burst Time and Process Number\n";
    for (auto &a : arr)
        cin >> a.arrival >> a.burst >> a.no;
    sort(arr.begin(), arr.end(), [](process a, process b)
         { return a.arrival < b.arrival; });
    cout << "Enter Time Quantum\n";
    int tq;
    cin >> tq;
    queue<process> q;
    int time = arr[0].arrival, i = 0, avgTT = 0;
    int avgWT = accumulate(arr.begin(), arr.end(), 0, [](int sum, process p)
                           { return sum + p.burst; });
    q.push(arr[i++]);
    while (q.size())
    {
        process p = q.front();
        q.pop();
        if (p.burst > tq)
        {
            time += tq;
            p.burst -= tq;
            cout << "Process " << p.no << " runs from " << time - tq << " to " << time << '\n';
        }
        else
        {
            time += p.burst;
            p.burst = 0;
            cout << "Process " << p.no << " completes at " << time << '\n';
            avgTT += time - p.arrival;
            avgWT += p.burst;
        }
        while (i < n && arr[i].arrival <= time)
            q.push(arr[i++]);
        if (p.burst)
            q.push(p);
    }
    cout << "\nAverage Turn-Around Time is " << (double)avgTT / (double)n << '\n';
    cout << "Average Wait Time is " << (double)(avgTT - avgWT) / (double)n << '\n';
}
