# Solution

$$\frac{\texttt{acc}(o\rightarrow n)}{\texttt{acc}(n\rightarrow o)}=\frac{\exp[-\beta_i U(j)-\beta_j U(i)]}{\exp[-\beta_i U(i)-\beta_j U(j)]}=\exp((\beta_i-\beta_j)[U(i)-U(j)])$$

The particles are able to diffuse when $T\geq 0.025$.
![](Results/pos.png)

Below are the results of having exchange moves:

![](Results/dist0.png)
![](Results/dist1.png)
![](Results/dist2.png)
![](Results/dist3.png)

The system with the lowest energy passes the barrier when there are three system. This is reasonable, because there is no energy distribution overlapping between the system with the highest energy and the system with the lowest energy.

![](Results/energy.png)

The equilibrium distribution with and without exchange moves are identical:

![](Results/identical.png)