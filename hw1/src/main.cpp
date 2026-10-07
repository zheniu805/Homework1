#include <iostream>
#include <stack>
using namespace std;

// Problem 1：Ackermann 遞迴
int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

// Problem 1：Ackermann 非遞迴
int ackermann2(int m, int n)
{
    stack<int> s;
    s.push(m);

    while (!s.empty())
    {
        m = s.top();
        s.pop();

        if (m == 0)
            n = n + 1;
        else if (n == 0)
        {
            n = 1;
            s.push(m - 1);
        }
        else
        {
            n = n - 1;
            s.push(m - 1);
            s.push(m);
        }
    }

    return n;
}

// Problem 2：Powerset
char a[10];
char result[10];

void powerset(int n, int index)
{
    if (index == n)
    {
        cout << "{";

        for (int i = 0; i < n; i++)
        {
            if (result[i] != ' ')
                cout << result[i];
        }

        cout << "}" << endl;
        return;
    }

    // 不選這個元素
    result[index] = ' ';
    powerset(n, index + 1);

    // 選這個元素
    result[index] = a[index];
    powerset(n, index + 1);
}

int main()
{
    int m, n;

    // Problem 1
    cout << "Problem 1" << endl;
    cout << "Enter m and n: ";
    cin >> m >> n;

    cout << "Recursive: " << ackermann(m, n) << endl;
    cout << "Nonrecursive: " << ackermann2(m, n) << endl;

    // Problem 2
    cout << endl;
    cout << "Problem 2" << endl;

    int size;

    cout << "Enter size: ";
    cin >> size;

    cout << "Enter elements: ";

    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "Powerset:" << endl;
    powerset(size, 0);

    return 0;
}
