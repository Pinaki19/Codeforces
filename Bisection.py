def bisection_method(func, a, b, tol):
    """
    :param func: The target function.
    :param a: Left endpoint of the interval.
    :param b: Right endpoint of the interval.
    :param tol: Tolerance level for convergence.
    :return: Approximation of the root.
    """
    # Check if the interval contains a root
    if func(a) * func(b) > 0:
        raise ValueError(
            "The function values at the endpoints must have opposite signs.")
    iteration = 0
    while (b - a) / 2 > tol:
        iteration += 1
        c = (a + b) / 2
        if func(c) == 0:    #this is an Exact root
            break  
        elif func(c) * func(a) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2,iteration

def function_1(x):
    return x**2 - 4
def function_2(x):
    return x**3 - 6*x**2 + 11*x - 6

intervals = [(-1, 6), (-1, 200)]  # will be tested on these two intervals
tolerances = [1e-8, 1e-12, 1e-15] #each interval will use these tolerances

print("\n\t\tTarget Functions used: \n\t\t function_1 : x^2 - 4 \
    \n\t\t function_2 : x^3 - 6*x^2 + 11*x - 6")

# Apply the Bisection Method
for a, b in intervals:
  print(f"\n\t\t\t\tInterval: [{a}, {b}]\n")
  for func in [function_1,function_2]:
    for tolerance in tolerances:
      root_appx,n=bisection_method(func, a, b, tolerance)
      print(
      f"Target: {func.__name__}, Tolerance: {tolerance},Approx Root: {root_appx},Iterations: {n}")
