<!-- $$
\begin{aligned}
  &\text{Since only need to perform bubbling down for }level\ 1\ to\ h-1,\\
  &\text{for each level, there are at most }2^{j-1}\ nodes,\\
  &\text{and each node might bubbles down }h - j\ levels,\\
  &\text{the total time is}\\
  &\quad\begin{aligned}
    &=\sum\limits_{j=1}^{h-1}2^{j-1}(h-j)
    =\sum\limits_{i=1}^{h-1}2^{h-j}\times i
    =\sum\limits_{i=1}^{h-1}\frac{i2^h}{2^i}\\
    &=2^h\sum\limits_{i=1}^{h-1}\frac{i}{2^i}
    \leq2^h\sum\limits_{i=0}^{\infty}\frac{i}{2^i}
    =2^h\times2
    =2^{h+1}=O(n)
  \end{aligned}\\
  &\text{Therefore, }
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &t(j)\text{ is the time needed to perform bubuling down for j-th level,}\\
  &\text{and we only need to perform such tacks for }level\ 1\ to\ h-1.\\
  &\text{Therefore, the total time is}\\
  &\quad\begin{aligned}
    &t(1)+t(2)+\dotsm+t(h-1)\\
    &=\sum\limits_{j=1}^{h-1}t(j)
    =\sum\limits_{j=1}^{h-1}2^{j-1}(h-j)
    =\sum\limits_{j=1}^h2^{j-1}(h-j)\\
    &=\sum\limits_{i=0}^{h-1}2^{h-i-1}\times i
    =\sum\limits_{i=1}^{h-1}\frac{i2^{h-1}}{2^i}
    =2^{h-1}\sum\limits_{i=1}^{h-1}\frac{i}{2^i}\\
    &\leq2^{h-1}\sum\limits_{i=0}^{\infty}\frac{i}{2^i}=2^{h-1}\times2=2^h=n+1=O(n)
  \end{aligned}\\
  &\text{Therefore, }t(1)+t(2)+\dotsm+t(h-1)=O(n).
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &\text{Since internal vertices of a complete d-mary tree all have d children,}\\
  &\text{we will formulate parent of node i as normal, and j-th child for node i.}\\
    &\begin{aligned}
      parent(i)&=\lfloor\frac{i+d+2}{d}\rfloor\\
      child(i, j)&=di+d+j+1\quad if\:
      \begin{cases}
        &1\leq j\leq d\\
        &di+d+j+1 \leq n
      \end{cases}
    \end{aligned}
\end{aligned}
$$ -->

<!-- $$
\large\begin{aligned}
  &\text{For initializing a max heap from n key values stored in an array,}\\
  &\text{instead of inserting key value one by one, assume that}\\
  &\begin{aligned}
    \quad&\text{The height of heap } = h,\\
    &\text{Number of subtrees with root at level j is } \leq 2^{j-1},\\
    &\text{Time for each subtree is } O(h-j). \text{ (\# of bubbling down),}\\
    &\text{Time for level j subtrees is }\leq 2^{j-1}(h-j) = t(j),
  \end{aligned}\\
  &\text{Then total time is }t(1)+t(2)+\dotsm+t(h-1)=O(n)\\
  &\text{Please prove the above argument.}
\end{aligned}
$$ -->

$$
\begin{aligned}
  inorder&:HDJBEAFCG\\
  preorder&:ABDHJECFG\\
  postorder&:HJDEBFGCA\\
  levelorder&:ABCDEFGHJ
\end{aligned}
$$

$$
\begin{aligned}
  inorder&:A-B*C*D+E\\
  preorder&:+**-ABCDE\\
  postorder&:AB-C*D*E+\\
  levelorder&:+*E*D-CAB
\end{aligned}
$$

<!-- $$
\begin{array}{|c|c|c|c|c|c|c|c|c|}\hline
0&1&2&3&4&5&6&7&8\\\hline
&A&B&&C&D&&&E\\\hline
\end{array}
$$ -->

<!-- $$
\begin{aligned}
  &\text{The maximum number of nodes is obtained when the tree is full,}\\
  &\text{and when the tree is full, we have the number of nodes equal to}\\
  &k^0+k^1+k^2+\dotsm+k^{h-1} = \sum\limits_{i=0}^{h-1}k^i = \frac{k^h-1}{k-1}
\end{aligned}
$$ -->
