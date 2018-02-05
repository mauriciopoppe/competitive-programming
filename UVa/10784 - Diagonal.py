from sys import stdin, stdout


def fn(n):
    res = (n - 3) + (n - 3) * (n - 2) // 2
    # stdout.write("{}".format(res))
    return res


def main():
    lmax = 1e15
    mx = (lmax - 3) + (lmax - 3) * (lmax - 2) // 2
    cas = 1

    while(True):
        k = int(stdin.readline())
        if k == 0:
            break
        lo = 0
        hi = mx
        while (hi - lo > 1):
            mid = lo + (hi - lo) // 2
            if fn(mid) >= k:
                hi = mid
                if fn(mid) == k:
                    break
            else:
                lo = mid
        stdout.write("Case {}: {}\n".format(cas, int(hi)))
        cas += 1


if __name__ == '__main__':
    main()
