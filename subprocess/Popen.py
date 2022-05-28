from asyncio.subprocess import DEVNULL
import subprocess

cmd = "df -1h"
p1 = subprocess.Popen(cmd, shell=True,text=True,stderr=DEVNULL,stdout=DEVNULL)
p1.wait()
if p1.returncode == 0: # successfully 
    print("command success")
else:
    print("command failed")

