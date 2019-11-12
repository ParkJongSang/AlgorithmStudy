tmp_str = input()
tmp_list = tmp_str.split(' ')

hour = int(tmp_list[0])
minute = int(tmp_list[1])
second = int(tmp_list[2])

input_sec = int(input())

to_add_hour = int(input_sec / 3600)
input_sec %= 3600

to_add_min = int(input_sec / 60)
input_sec %= 60

to_add_sec = int(input_sec)

hour += to_add_hour
minute += to_add_min
second += to_add_sec

if second >= 60 : 
    second %= 60
    minute += 1

if minute >= 60 :
    minute %= 60
    hour += 1

if hour >= 24 :
    hour %= 24

result = str(hour) + " " + str(minute) + " " + str(second)

print(result)