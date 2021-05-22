import threading as th

th_even = th.Event()
th_odd  = th.Event()

def even_foo():
    global num
    global limit
    while num <= limit:
        th_even.wait() # true
        print('偶数：' + str(num))
        num += 1
        th_odd.set() # true
        th_even.clear() # false

def odd_foo():
    global num
    global limit
    while num <= limit:
        th_odd.wait()
        print('奇数：' + str(num))
        num += 1
        th_even.set()
        th_odd.clear()


if __name__ == '__main__':

    num = 0
    limit = 23

    t1 = th.Thread(target=even_foo)
    t2 = th.Thread(target=odd_foo)

    th_even.set()

    t1.start()
    t2.start()

    t1.join()
    t2.join()
