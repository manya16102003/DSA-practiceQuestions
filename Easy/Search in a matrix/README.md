<h2><a href="https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1">Search in a matrix</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a matrix <strong>mat</strong>[][] of size <strong>N</strong>&nbsp;x&nbsp;<strong>M</strong>, where every row and column is sorted in increasing order, and a number <strong>X</strong> is given. The task is to find whether element <strong>X</strong> is present in the matrix or not.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
N = 3, M = 3
mat[][] = 3 30 38 
         44 52 54 
         57 60 69
X = 62
<strong>Output</strong>:
0
<strong>Explanation</strong>:
62 is not present in the
matrix, so output is 0</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
N = 1, M = 6
mat[][]<strong> </strong>= 18 21 27 38 55 67
X = 55
<strong>Output</strong>:
1
<strong>Explanation</strong>:
55 is present in the
matrix at 5th cell.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. You just have to complete the function&nbsp;matSearch()&nbsp;which takes a 2D matrix&nbsp;<strong>mat</strong>[][],&nbsp;its dimensions <strong>N</strong> and <strong>M</strong> and integer <strong>X</strong> as inputs and returns 1 if the element <strong>X</strong> is present in the matrix and 0 otherwise.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity</strong>:&nbsp;O(N+M).<br>
<strong>Expected Auxiliary Space</strong>:&nbsp;O(1).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints</strong>:<br>
1 &lt;= N, M &lt;= 1005<br>
1 &lt;= mat[][] &lt;= 10000000<br>
1&lt;= X &lt;= 10000000</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Oracle</code>&nbsp;<code>Visa</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Directi</code>&nbsp;<code>Adobe</code>&nbsp;<code>SAP Labs</code>&nbsp;<code>Groupon</code>&nbsp;<code>InMobi</code>&nbsp;<code>One97</code>&nbsp;<code>Polycom</code>&nbsp;<code>TinyOwl</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Searching</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;