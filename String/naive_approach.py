def naive_approach(s, p):
    len_p   = len(p)
    len_s_p = len(s) - len_p + 1
    count = 0
    match = False
    for i in range(len_s_p):
        count += 1
        if s[i] == p[0]:
            for j in range(1, len_p):
                count += 1
                if s[i+j] != p[j]:                    
                    break
                if j == len_p - 1:
                    match = True
                    break
            if match:
                break
    print("number of comparisons", count)
    if match:
        return i, s[i:i+len_p]
    else:
        return -1
    
if __name__ == "__main__":
    s = "dream on until your dreams come true"
    print(naive_approach(s, "ti"))
    
