def find_subarray(t, test_cases):
    results = []

    for i in range(t):
        n = test_cases[i][0]
        glasses = test_cases[i][1]

        prefix_sum_odd = [0] * (n + 1)
        prefix_sum_even = [0] * (n + 1)

        for j in range(1, n + 1):
            prefix_sum_odd[j] = prefix_sum_odd[j - 1] + \
                glasses[j - 1] if j % 2 != 0 else prefix_sum_odd[j - 1]
            prefix_sum_even[j] = prefix_sum_even[j - 1] + \
                glasses[j - 1] if j % 2 == 0 else prefix_sum_even[j - 1]

        found = False
        start, end = None, None

        for s in range(1, n + 1):
            for e in range(s, n + 1):
                even_diff = prefix_sum_even[e] - prefix_sum_even[s - 1]
                odd_diff = prefix_sum_odd[e] - prefix_sum_odd[s - 1]

                if even_diff == odd_diff:
                    found = True
                    start, end = s, e
                    break

            if found:
                break

        results.append((start, end))

    return results


def main():
    t = int(input())
    test_cases = []

    for _ in range(t):
        n = int(input())
        glasses = list(map(int, input().split()))
        test_cases.append((n, glasses))

    results = find_subarray(t, test_cases)

    for start, end in results:
        if start is not None and end is not None:
            print(f"{start} {end}")
        else:
            print("NO")


if __name__ == "__main__":
    main()
