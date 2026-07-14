import pandas as pd
import matplotlib.pyplot as plt

# Load residual history
data = pd.read_csv("results/residual.csv")

plt.figure(figsize=(8,5))

plt.semilogy(
    data["Iteration"],
    data["Residual"],
    linewidth=2
)

plt.xlabel("Iteration")
plt.ylabel("Residual")
plt.title("LBM Convergence History")

plt.grid(True, which="both", linestyle="--")

plt.tight_layout()

plt.savefig("results/residual_history.png", dpi=300)
print("Saved results/residual_history.png")
