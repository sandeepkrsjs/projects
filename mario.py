import cs50
def main():
    while True:
        print("Height: ",end="")
        height = cs50.get_int()
        if height>0 or height<23:
            break
    for i in range(height):
        for j in range(height-i):
            print(" ",end="")
        print("#" * int(i+2),end="")
        print()
        
if __name__ == "__main__":
    main()
    