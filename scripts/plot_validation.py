import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

## reading result file
df = pd.read_csv("results/channel_final.csv")

## extract centerline
nx = 160
centre = nx // 2
line = df[df["x"] == centre]

## compute viscosity
tau = 0.8
nu = (tau - 0.5) / 3.0

## Analytical solution
Fy = 1e-6
H = 50.0         ## channel height
y = np.arange(H)
yPhysical = y + 0.5
u_exact = Fy/(2*nu) * yPhysical * (H - yPhysical)

## plot result
plt.figure(figsize=(6,5))
plt.plot(line["ux"], line["y"], "o", label="LBM")
plt.plot(u_exact, y, "-", label="Analytical")

plt.xlabel("Velocity")
plt.ylabel("y")

plt.legend()
plt.grid(True)

plt.tight_layout()

plt.savefig(
    "results/velocity_profile.png",
    dpi=300,
    bbox_inches="tight"
)

print("Saved results/velocity_profile.png")