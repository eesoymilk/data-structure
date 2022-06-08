$$
\begin{aligned}
  &P(u)=e^{\frac{-u}{n}}(1-e^{\frac{-uh}{m}})^h\\
  &\implies \ln\big(P(u)\big)=\frac{-u}{n}+h\ln(1-e^{\frac{-uh}{m}})\\\\
  &\begin{aligned}
    \frac{\delta\ln\big(P(u)\big)}{\delta h}&=\ln(1-e^{\frac{-uh}{m}})+h\cdot\frac{1}{1-e^{\frac{-uh}{m}}}\cdot(\frac{u}{m})e^{\frac{-uh}{m}}\\
    &=\frac{1}{P(u)}\cdot\frac{\delta P(u)}{\delta h}\\
  \end{aligned}\\
  &\implies \frac{\delta P(u)}{\delta h}=P(u)\cdot\bigg\{\ln(1-e^{\frac{-uh}{m}})+\frac{uh\cdot e^{\frac{-uh}{m}}}{m(1-e^{\frac{-uh}{m}})}\bigg\}\\\\
  &\because\frac{\delta P(u)}{\delta h}=0\enspace and\enspace P(u)\neq 0\enspace\\
  &\therefore\ln(1-e^{\frac{-uh}{m}})=\frac{-uh\cdot e^{\frac{-uh}{m}}}{m(1-e^{\frac{-uh}{m}})}\\\\
  &\text{Let }v=1-e^{\frac{-uh}{m}}\text{ , and we have }\ln(1-v)=\frac{-uh}{m}.\\
  &\implies\ln(v)=\frac{(1-v)\ln(1-v)}{v}\\
  &\implies v\ln(v)=(1-v)\ln(1-v)\\
  &\implies v=1-v\\
  &\implies v=\frac{1}{2}=1-e^{\frac{-uh}{m}}\\
  &\implies {\frac{-uh}{m}}=-\ln2\\
  &\implies \bold{h=\frac{u}{m}\ln2}
\end{aligned}
$$

