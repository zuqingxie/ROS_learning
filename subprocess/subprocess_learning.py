import subprocess

# subprocess.run('ls -la', shell=True) # shell = True  and then we can run as a string 

# with shell= True is recommended. cause we can use &&
subprocess.run('ls -la && ls', shell=True) # shell = True  and then we can run as a string 
p1 = subprocess.run(['ls', '-la']) # otherwise we need to seperate them as a list
print(p1)
print(p1.args)
print(p1.returncode) # 0 means 0 error
print(p1.stdout) # None 


# capture_output=True will print nothing in the terminal. it appears only if we print(p2.stdout)
# caputred is a bites we need to decode them to a readable messages
# another way is to setting text=True
p2 = subprocess.run('ls -la && ls', shell=True,capture_output=True) 
print(p2.stdout.decode())

p3 = subprocess.run('ls -la && ls', shell=True,capture_output=True,text=True) 
print(p3.stdout)

# writing into a output file
with open('output.txt','w') as f:
    p4 = subprocess.run('ls -la && ls', shell=True,stdout=f,text=True)

# Error handling
p5 = subprocess.run(['ls','-la','dna'],capture_output=True,text=True)
print(p5.returncode)
print(p5.stderr)
if p5.returncode != 0 :
    pass

# check= True to throw the error immediatly and stop without continuing 
# p6 = subprocess.run(['ls','-la','dna'],capture_output=True,text=True,check=True)

# but we still can ignore all the error
p7 = subprocess.run(['ls','-la','dna'],stderr=subprocess.DEVNULL)
