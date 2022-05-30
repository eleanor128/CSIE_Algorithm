# CS_Algorithm

## HW1 Closest Pair Problem
```
我們認為在 Divide 到一個程度後，轉換方法可以提高效率，而 threshold 是指決定 divide 到什麼程度的閥值，
解釋 threshold 設置的考量，並寫一份報告。
Closest Pair(最近點對)
給平面上的 n 個點，每個點有 x 軸座標和 y 軸座標，找出距離最近的兩個點之間的距離。

Input:
第一行為一正整數字 n，代表點的個數，第二行開始依序為每個點的座標 Xi與 Yi。
2≦n≦1000000
-10000≦Xi≦10000
-10000≦Yi≦10000

Output:
兩個距離最近的點之間距離為多少，輸出至小數點後 3 位
範例輸入:
4
-2 3
9 10
-1 -2
8 4
範例輸出:
5.099
```

## HW2 DP Practice

寫兩個小程式測試遞迴解與 DP 解之間的差異，並繳交實驗報告。
不限定要解決什麼問題，但一定要用遞迴與DP 來解，並比較差異，當輸入大小大於多少時，在執行時間上會超過 10 秒。
下方有例子給同學參考。
斐波那契數列(舉例)
F_{n} = F_{n-1} + F_{n-2} \left ( n\geq 2 \right )
分別用 DP 與遞迴解時，當 n 大於多少，可發現兩者執行時間相差超過 10 秒
帕斯卡三角形(舉例)
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}


## HW3 Mathematical Expression Problem
```
給定一個沒有括號的數學表達式，請設計一個演算法來給表達式加上括號，使得表達式的值最大化。
例如，考慮表達式：2+7*5。
有兩種方法可以將表達式 2+(7*5) = 37 和 (2+7)*5 = 45 括起來，
因此在這種情況下，應該輸出第二個表達式。
您可以假設給定的表達式僅包含 3 種二元運算符“+”、“-”和“*”。
括起來的表達式不唯一，輸出其中一種方式即可。

Input:
2+7*5

Output:
45
(2+7)*5
```

## HW4 Job Schduling Problem
```
假設您有一台機器和𝑛個要在該機器上處理的工作 𝑗𝑜𝑏1,…, 𝑗𝑜𝑏𝑛。每個 𝑗𝑜𝑏𝑖 都有一個處理時間 𝑝𝑖 和一個截止日期 𝑑𝑖，
而且每個工作都有著相同的利潤 1。機器一次只能處理一個工作，𝑗𝑜𝑏𝑖 必須不間斷地運行 𝑝𝑖 個連續的時間單位。
如果工作 𝑗𝑜𝑏𝑖 在截止日期 𝑑𝑖 之前完成，您將獲得單位利潤，但如果在截止日期之後完成，您將無法獲得任何利潤。
請給出一個算法，找出獲得最大利潤的工作排程表。
請分別使用 DP 與 Greedy 作法分別解決此問題，並比較 𝒏 大於多少時，兩方法的執行時間有明顯差異。

Input:
首先輸入工作數量𝑛，接著依序輸入 𝑗𝑜𝑏𝑖 的運行時間 𝑝𝑖 與截止時間 𝑑𝑖
1 ≤ 𝑛 ≤ 10000
1 ≤ 𝑖 ≤ 𝑛
1 ≤ 𝑝𝑖 ≤ 100000
1 ≤ 𝑑𝑖 ≤ 100000

Output:
獲得最大利潤的工作排程表
範例輸入:
4
300 1000
1000 1200
200 600
100 101
範例輸出:
4 3 1
```
## HW5 Critical Link Problem
```
In a computer network a link L, which interconnects two servers, is considered critical if 
there are at least two servers A and B such that all network interconnection paths between A and B pass through L. 
Removing a critical link generates two disjoint sub–networks such that any two servers of a sub–network are interconnected.
It is known that：
1. the connection links are bi–directional
2. a server is not directly connected to itself
3. two servers are interconnected if they are directly connected or if they are interconnected with the same server
4. The network can have stand–alone sub–networks Write a program that finds all critical links of a given computer network.
ex. <0,3> and <3,4> are critical links

Input: 
The first line contains a positive integer n which is the number of network servers.
The next k lines until EOF are randomly ordered and show the way servers are connected.
Output: 
Prints all critical links in network increasingly.
 
範例輸入: 
5
1 0
2 1
0 2
3 0
3 4

範例輸出: 
0 3
3 4
```
