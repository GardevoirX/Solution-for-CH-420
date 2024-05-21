# Solution

We know that the area of a square of length $l$ is $l^2$ and the area of a circle of diameter $d$ is $\frac{\pi d^2}{4}$. Thus the probability of a randomly dropped point fall in the circle is

$$P=\frac{\pi d^2}{4 l^2}=\frac{\pi}{4 ratio^2}$$

By calculate the ratio of the number of points fall in the circle and the number of the whole points, we can calculate the $\pi$.

There is an optimal ratio $l/d$ and the larger the number of generated coordinates, the more accurate the result is.

This algorithm can be described by a binomial distribution $B(n, P)$, whose mean is $nP$ and the variance is $nP(1-P)$. Here the $n$ means the # of generated point and $P$ is the probability metioned above. To minimize the variance, we require its derivative equals zero:

$$ n(1-P)-nP=n-2nP=0$$

and the result is $P=\frac{1}{2}$. Thus the optimal ratio is $\sqrt{\frac{\pi}{2}}$.

This method can provide us with a approximation of the $\pi$, but is not a good way to calculate the $\pi$ accurately, because its value converge to the exact value of $\pi$ in probability. That is to say, no matter how many points we drop, it is still possible that there is a large deviation from the exact value.