<!-- $$
\begin{aligned}
  &\textbf{One-way-property:}\\
  &\quad\begin{aligned}
    &\text{For a given hash code }c,\text{ we can easily find a }\\&k=c+17n\enspace where\ n\isin\Z\text{ such that } h(k)=c.\\
    &\implies h(k)=k\%17\textbf{ does not satisfy one-way-property.}
  \end{aligned}\\\\
  &\textbf{Weak collision resistance:}\\
  &\quad\begin{aligned}
    &\text{Given the hash function }h(k)=k\%17\text{ and the original message }M,\\
    &\text{we can easily find a } M'=M+17n\enspace n\isin\Z-\{0\}\\
    &\text{such that }h(M')=h(M).\\
    &\implies h(k)=k\%17\textbf{ does not weak collision resistance.}
  \end{aligned}\\\\
  &\textbf{Strong collision resistance:}\\
  &\quad\begin{aligned}
    &\text{It is easy to find a pair }(x,x+17n)\enspace where\ x,n\isin\Z\ and\ n\neq0\\
    &\text{such that }h(x)=h(x+17n).\\
    &\implies h(k)=k\%17\textbf{ does not satisfy strong collision resistance.}
  \end{aligned}\\\\
  &\text{Therefore, }h(k)=k\%17\textbf{ does not satisfy any properties.}
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &\textbf{One-way-Property:}\\
  &\quad\begin{aligned}
    &\text{For a given hash code }c,\text{ it is computationally difficult}\\
    &\text{to find a }k\text{ such that } h(k)=c.
  \end{aligned}\\\\
  &\textbf{Weak collision resistance:}\\
  &\quad\begin{aligned}
    &\text{Given the hash function }h\text{ and the original message }M,\\
    &\text{it is computationally difficult to find a } M'\neq M\\
    &\text{such that }h(M')=h(M).
  \end{aligned}\\\\
  &\textbf{Strong collision resistance:}\\
  &\quad\begin{aligned}
    &\text{It is computationally difficult to find a pair }(x,y)\\
    &\text{such that }h(x)=h(y).
  \end{aligned}
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &\text{Since }K_i = K^1_i\times n+K^2_i,
  \text{ we have }\\
  &\begin{cases}
    &K^1_i=\lfloor\frac{K_i}{n}\rfloor\\
    &K^2_i = K_i\bmod n
  \end{cases}\quad for\quad
  \begin{aligned}
    &K^1_i,K^2_i\isin\N\\
    &0\leq K^1_i,K^2_i\lt n
  \end{aligned}\\\\
  &\text{We can now perform Radix Sort with respect to these two keys, }K^1, K^2.\\
  &\text{Also, for our algorithm, }d=2,r=n,
  \text{ and we know that}\\
  &\text{the time complexity of a radix sort is }O(d(n+r)).\\\\
  &\text{Therefore, the time complexity of our algorithm is given by}\\
  &\quad O(d(n+r))=O(2(n+n))=O(n)
\end{aligned}
$$ -->

<!-- $$
\begin{aligned}
  &\text{Consider this list, } l=[3, 2, 1_a, 1_b], \text{with duplicate keys,}\\
  &\text{and for the duplicate 1's, we label them }1_a\ and\ 1_b.\\
  &\text{We perform quick sort on this list; then we have, }\\
  &\quad l=[\bold{1_b}, \bold{1_a}, 2, 3].\\\\
  &\text{Since the order of 1's is not preserved,}\\
  &\text{we therefore conclude that quicksort is unstable.}
\end{aligned}
$$ -->

<!-- $$
\begin{array}{|c|c|c|c|c|c|c|c|c|c|c|c|c|}\hline
  R_1& R_2& R_3& R_4& R_5& R_6& R_7& R_8& R_9& R_{10}& R_{11}&left &right\\\hline
  \boldsymbol[12 & 2& 16&  30& 8 & 28& 4& 10& 20& 6& 18\boldsymbol] & 1 & 11\\\hline
  \boldsymbol[4  & 2&  6&  10& 8\boldsymbol]& 12& \boldsymbol[28& 30& 20 & 16& 18\boldsymbol] & 1 & 5\\\hline
  2   & 4& \boldsymbol[6&  10& 8\boldsymbol]& 12& \boldsymbol[28& 30& 20 & 16& 18\boldsymbol] & 3 & 5\\\hline
  2   & 4&  6& \boldsymbol[10& 8\boldsymbol]& 12& \boldsymbol[28& 30& 20 & 16& 18\boldsymbol] & 4 & 5\\\hline
  2   & 4&  6&   8& 10& 12& \boldsymbol[28& 30& 20 & 16& 18\boldsymbol] & 7 & 11\\\hline
  2   & 4&  6&   8& 10& 12& \boldsymbol[16& 18& 20\boldsymbol]& 28& 30  & 7 & 9\\\hline
  2   & 4&  6&   8& 10& 12& 16& \boldsymbol[18& 20\boldsymbol]& 28& 30  & 8 & 9\\\hline
  2   & 4&  6&   8& 10& 12& 16& 18& 20& 28& 30  &  & \\\hline
\end{array}
$$ -->

<!-- $$
\begin{array}{|c|c|c|c|c|c|c|c|c|c|c|c|}\hline
  j& [1]& [2]& [3]& [4]& [5]& [6]& [7]& [8]& [9]& [10]& [11]\\\hline
  1&  \bold{12}& 2& 16& 30& 8& 28& 4& 10& 20& 6& 18\\\hline
  2&  \bold{2} & \bold{12}& 16& 30& 8& 28& 4& 10& 20& 6& 18\\\hline
  3&  \bold{2} & \bold{12}& \bold{16}& 30& 8& 28& 4& 10& 20& 6& 18\\\hline
  4&  \bold{2} & \bold{12}& \bold{16}& \bold{30}& 8& 28& 4& 10& 20& 6& 18\\\hline
  5&  \bold{2} & \bold{8} & \bold{12}& \bold{16}& \bold{30}& 28& 4& 10& 20& 6& 18\\\hline
  6&  \bold{2} & \bold{8} & \bold{12}& \bold{16}& \bold{28}& \bold{30}& 4& 10& 20& 6& 18\\\hline
  7&  \bold{2} & \bold{4} & \bold{8} & \bold{12}& \bold{16}& \bold{28}& \bold{30}& 10& 20& 6& 18\\\hline
  8&  \bold{2} & \bold{4} & \bold{8} & \bold{10}& \bold{12}& \bold{16}& \bold{28}& \bold{30}& 20& 6& 18\\\hline
  9&  \bold{2} & \bold{4} & \bold{8} & \bold{10}& \bold{12}& \bold{16}& \bold{20}& \bold{28}& \bold{30}& 6& 18\\\hline
  10& \bold{2} & \bold{4} & \bold{6} & \bold{8} & \bold{10}& \bold{12}& \bold{16}& \bold{20}& \bold{28}& \bold{30}& 18\\\hline
  11& \bold{2} & \bold{4} & \bold{6} & \bold{8} & \bold{10}& \bold{12}& \bold{16}& \bold{18}& \bold{20}& \bold{28}& \bold{30}\\\hline
\end{array}
$$ -->
