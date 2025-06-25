#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    while (testCount--)
    {
        int length;
        cin >> length;

        vector < long long > original(length), boost(length);
        long long maxElement = 0, boostSum = 0;

        for (int i = 0; i < length; ++i)
        {
            cin >> original[i];
            if (original[i] > maxElement)
                maxElement = original[i];
        }

        for (int j = 0; j < length; ++j)
        {
            cin >> boost[j];
            boostSum += boost[j];
        }

        long long start = maxElement, end = maxElement + 2 * boostSum;

        while (start < end)
        {
            long long midPoint = start + (end - start) / 2;
            __int128 removal = 0, doubling = 0;

            for (int i = 0; i < length; ++i)
            {
                __int128 diff = (__int128) midPoint - original[i];
                __int128 usedBoost = boost[i] < diff ? boost[i] : diff;

                removal += boost[i] - usedBoost;
                doubling += (diff - usedBoost) / 2;
            }

            if (doubling >= removal)
                end = midPoint;
            else
                start = midPoint + 1;
        }

        cout << start << '\n';
    }

    return 0;
}