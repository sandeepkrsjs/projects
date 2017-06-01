import cs50

def main():
    count = 0
    while True:
        print("o hai! how much change is owed?")
        amount = cs50.get_float()
        if amount>0:
            break
    amt = round(amount*100)
    if amt//25 > 0:
        count = count + amt//25
        amt = amt - (amt//25)*25
        
    if amt//10 > 0:
        count = count + amt//10
        amt = amt - (amt//10)*10
        
    if amt//5 > 0:
        count = count + amt//5
        amt = amt - (amt//5)*5
        
    if amt//1 > 0:
        count = count + amt//1
        amt = amt - (amt//1)*1
        
    print(count)
    
if __name__ == "__main__":
    main()
        
        