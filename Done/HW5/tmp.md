<!-- $$
\begin{array}{|c|c|c|}\hline
  First&Last&Simple\ Path\\\hline
  0&0&0\\\hline
  0&0&0\to3\to2\to0\\\hline
  0&0&0\to1\to2\to0\\\hline
  0&1&0\to1\\\hline
  0&2&0\to1\to2\\\hline
  0&2&0\to3\to2\\\hline
  0&3&0\to3\\\hline
  1&0&1\to2\to0\\\hline
  1&1&1\\\hline
  1&1&1\to2\to0\to1\\\hline
  1&2&1\to2\\\hline
  1&3&1\to2\to0\to3\\\hline
  2&0&2\to0\\\hline
  2&1&2\to0\to1\\\hline
  2&2&2\\\hline
  2&2&2\to0\to1\to2\\\hline
  2&2&2\to0\to3\to2\\\hline
  2&3&2\to0\to3\\\hline
  3&0&3\to2\to0\\\hline
  3&1&3\to2\to0\to1\\\hline
  3&2&3\to2\\\hline
  3&3&3\\\hline
  3&3&3\to2\to0\to3\\\hline
\end{array}
$$ -->

<!-- $$
\begin{aligned}
  &\text{No, it is not unique because}\\
  &\text{there is a second one as shown below.}
\end{aligned}
$$ -->

<!-- $$
\cos^3\alpha=\frac{1}{4}\cos\alpha+\frac{3}{4}\cos3\alpha
$$ -->
<!-- $$
\begin{aligned}
  &\text{Since }a_2,\ a_4,\ and\ a_{14}\ \text{are on all critical paths,}\\
  &\text{any one of whose speed-up can reduce the project finish time.}
\end{aligned}
$$ -->
<!-- $$
\begin{aligned}
  &\text{Since Dijkstra's algorithm only works on nonnegative weights,}\\
  &\text{and this graph has a weight of -2, the algorithm will not work properly.}\\\\
  &Shortest\ path\ between\ vertices\ 0\ and\ 6:\ 0\to2\to1\to3\to4\to6\\
  &Total\ weight:\ 8
\end{aligned}
$$ -->
<!-- $$
\begin{array}{|c|c|c|c|c|}\hline
  Activity&Early\ Time\ e(a_i)&Late\ Time\ l(a_i)&Slack\ l(a_i)-e(a_i)&Critical\\\hline
  a_1   &0  &4  &4&\times\\\hline
  a_2   &0  &0  &0&\circ\\\hline
  a_3   &5  &9  &4&\times\\\hline
  a_4   &6  &6  &0&\circ\\\hline
  a_5   &6  &12 &6&\times\\\hline
  a_6   &12 &12 &0&\circ\\\hline
  a_7   &12 &15 &3&\times\\\hline
  a_8   &12 &12 &0&\circ\\\hline
  a_9   &15 &15 &0&\circ\\\hline
  a_{10}&15 &15 &0&\circ\\\hline
  a_{11}&16 &16 &0&\circ\\\hline
  a_{12}&19 &19 &0&\circ\\\hline
  a_{13}&16 &19 &3&\times\\\hline
  a_{14}&21 &21 &0&\circ\\\hline
\end{array}
$$ -->

$$
\begin{aligned}
  &\text{By transitivity of partial order, we have}\\
  &\begin{rcases}
    0<1\\
    1<2\\
    2<4
  \end{rcases}\implies
  \begin{rcases}
    0<2\\
    2<4
  \end{rcases}\implies0<4\\
  &\begin{rcases}
    a\ \R\ b \\
    b\ \R\ a 
  \end{rcases}\implies a=b\quad where\ \R\ denotes\ a\ partial\ order\\\\
  &Since\ 0<4,\ 4<0,\ and\ 0\neq4,\ it\ is\ not\ a\ partial\ order.
\end{aligned}
$$

<!-- $$
\begin{aligned}
  &\text{Yes, it is strongly connected.}\\
  &Simple\ Path\ \#1:\ 0\to3\to2\to0\\
  &Simple\ Path\ \#2:\ 0\to1\to2\to0\\
\end{aligned}
$$ -->
<!-- $$
\begin{aligned}
  &DFS:\ 0\to1\to2\to3\\
  &BFS:\ 0\to1\to2\to3\\
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &\begin{array}{c}
    0&1&2&3&4&5
  \end{array}\\
  \begin{array}{c}
    0\\1\\2\\3\\4\\5
  \end{array}&
  \begin{bmatrix}
    0&0&0&0&0&0\\
    1&0&0&1&0&0\\
    0&1&0&0&0&1\\
    0&0&1&0&1&1\\
    1&0&0&0&0&0\\
    1&1&0&0&1&0
  \end{bmatrix}
\end{aligned}
$$ -->
