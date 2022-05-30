# CS_Algorithm

## HW1 Closest Pair Problem
```
我們認為在 Divide 到一個程度後，轉換方法可以提高效率，而 threshold 是指決定 divide 到什麼程度的閥值，
解釋 threshold 設置的考量，並寫一份報告。
Closest Pair(最近點對)
給平面上的 n 個點，每個點有 x 軸座標和 y 軸座標，找出距離最近的兩個點之間的距離。
Input:第一行為一正整數字 n，代表點的個數，第二行開始依序為每個點的座標 Xi與 Yi。
2≦n≦1000000
-10000≦Xi≦10000
-10000≦Yi≦10000
Output:兩個距離最近的點之間距離為多少，輸出至小數點後 3 位
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
<img width="230" alt="image" src="https://user-images.githubusercontent.com/83395975/170953669-31c35aab-fea5-4bce-9370-8db488077b3a.png">

## HW3 Mathematical Expression Problem
<img width="227" alt="image" src="https://user-images.githubusercontent.com/83395975/170953806-9f39f1e0-1083-45bf-b489-1bddfe8c9c96.png">

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
<img width="241" alt="image" src="https://user-images.githubusercontent.com/83395975/170953479-4a6ae04b-55e0-4983-8f95-5b2961fa262c.png">
