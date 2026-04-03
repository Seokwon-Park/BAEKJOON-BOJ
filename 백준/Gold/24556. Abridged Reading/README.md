# [Gold IV] Abridged Reading - 24556 

[문제 링크](https://www.acmicpc.net/problem/24556) 

### 성능 요약

메모리: 2196 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 트리, 트리에서의 다이나믹 프로그래밍

### 제출 일자

2026년 4월 3일 14:49:45

### 문제 설명

<p>Miss Othmar is a grade school teacher who uses a very interesting textbook in her science class.  All of the chapters in the book have material that depends on at most one previous chapter's material, while several chapters are labeled "Culminating Concept" chapters that have no chapters depending on them –-- they basically represent the culmination of the stream of material in all the previous chapters that must be read before them.  Chapters that are not Culminating Concept chapters are referred to as "prerequisite chapters."</p>

<p>Because of various delays caused by the pandemic, Miss Othmar is far behind where she wants to be in the class.  It's too late to try to cover all of the Culminating Concept chapters in the book (and their required prerequisite chapters) so she has decided to cover just two more Culminating Concept chapters.  To give the kids a break she has decided to pick the two Culminating Concept chapters which require the least amount of reading –-- this would include not only those chapters but their prerequisite chapters as well.</p>

### 입력 

 <p>Input starts with a line containing two integers $n$ $m$ where $n$ ($2 \leq n \leq 1\,000$) indicates the number of chapters (numbered $1$ to $n$) and $m$ ($0 \leq m < n$) indicates the number of chapter dependencies.  After this are $n$ positive values indicating the number of pages in each chapter. These values will be on one or more lines and the number of pages in any chapter is $ \leq 1\,000$.  After this are $m$ lines each containing two  integers $a$ $b$ $(1 \leq a < b \leq n)$ indicating that chapter $a$ must be read before chapter $b$.  No chapter appears as the second integer in these lines more than once.  There will be at least two Culminating Concept chapters.</p>

### 출력 

 <p>Output the minimum number of pages that need to be read in order to complete two Culminating Concept chapters.</p>

