class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        if len(haystack) < len(needle):
            return -1

        for i in range(len(haystack)):
            if haystack[i : i + len(needle)] == needle:
                return i

        return -1


def main():
    haystack = "hello"
    needle = "ll"
    solution = Solution()
    result = solution.strStr(haystack, needle)
    print(result)


if __name__ == "__main__":
    main()
