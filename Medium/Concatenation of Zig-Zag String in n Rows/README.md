<h2><a href="https://www.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows0308/1">Concatenation of Zig-Zag String in n Rows</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when the input string is written in row-wise Zig-Zag fashion.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: 
str = "ABCDEFGH"
n = 2
<strong>Output:</strong> "ACEGBDFH"
<strong>Explanation:</strong> 
Let us write input string in 
Zig-Zag fashion in 2 rows.
A   C   E   G  
  B   D   F   H
Now concatenate the two rows and ignore 
spaces in every row. We get "ACEGBDFH"</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
str = "GEEKSFORGEEKS"
n = 3
<strong>Output:</strong> GSGSEKFREKEOE
<strong>Explanation:</strong> 
Let us write input string in 
Zig-Zag fashion in 3 rows.
G       S       G       S
  E   K   F   R   E   K
    E       O       E
Now concatenate the two rows and ignore spaces
in every row. We get "GSGSEKFREKEOE"</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You need not&nbsp;read input or print anything. Your task is to complete the function&nbsp;<strong>convert()&nbsp;</strong>which takes 2 arguments(string str, integer n) and returns the resultant string.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(|str|).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(|str|).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>PayPal</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;