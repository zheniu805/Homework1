
# 41443127

# Homework 1

## 解題說明

本次作業共有兩個問題。

Problem 1 要求實作 Ackermann Function，分別使用遞迴與非遞迴兩種方式計算。

Problem 2 要求使用遞迴方式產生一個集合的所有子集合，也就是 Powerset。

### Problem 1：Ackermann Function

Ackermann Function 定義如下：

$$
A(m,n)=
\begin{cases}
n+1, & m=0 \\
A(m-1,1), & n=0 \\
A(m-1,A(m,n-1)), & otherwise
\end{cases}
$$

### 解題策略

1. 遞迴版本直接按照題目給定的公式進行實作。
2. 當 $m=0$ 時，回傳 $n+1$。
3. 當 $n=0$ 時，計算 $A(m-1,1)$。
4. 其他情況計算 $A(m-1,A(m,n-1))$。
5. 非遞迴版本使用 `stack` 儲存尚未完成的 $m$，並使用 `while` 迴圈模擬原本的遞迴過程。

### Problem 2：Powerset

Powerset 是一個集合所有可能子集合所形成的集合。

例如：

$$
S=\{a,b,c\}
$$

共有：

$$
2^3=8
$$

個子集合。

### 解題策略

1. 從集合的第一個元素開始處理。
2. 每個元素都有「不選」與「選」兩種情況。
3. 使用遞迴繼續處理下一個元素。
4. 當所有元素都處理完成時，輸出目前的子集合。


## 程式實作

以下為主要程式碼：

```cpp
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
```


## 效能分析

### Problem 1：Ackermann Function


空間複雜度可表示為：

$$
O(A(m,n))
$$

時間複雜度可表示為：

$$
O(A(m,n))
$$


### Problem 2：Powerset

由於輸出每個子集合時最多需要檢查 $n$ 個元素，因此時間複雜度為：

$$
O(n2^n)
$$

遞迴的最大深度為 $n$，因此遞迴所需的額外空間複雜度為：

$$
O(n)
$$


## 測試與驗證

### Problem 1 測試案例

| 測試案例 | m | n | Recursive | Nonrecursive |
|----------|---|---|-----------|--------------|
| 測試一 | 0 | 1 | 2 | 2 |
| 測試二 | 1 | 1 | 3 | 3 |
| 測試三 | 2 | 2 | 7 | 7 |
| 測試四 | 2 | 3 | 9 | 9 |
| 測試五 | 3 | 2 | 29 | 29 |

遞迴與非遞迴版本得到相同結果，因此可以確認兩種方法的計算結果一致。

### Problem 2 測試案例

輸入：

```text
3
a b c
```

輸出：

```text
{}
{c}
{b}
{bc}
{a}
{ac}
{ab}
{abc}
```

集合中共有 3 個元素，因此 Powerset 應有：

$$
2^3=8
$$

個子集合。

程式實際輸出 8 個子集合，因此結果符合預期。


### 編譯與執行指令

```shell
g++ -std=c++17 -o homework1 homework1.cpp
./homework1
```


### 結論

1. Ackermann Function 的遞迴版本能按照數學定義正確計算結果。
2. Ackermann Function 的非遞迴版本使用 `stack` 模擬遞迴，結果與遞迴版本相同。
3. Powerset 能使用遞迴方式產生集合的所有子集合。
4. 當輸入 `{a,b,c}` 時，可以正確產生 8 個子集合。


## 申論及開發報告

### Problem 1：遞迴與非遞迴

Ackermann Function 的遞迴寫法與數學公式非常接近，因此程式較容易理解。

例如：

```cpp
if (m == 0)
    return n + 1;
else if (n == 0)
    return ackermann(m - 1, 1);
else
    return ackermann(m - 1, ackermann(m, n - 1));
```

可以直接對應題目給出的三種情況。

非遞迴版本則使用 `stack` 儲存需要繼續處理的資料，並利用 `while` 迴圈逐步完成計算。

透過兩種不同方式實作同一個函式，可以了解遞迴函式在執行時會利用堆疊保存尚未完成的工作。

### Problem 2：Powerset 的遞迴

Powerset 使用遞迴的原因是每個元素都可以分成兩種選擇：

1. 不加入目前的子集合。
2. 加入目前的子集合。

程式會對這兩種情況繼續呼叫下一層：

```cpp
result[index] = ' ';
powerset(n, index + 1);

result[index] = a[index];
powerset(n, index + 1);
```

當 `index == n` 時，代表所有元素都已經決定是否加入，因此輸出目前得到的子集合。

透過本次作業可以練習遞迴、Stack，以及使用遞迴方式產生所有可能組合的基本概念。
