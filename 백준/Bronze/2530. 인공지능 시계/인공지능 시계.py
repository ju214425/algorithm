h, m, s = map(int, input().split())
t = int(input())

h_ = t // 3600
t -= (3600 * h_)
m_ = t // 60
t -= (60 * m_)
s_ = t % 60

h += h_
m += m_
s += s_

if s >= 60:
    s -= 60
    m += 1

if m >= 60:
    m -= 60
    h += 1

h %= 24

print(h, m, s)