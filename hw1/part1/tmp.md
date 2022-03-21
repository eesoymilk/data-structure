$$
\def\arraystretch{1.2}\begin{array}{|c|c|c|c|c|c|c|c|c|c|c|c|}\hline
c[0]&c[1]&c[2]&\dotsm&c[n-a]&c[n-a+1]&c[n-a+2]&\dotsm&c[2n-2a+1]&c[2n-2a+2]&\dotsm&c[ab-an-bn-1]\\\hline
A_{a-1\:0}&A_{a\:1}&A_{a+1\:2}&\dotsm&A_{n-1\:n-a}&A_{a-2\:0}&A_{a-1\:1}&\dotsm&A_{n-1\:n-a+1}&A_{a-3\:0}&\dotsm&A_{n-b\:n-1}\\\hline\end{array}
$$

<!-- $$
\begin{aligned}
number\:of\:elememet\:in\:A_{n,a,b}&=n^2-\frac{(n-a)\times(n-a+1)}{2}-\frac{(n-b)\times(n-b+1)}{2}\\
&=\frac{-1}{2}a^2+\frac{-1}{2}b^2+an+bn-n+\frac{1}{2}a+\frac{1}{2}b\\
&=\frac{-1}{2}(a^2-a+b^2-b)+an+bn-n
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
&\text{Assume $\alpha$ is the base address for $a[0][0],\dots,[0]$, then}\\
&\text{the address for }a[i_1][i_2],\dots,[i_n]\text{ in column-major representation}\\
&=\alpha+i_1+u_1\Big(i_2+u_2\big(i_3+(\dotsm+i_nu_{n-1})\dotsm\big)\Big)\\
&=\alpha+\sum\limits_{j=1}^{n}\Bigg(\prod\limits_{k=1}^{j-1}u_k\Bigg)i_j\quad where\;\prod\limits_{k=1}^0u_k=1\\
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
&\text{Suppose all matrices are \ }n\times n.\\\\
&\text{In a general matrix addtion (operation+ in class Matrix):}\\
&\implies number\:of\:addition=n^2\\\\
&\text{In a general matrix multiplication (operation* in class Matrix):}\\
&\implies\begin{cases}
  number\:of\:addition&=n^3-n^2\\
  number\:of\:multiplication&=n^3
\end{cases}\\\\
&\text{For a complex-valued matrix multiplication,}\\
&\text{there are 4 general matrix multiplications,}\\
&\text{and 2 general matrix additions.}\\
&\text{Therefore, we have}\\
&\implies\begin{cases}
  number\:of\:addition&=4(n^3-n^2)+2n^2=4n^3-2n^2\\
  number\:of\:multiplication&=4n^3
\end{cases}\\
\end{aligned}
$$ -->

<!-- $$
\large\begin{aligned}
&\text{To move 1 disk to the right peg, we only need one step. Thus, T(1)=1.}\\\\
&\text{To move N disks to the right peg, we must first move N-1 disks to the middle peg.}\\
&\text{Then, move the most bottom disk to the right peg.}\\
&\text{This procedure takes T(N-1) + 1 steps.}\\
&\text{Lastly, we move N-1 disks in the middle to the right, which takes T(N-1) steps.}\\
&\text{In total, there are 2T(N-1) + 1 steps.}\\\\
&\text{Therefore we have \ }T(N)=2T(N-1)+1\; with\:T(1)=1
\end{aligned}
$$

$$
\begin{aligned}
\implies&T(N)-2T(N-1)=1\quad\\
&T(1)=1\\\\
&\textbf{Homogeneous Soultion: \ }T_h(N)\\
&T(N)-2T(N-1)=0\\
&characteristic\;equation:\quad r-2=0\implies r=2\\
&T_h(N)=\alpha2^n\quad\forall\;\alpha\in\reals\\\\
&\textbf{Particular Soultion: \ }T_p(N)\\
&Guess:T_p(N)=\beta\quad\forall\;\beta\in\reals\\
&T_p(N)-2T_p(N-1)=\beta-2\beta=-\beta=1\implies\beta=-1\\\\
&\textbf{Genearl Soultion: }T(N)=T_h(N)+T_p(N)\\
&T(N)=T_h(N)+T_p(N)=\alpha2^n-1\\
&\text{For the initial condition: \ }T(1)=1\\
&\implies T(1)=\alpha2^1-1=2\alpha-1=1\implies\alpha=1\\\\
&\textbf{Finally, we have \ }T(N)=2^n-1
\end{aligned}
$$

