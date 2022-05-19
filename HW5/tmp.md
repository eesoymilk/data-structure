$$
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
$$

<!-- $$
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
  &\text{By definition of partial order,}\\
  &a\ \R\ b \implies a=b\quad where\ \R\ denotes\ a\ partial\ order\\\\
  &Since\ 0<4\ and\ 0\neq4,\ it\ is\ not\ a\ partial\ order.
\end{aligned}
$$ -->

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

<!-- $$
\begin{aligned}
  &\text{Euler's theorem states that a graph G has an Eulerian walk}\\
  &\text{if and only if G is connected and each vertex in G has even degree.}\\\\
  &\text{The Eulerian walk of the given mutigraph: }\\
  &0\to1\to0\to2\to3
\end{aligned}
$$ -->
