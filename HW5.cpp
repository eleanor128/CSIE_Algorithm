#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <ctype.h>
using namespace std;
#define MAX 10000
using std::begin;
vector<int> vec[MAX];

int t;
int counter = 0;

struct vertic
{
    int visit;
    int low;
    int d;
};

struct pairs
{
    int a;
    int b;
};

vector<pairs> connected;

bool compare(pairs a, pairs b)
{ // 小到大
    if (a.a < b.a)
        return 1;
    else
        return 0;
};

inline bool operator<(const pairs &lhs, const pairs &rhs)
{
    return lhs.a < rhs.a;
}

void DFS(int c, int n, int p, pairs ans[], int visit[], int low[], int d[]) //,int count
{
    visit[c] = 1; // 來過了
    d[c] = low[c] = t++;
    for (int i = 0; i < vec[c].size(); i++)
    {

        if (vec[c][i] > n)
            break;
        if (vec[c][i] == p)
            continue;

        if (visit[vec[c][i]] == 1)
        { // c的鄰居來過了
            low[c] = min(d[vec[c][i]], low[c]);
        }

        if (visit[vec[c][i]] == 0)
        {                                             // 沒來過c的鄰居
            DFS(vec[c][i], n, c, ans, visit, low, d); //,count
            if (low[vec[c][i]] > d[c])
            {

                if (vec[c][i] < c)
                {
                    ans[counter].a = vec[c][i];
                    ans[counter].b = c;
                }
                if (vec[c][i] > c)
                {
                    ans[counter].a = c;
                    ans[counter].b = vec[c][i];
                }
                counter++;
            }
            low[c] = min(low[vec[c][i]], low[c]);
        }
    }
}

void swap(pairs arr[], int pos1, int pos2)
{
    pairs temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(pairs arr[], int low, int high, pairs pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (arr[i].a > pivot.a)
        {
            i++;
        }
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}
void quickSort(pairs arr[], int low, int high)
{
    if (low < high)
    {
        pairs pivot = arr[high];
        int pos = partition(arr, low, high, pivot);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

void print(pairs ans[], int n)
{ //,int count

    sort(ans, ans + counter, compare);

    for (int i = 0; i < counter; i++)
    {
        cout << ans[i].a << " " << ans[i].b << "\n";
    }
}

int main()
{

    int n, u, v; //,count=0
    t = 0;
    if (cin >> n && n > 0)
    {
    }
    else
        return 0;
    ; // 輸入有幾個點

    int visit[n], low[n], d[n];
    pairs ans[n];
    for (int i = 0; i < n; i++)
    {

        visit[i] = 0;
        ans[i].a = MAX;
        ans[i].b = MAX;
    }

    while (cin >> u >> v)
    {
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0 && vec[i].size() != 0)
        {
            DFS(i, n, 0, ans, visit, low, d); //,count
        }
    }
    print(ans, n); //,count

    return 0;
}