$$
\large\begin{aligned}
&\text{address for \ }a[i_1][i_2],\dots,[i_n]\text{ \ in column-major\:representation}=\\
&\alpha+\sum\limits_{j=1}^{n-2}i_ja_j+i_n\times u_{n-1} + i_{n-1}\quad where\;a_j=\prod\limits_{k=j+1}^nu_k\quad1\le j\le n-2
\end{aligned}
$$ -->
<!--
$$
\large\begin{array}{|c|c|c|c|c|}\hline
\text{line} & \text{s/e} & \text{frequency} & \text{step counts}\\\hline
\text{1} & 0 & - & 0  \\\hline
\text{2} & 0 & - & 0  \\\hline
\text{3} & 1 & m+1 & m+1 \\\hline
\text{4} & 1 & m(p+1) & mp+m \\\hline
\text{5} & 1 & mp & mp \\\hline
\text{6} & 1 & mp(n+1) & mpn+mp \\\hline
\text{7} & 1 & mpn & mpn \\\hline
\text{8} & 0 & - & 0 \\\hline
\text{9} & 0 & - & 0 \\\hline
\end{array}
$$

$$
\large Total\:Step\:Count=2mnp+3mp+2m+1
$$

$$
\large\begin{array}{|c|c|c|c|c|}\hline
\text{line} & \text{s/e} & \text{frequency} & \text{total steps}\\\hline
\text{1} & 0 & - & \Theta(0) \\\hline
\text{2} & 0 & - & \Theta(0) \\\hline
\text{3} & 1 & m+1 & \Theta(m) \\\hline
\text{4} & 1 & m(p+1) & \Theta(mp) \\\hline
\text{5} & 1 & mp & \Theta(mp) \\\hline
\text{6} & 1 & mp(n+1) & \Theta(mnp) \\\hline
\text{7} & 1 & mpn & \Theta(mnp) \\\hline
\text{8} & 0 & - & \Theta(0) \\\hline
\text{9} & 0 & - & \Theta(0) \\\hline
\end{array}
$$

$$
\large\begin{array}{|c|c|c|c|c|}\hline
\text{line} & \text{s/e} & \text{frequency} & \text{total steps}\\\hline
\text{1} & 0 & - & \Theta(0) \\\hline
\text{2} & 0 & - & \Theta(0) \\\hline
\text{3} & 1 & m+1 & \Theta(m) \\\hline
\text{4} & 1 & m(n+1) & \Theta(mn) \\\hline
\text{5} & 1 & mn & \Theta(mn) \\\hline
\text{6} & 1 & mn & \Theta(mn) \\\hline
\text{7} & 2 & mn & \Theta(mn) \\\hline
\text{8} & 0 & - & \Theta(0) \\\hline
\text{9} & 0 & - & \Theta(0) \\\hline
\text{10} & 1 & 1 & \Theta(1) \\\hline
\text{11} & 0 & - & \Theta(0) \\\hline
\end{array}
$$

$$
\def\arraystretch{2.2}\begin{array}{|c|c|c|c|c|c|c|c|c|c|c|c|}\hline\
c[0]&c[1]&c[2]&\dotsm&c[n-b]&c[n-b+1]&c[n-b+2]&\dotsm&c[2n-2b+1]&c[2n-2b+2]&\dotsm&c[ab-an-bn-1]\\\hline
A_{b-1\:0}&A_{b\:1}&A_{b+1\:2}&\dotsm&A_{n-1\:n-b}&A_{b-2\:0}&A_{b-1\:1}&\dotsm&A_{n-1\:n-b+1}&A_{b-3\:0}&\dotsm&A_{n-b\:n-1}\\\hline
\end{array}
$$ -->
