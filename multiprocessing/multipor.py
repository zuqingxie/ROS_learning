# in window and apple application is the multiprocedd avariable 
# but in linux is that not quite easy and everything looks different 
import multiprocessing
import time


start = time.perf_counter() # reletive time when the computer opens
print(start)
def do_something():
    print('start sleep')
    time.sleep(1) 
    print('sleeping for 1s')

p1 = multiprocessing.Process(target=do_something())
p2 = multiprocessing.Process(target=do_something())
p1.start()
p2.start()
p1.join()
p2.join()
# do_something()
# do_something()
# do_something()
finish = time.perf_counter() # reletive time when the computer opens

print(f'finish the executing, using time: {round(finish - start,2)}')