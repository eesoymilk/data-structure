$$
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
$$

<!-- $$
\begin{aligned}
  inorder&:HDJBEAFCG\\
  preorder&:ABDHJECFG\\
  postorder&:HJDEBFGCA
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  inorder&:A-B*C*D+E\\
  preorder&:+**-ABCDE\\
  postorder&:AB-C*D*E+
\end{aligned}
$$ -->

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
