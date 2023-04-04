import os, time
from datetime import datetime
from pytz import timezone
new_year = datetime.now().year + 1
vietnam_zone = "Asia/Ho_Chi_Minh"
logohpny = """
db   db  .d8b.  d8888b. d8888b. db    db   d8b   db d88888b db   d8b   db  db    db d88888b  .d8b.  d8888b.  
88   88 d8' `8b 88  `8D 88  `8D `8b  d8'   888o  88 88'     88   I8I   88  `8b  d8' 88'     d8' `8b 88  `8D 
88ooo88 88ooo88 88oodD' 88oodD'  `8bd8'    88V8o 88 88ooooo 88   I8I   88   `8bd8'  88ooooo 88ooo88 88oobY' 
88~~~88 88~~~88 88~~~   88~~~      88      88 V8o88 88~~~~~ Y8   I8I   88     88    88~~~~~ 88~~~88 88`8b  
88   88 88   88 88      88         88      88  V888 88.     `8b d8'8b d8'     88    88.     88   88 88 `88. 
YP   YP YP   YP 88      88         YP      VP   V8P Y88888P  `8b8' `8d8'      YP    Y88888P YP   YP 88   YD   
																		
"""
def count_down(tz: timezone) -> tuple:
	tz = timezone(tz)
	new_year = datetime(datetime.now(tz).year + 1, 1, 1)
	today = datetime.now(tz)
	day_diff = new_year.day - today.day
	if day_diff < 0:
		day_diff = 30 + new_year.day - today.day
		month_diff = 12 - today.month
		total_days = int(day_diff + ((month_diff / 2) * 30) + ((month_diff / 2) * 31))
		hour_diff = new_year.hour - today.hour
	if hour_diff < 0:
		hour_diff = (new_year.hour - today.hour) + 23
	minute_diff = new_year.minute - today.minute
	if minute_diff < 0:
		minute_diff = 59 + new_year.minute - today.minute
	sec_diff = new_year.second - today.second
	if sec_diff < 0:
		sec_diff = 59 + (new_year.second - today.second)
	return {
		"day": str(total_days).zfill(2),
		"hour": str(hour_diff).zfill(2),
		"min": str(minute_diff).zfill(2),
		"sec": str(sec_diff).zfill(2),
	}
os.system("cls" if os.name == "nt" else "clear")
print('Count Down New Year')
while True:
	print("\r[-] => {day} Days {hour} Hours {min} Minutes {sec} Seconds\r".format(**count_down(vietnam_zone)),end = "\r")
	time.sleep(0.25)
	print("\r[\] => {day} Days {hour} Hours {min} Minutes {sec} Seconds\r".format(**count_down(vietnam_zone)),end = "\r")
	time.sleep(0.25)
	print("\r[|] => {day} Days {hour} Hours {min} Minutes {sec} Seconds\r".format(**count_down(vietnam_zone)),end = "\r")
	time.sleep(0.25)
	print("\r[/] => {day} Days {hour} Hours {min} Minutes {sec} Seconds\r".format(**count_down(vietnam_zone)),end = "\r")
	time.sleep(0.25)
	if '{hour}' == '00':
		print(logohpny)
		exit()
