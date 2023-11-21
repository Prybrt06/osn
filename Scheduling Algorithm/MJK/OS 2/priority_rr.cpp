#include <bits/stdc++.h>
using namespace std;

int tq,avgTT;

struct process
{
    int arrival;
    int burst;
    int no;
    int priority;
    process() {
        this->burst=0;
    }
};

process execute(queue<process>& q,int & time)
{
    process p = q.front();
    q.pop();
    if (p.burst > tq)
    {
        time += tq-1;
        p.burst -= tq;
        cout << "Process " << p.no << " runs from " << time - tq + 1 << " to " << time << '\n';
    }
    else
    {
        time += p.burst-1;
        p.burst = 0;
        cout << "Process " << p.no << " completes at " << time+1 << '\n';
        avgTT += time - p.arrival;
    }
return p;
}

int main()
{
    cout << "Enter no of Processes\n";
    int n;
    cin >> n;
    vector<process> arr(n);
    cout << "Enter Process Arrival Time and Burst Time and Process Number and Priority\n";
    for (auto &a : arr)
        cin >> a.arrival >> a.burst >> a.no >> a.priority;
    sort(arr.begin(), arr.end(), [](process a, process b)
            { return a.arrival < b.arrival; });
    for(auto a: arr) cout<<a.no<<' ';
    cout << "Enter Time Quantum\n";
    cin >> tq;
    queue<process> q1,q2;
    int time = arr[0].arrival-1; 
    int avgWT = accumulate(arr.begin(), arr.end(), 0, [](int sum, process p)
                           { return sum + p.burst; });
    for (int i = 0; time <= arr[n - 1].arrival; time++)
    {
        process p;
        if (q2.size())
            p=execute(q2,time);
        else if (q1.size())
            p=execute(q1,time);
        while (i < n && arr[i].arrival <= time+1)
        {
            if(arr[i].priority==1) q1.push(arr[i++]);
            else q2.push(arr[i++]);
        }
        if(p.burst)
        {
            if(p.priority==1) q1.push(p);
            if(p.priority==2) q2.push(p);
        }
    }
    while (q2.size())
    {
        process p=execute(q2,time);
        time++;
        if(p.burst) q2.push(p);
    }
    while (q1.size())
    {
        process p=execute(q1,time);
        time++;
        if(p.burst) q1.push(p);
    }
    cout << "\nAverage Turn-Around Time is " << (double)avgTT / (double)n << '\n';
    cout << "Average Wait Time is " << (double)(avgTT - avgWT) / (double)n << '\n';
}