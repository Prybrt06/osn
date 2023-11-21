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
    int avgWT = accumulate(arr.begin(), arr.end(), 0, [](int sum, process p)
                           { return sum + p.burst; });
    int time = arr[0].arrival, avgTT = 0;
    for(const auto& p: arr) {
        time+=p.burst;
        avgTT+=time-p.arrival;
        cout << "Process " << p.no << " completes at " << time << '\n';
    }
    cout << "\nAverage Turn-Around Time is " << (double)avgTT / (double)n << '\n';
    cout << "Average Wait Time is " << (double)(avgTT - avgWT) / (double)n << '\n';
}