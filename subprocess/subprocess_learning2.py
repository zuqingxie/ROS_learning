from re import sub
import subprocess

# trying to use the result of another process!!!!!!!!!
p1 = subprocess.run(['cat','test.txt'],capture_output=True,text=True)
# print(p1.stdout)
p2 = subprocess.run(['grep','-n','test'],capture_output=True,text=True,input=p1.stdout)
print(p2.stdout)


