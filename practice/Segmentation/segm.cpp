#include <iostream>
#include <vector>

using namespace std;

// Function to segment an array into subarrays
vector<vector<int> > segmentArray(const vector<int> &inputArray, int segmentSize)
{
    vector<vector<int> > segmentedArrays;

    for (size_t i = 0; i < inputArray.size(); i += segmentSize)
    {
        // Create a subarray for the current segment
        vector<int> segment;

        // Copy elements to the subarray, up to the segment size or until the end of the array
        for (int j = i; j < i + segmentSize && j < inputArray.size(); ++j)
        {
            segment.push_back(inputArray[j]);
        }

        // Add the current subarray to the segmented arrays
        segmentedArrays.push_back(segment);
    }

    return segmentedArrays;
}

int main()
{
    // Example usage
    vector<int> inputArray;
    for (int i = 1; i <= 10; i++)
    {
        inputArray.push_back(i);
    }
    int segmentSize = 3;

    vector<vector<int> > segmentedArrays = segmentArray(inputArray, segmentSize);

    // Display the segmented arrays
    for (const auto &segment : segmentedArrays)
    {
        for (int value : segment)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
