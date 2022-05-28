# this the the time counter to count the time we use to excute the algo 
import time
from turtle import st

start = time.perf_counter() # reletive time when the computer opens
print(start)
def do_something():
    print('start sleep')
    time.sleep(1) 
    print('sleeping for 1s')
do_something()
do_something()
do_something()
finish = time.perf_counter() # reletive time when the computer opens

print(f'finish the executing, using time: {round(finish - start,2)}')