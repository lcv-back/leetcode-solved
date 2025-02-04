class Solution:
    def myAtoi(self, s: str) -> int:
        # 1. ignore any leading whitespace
        s = s.lstrip()

        # 2. check sign
        if len(s) == 0:
            return 0

        sign = 1
        if s[0] == "-" or s[0] == "+":
            if s[0] == "-":
                sign = -1
            s = s[1:]

        # 3. read until not digit
        num = ""
        for c in s:
            if c.isdigit():
                num += c
            else:
                break

        if len(num) == 0:
            return 0

        # 4. convert
        ans = int(num) * sign

        print(ans)

        if ans < -(2**31):
            ans = -(2**31)
        if ans > 2**31 - 1:
            ans = 2**31 - 1

        return ans


def main():
    s = "     -042"
    solution = Solution()
    result = solution.myAtoi(s)
    print(result)  # Output: -42


if __name__ == "__main__":
    main()
