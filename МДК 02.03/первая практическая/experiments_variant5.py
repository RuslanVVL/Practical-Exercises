# Серии компьютерного эксперимента для варианта 5
import numpy as np
import matplotlib.pyplot as plt

BASE_A = 1.2
BASE_K = 150_000.0
BASE_N0 = 8_000.0
T = 30

A_VALUES = [0.7, 1.0, 1.2, 1.4, 1.9, 2.3, 2.7, 2.9]
N0_VALUES = [1_000, 8_000, 50_000, 100_000, 160_000]
K_VALUES = [75_000, 120_000, 150_000, 200_000, 250_000]

def simulate(a, K, N0, T=T):
    N = np.zeros(T + 1)
    N[0] = N0
    for t in range(T):
        N[t + 1] = N[t] + a * N[t] * (1.0 - N[t] / K)
    return N

def t95(N, K):
    idx = np.where(N >= 0.95 * K)[0]
    return int(idx[0]) if len(idx) else None

experiments = []

for a in A_VALUES:
    n = simulate(a, BASE_K, BASE_N0)
    experiments.append(("1: a", a, BASE_K, BASE_N0, t95(n, BASE_K)))

for n0 in N0_VALUES:
    n = simulate(BASE_A, BASE_K, n0)
    experiments.append(("2: N0", BASE_A, BASE_K, n0, t95(n, BASE_K)))

for k in K_VALUES:
    n = simulate(BASE_A, k, BASE_N0)
    experiments.append(("3: K", BASE_A, k, BASE_N0, t95(n, k)))

print("Серия | a | K | N0 | t*(0.95K)")
for e in experiments:
    print(*e, sep=" | ")

fig, ax = plt.subplots(figsize=(8, 4.8))
for a in A_VALUES:
    n = simulate(a, BASE_K, BASE_N0)
    ax.plot(range(T + 1), n / BASE_K, label=f"a={a}")
ax.axhline(1, ls="--", lw=1)
ax.set(xlabel="Месяц t", ylabel="N(t) / K", title="Серия 1: влияние коэффициента прироста a")
ax.legend(ncol=2, fontsize=8)
ax.grid(alpha=0.25)
fig.tight_layout()
fig.savefig("series1_variant5.png", dpi=180)

fig, ax = plt.subplots(figsize=(8, 4.8))
for n0 in N0_VALUES:
    n = simulate(BASE_A, BASE_K, n0)
    ax.plot(range(T + 1), n, label=f"N0={n0}")
ax.axhline(BASE_K, ls="--", lw=1, label="K")
ax.set(xlabel="Месяц t", ylabel="N(t)", title="Серия 2: влияние начального состояния N0")
ax.legend(fontsize=8)
ax.grid(alpha=0.25)
fig.tight_layout()
fig.savefig("series2_variant5.png", dpi=180)

fig, ax = plt.subplots(figsize=(8, 4.8))
for k in K_VALUES:
    n = simulate(BASE_A, k, BASE_N0)
    ax.plot(range(T + 1), n, label=f"K={k}")
ax.set(xlabel="Месяц t", ylabel="N(t)", title="Серия 3: влияние ёмкости рынка K")
ax.legend(fontsize=8)
ax.grid(alpha=0.25)
fig.tight_layout()
fig.savefig("series3_variant5.png", dpi=180)
