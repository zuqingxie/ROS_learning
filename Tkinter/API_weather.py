from tkinter import *
from PIL import ImageTk,Image
# 用来请求天气返回的
import requests
# 用来解码发回来的json文件
import json

root = Tk()
root.title("天气获取器")
root.geometry("400x35")
root.configure(background="green")

# http://docs.airnowapi.org/


# las Vegas
# https://www.airnowapi.org/aq/observation/zipCode/current/?format=application/json&zipCode=89129&distance=5&API_KEY=01CA0E43-1D0B-42DF-A763-83CA4E34E3E0
try:
    api_rqquest = requests.get("https://www.airnowapi.org/aq/observation/zipCode/current/?format=application/json&zipCode=89129&distance=5&API_KEY=01CA0E43-1D0B-42DF-A763-83CA4E34E3E0")
    api = json.loads(api_rqquest.content)
    city = api[0]["ReportingArea"]
    quality = api[0]["AQI"]
    category = api[0]["Category"]["Name"]
    
except Exception as e:
    api = "Error......"

my_label = Label(root,text=city +  "Air Quality" + str(quality) +" "+ category,font=("Helvetica",20),background="green" ).pack()



root.mainloop() 