import heapq

def longestDiverseString(a: int, b: int, c: int) -> str:
    """
    Constructs the longest possible string that adheres to the "happy string" conditions.

    Args:
      a: The maximum number of 'a's allowed in the string.
      b: The maximum number of 'b's allowed in the string.
      c: The maximum number of 'c's allowed in the string.

    Returns:
      The longest possible "happy string".
    """
    result = []
    max_heap = []
    for count, char in [(-a, 'a'), (-b, 'b'), (-c, 'c')]:
        if count != 0:
            heapq.heappush(max_heap, (count, char))

    while max_heap:
        count, char = heapq.heappop(max_heap)
        if len(result) >= 2 and result[-1] == result[-2] == char:
            if not max_heap:
                break
            count2, char2 = heapq.heappop(max_heap)
            result.append(char2)
            count2 += 1
            if count2 != 0:
                heapq.heappush(max_heap, (count2, char2))
        else:
            result.append(char)
            count += 1
        if count != 0:
            heapq.heappush(max_heap, (count, char))

    return ''.join(result)

if __name__ == "__main__":
    test_cases = [
        (1, 1, 7),  # Example case
        (2, 2, 1),
        (7, 1, 0),
        (0, 0, 0)  # Edge case: empty string
    ]

    for a, b, c in test_cases:
        result = longestDiverseString(a, b, c)
        print(f"Input: a={a}, b={b}, c={c}, Output: {result}")