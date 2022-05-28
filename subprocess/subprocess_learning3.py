import subprocess

# trying to use the result of another process!!!!
# the same function as it is in the subprocess_learning2.py
p1 = subprocess.run('cat test.txt | grep -n test',shell=True)
p2 = subprocess.run('bash /home/greenteamsim/bridge.sh',shell=True)