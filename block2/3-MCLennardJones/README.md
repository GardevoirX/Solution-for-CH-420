# Solution

Below is the table and figure for the pressure versus density at $T=2$:

|Density |Pressure |
|--------|---------|
|0.1     |0.214    |
|0.2     |0.440    |
|0.3     |0.643    |
|0.4     |0.789    |
|0.5     |0.727    |
|0.6     |0.354    |
|0.7     |-0.639   |
|0.8     |-2.524   |
|0.9     |-5.986   |
|1.0     |-12.11   |
|1.2     |-35.57   |
|1.4     |-91.12   |
|1.6     |-203.3   |
|2.0     |-722.6   |
|2.2     |-1220    |
|2.6     |-2986    |
|3.0     |-6333    | 

![](Results/pd.png)

It can be seen that the ideal gas law holds at $\rho \in [0.1,\ 0.4]$.

The heat capacity $C_V=\frac{\left<U^2\right>-\left<U\right>^2}{Nk_BT^2}$ has a dimension of $J/K$. Thus, to make it a dimensionless, we can simply divide it by $k_B$:
$$C_V^*=\frac{\left<U^2\right>-\left<U\right>^2}{Nk_B^2T^2}=\frac{\left<U^2\right>-\left<U\right>^2}{N}\beta^2$$