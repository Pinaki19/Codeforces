def digit_sum(n):
    return sum(int(digit) for digit in str(n))


def sum_of_digit_sums(n):
    # Calculate the sum of digit sums for numbers from 1 to 9
    sum_1_to_9 = sum(range(1, 10))
    # Calculate the number of full cycles of 10
    full_cycles = n // 10
    # Calculate the sum contributed by full cycles of 10
    total = full_cycles * sum_1_to_9 * 10
    # Calculate the remaining numbers after the last full cycle
    remaining_numbers = n % 10
    # Add the sum of digit sums for the remaining numbers
    total += sum(range(1, remaining_numbers + 1))
    return total

t=int(input())
while t:
    t-=1
    n=int(input())
    print(sum_of_digit_sums(n))