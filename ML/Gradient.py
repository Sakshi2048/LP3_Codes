# Import only when needed
import matplotlib.pyplot as plt

# Function and its derivative
def func(x):
    return (x + 3)**2

def gradient(x):
    return 2 * (x + 3)

# Gradient Descent parameters
x = 2                 # Starting point
learning_rate = 0.1   # Step size
iterations = 50       # Number of updates

# To store the path of x values
x_values = [x]
y_values = [func(x)]

# Gradient Descent algorithm
for i in range(iterations):
    grad = gradient(x)
    x = x - learning_rate * grad   # Update rule
    x_values.append(x)
    y_values.append(func(x))
    print(f"Iteration {i+1}: x = {x:.5f}, y = {func(x):.5f}")

# Final result
print("\nLocal minima occurs at x =", round(x, 5))
print("Minimum value of y =", round(func(x), 5))

# Plot
plt.plot(x_values, y_values, marker='o')

plt.title("Gradient Descent on y = (x + 3)²")

plt.xlabel("x values")
plt.ylabel("y values")

plt.grid(True)
plt.show()
