At Harie University, you must pass a course registration code of conduct quiz before using the course registration system.

The quiz has 10
 multiple choice questions, with four options ('A', 'B', 'C', 'D') for each. There is only one correct answer for each question. Each correct answer gives 10
 points, and wrong answers give no points. A perfect score (100
) is required to pass the quiz. You may attempt the quiz multiple times, and the set of questions for each quiz remains unchanged. When you complete the quiz, the system will tell you the final score, but it won't tell you whether your answer is correct for individual questions.

You have failed the quiz for quite a lot of times, and are wondering how many possible answers there are according to the previous observations. More specifically, given the chosen options and scores of prior quiz attempts, count the number of remaining possible answers out of all option combinations.

It is guaranteed that the input data is consistent, i.e. there is at least one possible answer.

Input
The input consists of several independent test cases. The first line contains an integer t
 (1≤t≤20000
), which is the number of test cases.

For each test case, the first line contains an integer n
 (1≤n≤20000
) – the number of quizzes. The following n
 lines describe the results of these quizzes. Each line contains a string s
 (|s|=10
, si∈{'\t{A}','\t{B}','\t{C}','\t{D}'}
) and an integer a
 (0≤a≤90
, a
 is a multiple of 10
), separated by a space. The i
-th character of s
 denotes the chosen option of the i
-th question, and a
 is the quiz score.

The sum of all n
 in an input file will not exceed 20000
.

Output

For each test case, output an integer – the number of possible answers.

Example
inputCopy
3
1
CCCCCCCCCC 90
2
AAAAAAAAAA 10
ABCDABCDAB 20
3
AAAAAAAAAA 0
BBBBBBBBBB 0
CCCCCCCCCC 0
outputCopy
30
57456
1