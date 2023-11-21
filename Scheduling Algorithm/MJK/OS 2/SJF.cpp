#include <bits/stdc++.h>
using namespace std;

struct process
{
    int arrival;
    int burst;
    int no;
};

class comp
{
public:
    bool operator()(process a, process b)
    {
        if (a.burst == b.burst)
            return a.arrival < b.arrival;
        return a.burst > b.burst;
    }
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
    priority_queue<process, vector<process>, comp> q;
    int time = arr[0].arrival;
    for (int i = 0; time <= arr[n - 1].arrival;)
    {
        if (q.size())
        {
            process p = q.top();
            time += p.burst;
            cout << "Process " << p.no << " completed at " << time << '\n';
            q.pop();
        }
        while (i < n && arr[i].arrival <= time)
        {
            q.push(arr[i]);
            i++;
        }
    }
    while (q.size())
    {
        process p = q.top();
        time += p.burst;
        cout << "Process " << p.no << " completed at " << time << '\n';
        q.pop();
    }
}
