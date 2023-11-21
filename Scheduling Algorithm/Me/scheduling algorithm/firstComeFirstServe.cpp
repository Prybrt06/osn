#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process
{
public:
    int processNum, at, bt, ct, tat, wt, rt;
};

bool sortOnTheBasisOfArrivalTime(const Process &p1, const Process &p2)
{
    if (p1.at == p2.at)
    {
        return p1.processNum < p2.processNum;
    }

    return p1.at < p2.at;
}

int main()
{
    int n;
    cin >> n;

    vector<Process> arr, temp;

    for (int i = 0; i < n; i++)
    {
        int at, bt;
        cin >> at >> bt;

        Process p;
        p.at = at;
        p.bt = bt;
        p.processNum = i + 1;

        arr.push_back(p);
        temp.push_back(p);
    }

    sort(temp.begin(), temp.end(), sortOnTheBasisOfArrivalTime);

    int time = 0;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].at > time)
        {
            time = temp[i].at;
        }

        time += temp[i].bt;

        arr[temp[i].processNum - 1].ct = time;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        arr[i].rt = arr[i].wt;
    }

    cout << "PNo  AT  BT  CT  TAT  WT  RT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].processNum << "  " << arr[i].at << "  " << arr[i].bt << "  " << arr[i].ct << "  " << arr[i].tat << "  " << arr[i].wt << "  "
             << arr[i].rt << endl;
    }

    double avgWT = 0;
    double avgTAT = 0;

    for (int i = 0; i < n; i++)
    {
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

3
0 24
0 3
0 4

*/
