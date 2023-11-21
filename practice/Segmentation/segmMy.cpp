#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> inputs;

    for (int i = 1; i <= 10; i++)
    {
        inputs.push_back(i);
    }

    int noOfSegment = 3;

    vector<int> index(noOfSegment - 1);

    index[0] = 4;
    index[1] = 7;

    vector<vector<int> > segments;

    int k = 0;

    for (int i = 0; i < inputs.size();)
    {
        vector<int> segment;

        if (k >= index.size())
        {
            for (int j = i; j < inputs.size(); j++)
            {
                segment.push_back(j);
                i++;
            }
        }
        else
        {
            for (int j = i; j < index[k] && j < inputs.size(); j++)
            {
                segment.push_back(j);
                i++;
            }
            k++;
        }
        segments.push_back(segment);
    }

    for (int i = 0; i < segments.size(); i++)
    {
        for (int j = 0; j < segments[i].size(); j++)
        {
            cout << segments[i][j] << " ";
        }
        cout << endl;
    }
}