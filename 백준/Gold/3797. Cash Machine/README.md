# [Gold III] Cash Machine - 3797 

[문제 링크](https://www.acmicpc.net/problem/3797) 

### 성능 요약

메모리: 2508 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2026년 3월 19일 15:36:54

### 문제 설명

<p>A Bank plans to install a machine for cash withdrawal. The machine is able to deliver appropriate ♣ bills for a requested cash amount. The machine uses exactly N distinct bill denominations, say D<sub>k</sub>, k=1,N, and for each denomination D<sub>k</sub> the machine has a supply of n<sub>k</sub> bills. For example,</p>

<p style="text-align: center;">N=3, n<sub>1</sub>=10, D<sub>1</sub>=100, n<sub>2</sub>=4, D<sub>2</sub>=50, n<sub>3</sub>=5, D<sub>3</sub>=10</p>

<p>means the machine has a supply of 10 bills of ♣100 each, 4 bills of ♣50 each, and 5 bills of ♣10 each.</p>

<p>Call cash the requested amount of cash the machine should deliver and write a program that computes the maximum amount of cash less than or equal to cash that can be effectively delivered according to the available bill supply of the machine.</p>

### 입력 

 <p>Each data set in the file stands for a particular transaction and has the format:</p>

<p style="text-align: center;">cash N n<sub>1</sub> D<sub>1</sub> n<sub>2</sub> D<sub>2</sub> ... n<sub>N</sub> D<sub>N</sub></p>

<p>where 0 ≤ cash ≤ 100000 is the amount of cash requested, 0 ≤ N ≤ 10 is the number of bill denominations and 0 ≤ n<sub>k</sub> ≤ 1000 is the number of available bills for the D<sub>k</sub> denomination, 1 ≤ D<sub>k</sub> ≤ 1000, k=1,N. White spaces can occur freely between the numbers in the input. The input data are correct.</p>

### 출력 

 <p>For each set of data the program prints the result to the standard output on a separate line.</p>

